#include <stdio.h>
#include <setjmp.h>
#include <errno.h>
#include "trex.h"

typedef unsigned long DWORD;
typedef short WORD;
typedef unsigned char BYTE;
#define TRUE 1
#define FALSE 0
enum VARTYPES{
	INT=1,
	FLOAT,
};
typedef struct{
	char name[40];
	int type;
	int stat;
	int val;
	float f;
}VAR;

typedef struct{
	char name[40];
	int argc;
	char args[40];
}FUNC;
typedef struct{
	char *data;
	int len;
	int offset;
}CODE;

int PROGRAM_MEM[0x100000];
int STACK[100];
VAR vars[1000];
FUNC *current_func=0;

enum OPCODES{
	JUMP=0,
	CALL,
	RET,
	ADD,
	SUB,
	MUL,
	DIV,
	CMP,
	BEQ,
	BNE,
	STOP,
	WHILE_BEGIN,
	LOAD_ARG1,
	LOAD_ARG2,
	LOAD_ARG3,
	LOAD_ARG4,

};
enum CMPOPS{
	AND=0,
	NOT,
	LT,
	GT,
	LE,
	GE,
};
typedef struct{
   long  value;
   WORD  type;
   }TOKEN;

typedef struct{
   BYTE  op[ 3 ];
   long  (*Operation)( long, long );
   WORD  token;
   }OPERATOR;
BYTE
  *error[]={ "",
             "Syntax error",
             "Internal error",
             "Invalid operand",
             "Invalid operator",
             "Divide by zero",
             "Missing open paren",
             "Missing close paren",
             "Big number",
             "Long string number",
            },
 *ExpErrPoint;
TOKEN token;
jmp_buf jmp;

enum{
   EXP_OK = 0,
   EXP_ERR_SYNTAX,
   EXP_ERR_INTERNAL1,
   EXP_ERR_INVALIDOPERAND,
   EXP_ERR_INVALIDOPERATOR,
   EXP_ERR_ZERODIVIDE,
   EXP_ERR_NOPARENOPEN,
   EXP_ERR_NOPARENCLOSE,
   EXP_ERR_BIGNUMBER,
   EXP_ERR_INVALIDSTRINGNUMBER,
   };
#define  NOT_USED                   0L
#define  UNARY_YES                  1
#define  UNARY_NO                   0

#define  EXP_END                    0
#define  EXP_PLUS                   1
#define  EXP_MINUS                  2
#define  EXP_VALID                  8
#define  EXP_NUMBER                 0x0008
#define  EXP_LOGICOR                0x0010
#define  EXP_LOGICAND               0x0020
#define  EXP_BITOR                  0x0040
#define  EXP_BITXOR                 0x0080
#define  EXP_BITAND                 0x0100
#define  EXP_EQUAL                  0x0200
#define  EXP_EQUAL_EQUAL            EXP_EQUAL
#define  EXP_EQUAL_NOTEQUAL         EXP_EQUAL+1
#define  EXP_RELATION               0x0400
#define  EXP_RELATION_LESS          EXP_RELATION
#define  EXP_RELATION_GREAT         EXP_RELATION+1
#define  EXP_RELATION_LESSEQ        EXP_RELATION+2
#define  EXP_RELATION_GREATEQ       EXP_RELATION+3
#define  EXP_ADDITIVE               0x0800
#define  EXP_ADDITIVE_PLUS          EXP_ADDITIVE+EXP_PLUS
#define  EXP_ADDITIVE_MINUS         EXP_ADDITIVE+EXP_MINUS
#define  EXP_MULTI                  0x1000
#define  EXP_MULTI_MUL              EXP_MULTI
#define  EXP_MULTI_DIV              EXP_MULTI+1
#define  EXP_MULTI_MODULUS          EXP_MULTI+2
#define  EXP_PAREN                  0x2000
#define  EXP_PAREN_R                EXP_PAREN
#define  EXP_PAREN_L                EXP_PAREN+1
#define  EXP_UNARY                  0x4000
#define  EXP_UNARY_PLUS             EXP_UNARY+EXP_PLUS
#define  EXP_UNARY_MINUS            EXP_UNARY+EXP_MINUS
#define  EXP_UNARY_NEG              EXP_UNARY+3
#define  EXP_UNARY_NOT              EXP_UNARY+4
#define  EXP_SHIFT                  0x8000
#define  EXP_SHIFT_R                EXP_SHIFT
#define  EXP_SHIFT_L                EXP_SHIFT+1

long      OpError( long a, long b ){ report_error( EXP_ERR_INTERNAL1 ); return( 0 ); };
long        OpAdd( long a, long b ){ return( a + b ); };
long        OpSub( long a, long b ){ return( a - b ); };
long      OpMulti( long a, long b ){ return( a * b ); };
long        OpDiv( long a, long b ){ if( b ) return( a / b ); else report_error( EXP_ERR_ZERODIVIDE ); };
long  OpShiftLeft( long a, long b ){ return( (DWORD)a << b ); };
long OpShiftRight( long a, long b ){ return( (DWORD)a >> b ); };
long    OpModulus( long a, long b ){ if( b ) return( a % b ); else report_error( EXP_ERR_ZERODIVIDE ); };
long       OpLess( long a, long b ){ return( a < b ); };
long      OpGreat( long a, long b ){ return( a > b ); };
long     OpBitAnd( long a, long b ){ return( a & b ); };
long     OpBitXor( long a, long b ){ return( a ^ b ); };
long      OpBitOr( long a, long b ){ return( a | b ); };
long     OpLessEq( long a, long b ){ return( a <= b ); };
long    OpGreatEq( long a, long b ){ return( a >= b ); };
long      OpEqual( long a, long b ){ return( a == b ); };
long   OpNotEqual( long a, long b ){ return( a != b ); };
long   OpLocicAnd( long a, long b ){ return( a && b ); };
long    OpLogicOr( long a, long b ){ return( a || b ); };
long     OpBitNot( long a, long b ){ return( ~a ); };
long   OpLogicNot( long a, long b ){ return( !a ); };
long OpUnaryMinus( long a, long b ){ return( -a ); };
long  OpUnaryPlus( long a, long b ){ return( a ); };

OPERATOR
 operator[]={ { "",   OpError,      EXP_END },
                                          // single character FIRST !
              { ")",  OpError,      EXP_PAREN_R },
              { "(",  OpError,      EXP_PAREN_L },
              { "!",  OpLogicNot,   EXP_UNARY_NOT },
              { "~",  OpBitNot,     EXP_UNARY_NEG },
              { "+",  OpUnaryPlus,  EXP_UNARY_PLUS },      // unary operation
              { "+",  OpAdd,        EXP_ADDITIVE_PLUS },    // binary operation
              { "+",  OpError,      EXP_PLUS },              // token
              { "-",  OpUnaryMinus, EXP_UNARY_MINUS },     // unary operation
              { "-",  OpSub,        EXP_ADDITIVE_MINUS },   // binary operation
              { "-",  OpError,      EXP_MINUS },             // token
              { "*",  OpMulti,      EXP_MULTI_MUL },
              { "/",  OpDiv,        EXP_MULTI_DIV },
              { "%",  OpModulus,    EXP_MULTI_MODULUS },
              { "<",  OpLess,       EXP_RELATION_LESS },
              { ">",  OpGreat,      EXP_RELATION_GREAT },
              { "&",  OpBitAnd,     EXP_BITAND },
              { "^",  OpBitXor,     EXP_BITXOR },
              { "|",  OpBitOr,      EXP_BITOR },
                                          // double characters
              { "<<", OpShiftLeft,  EXP_SHIFT_L },
              { ">>", OpShiftRight, EXP_SHIFT_R },
              { "<=", OpLessEq,     EXP_RELATION_LESSEQ },
              { ">=", OpGreatEq,    EXP_RELATION_GREATEQ },
              { "==", OpEqual,      EXP_EQUAL_EQUAL },
              { "!=", OpNotEqual,   EXP_EQUAL_NOTEQUAL },
              { "&&", OpLocicAnd,   EXP_LOGICAND },
              { "||", OpLogicOr,    EXP_LOGICOR } };

////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

int
 TokenIndex( BYTE *p )
{
 int
   i=sizeof( operator )/sizeof( OPERATOR );

 while( --i > 0 && memcmp( operator[ i ].op, p, strlen( operator[ i ].op ) ) )
   ;
 return( i );
}

////////////////////////////////////////////////////////////

int
 OperatorIndex( WORD type )
{
 int
   i=sizeof( operator )/sizeof( OPERATOR );

 while( --i > 0 && operator[ i ].token != type )
   ;
 return( i );
}

////////////////////////////////////////////////////////////

BYTE
 *SkipSpace( BYTE *p )
{
 while( isspace( *p ) )
   p++;
 return( p );
}

BYTE
 *Str2Dword( BYTE *s, long *a )
{
 *a=0L;
 while( s && *++s && *s != '"' ){
   if( *a & 0xFF000000L )
     s=NULL;
    else
     *a=( *a << 8 ) | ( ( *s == '\\' )? *++s : *s );
 }
 if( s && *s++ != '"' )
   s=NULL;
 return( s );
}
////////////////////////////////////////////////////////////

BYTE
 Text2DwordLastChar( BYTE *s )
{
 if( *s == '-' || *s == '+' )
   s++;
 while( isxdigit( *s ) )
   s++;
 return( *s );
}
////////////////////////////////////////////////////////////

BYTE
 *Text2Dword( BYTE *s, DWORD *val, int base )
{
 BYTE
   suffix;
 int
   prefix=0;

 if( *s ){
   if( *s == '"' )
     s=Str2Dword( s, val );
    else{
     if( base ){
       if( ( *(WORD*)s | 0x2020 ) == 0x7830 ){
         prefix=2;
         base=16;
       }
       switch( suffix=Text2DwordLastChar( s+prefix ) ){
         case 'i': case 'I': base=2;  break;
         case 'o': case 'O': base=8;  break;
         case 't': case 'T': base=10; break;
         case 'h': case 'H': base=16; break;
         default:  suffix=0;
       }
     }
     errno=0;
     *val=strtoul( s+prefix, &s, base );
     if( errno == ERANGE )
       longjmp( jmp, EXP_ERR_BIGNUMBER );
     if( suffix && *s == suffix )
       s++;
   }
 }else
   *val=0L;
 return( s );
}

////////////////////////////////////////////////////////////
BYTE *Expression( BYTE *p );

BYTE
 *ExpToken( BYTE *p, short unary_flag )
{
 short
   index;

 ExpErrPoint=p=SkipSpace( p );
 if( *p ){
   if( isxdigit( *p ) || *p == '"' ){
     p=Text2Dword( p, &token.value, 10 );
     if( p == NULL )
       longjmp( jmp, EXP_ERR_INVALIDSTRINGNUMBER );
     token.type=EXP_NUMBER;
   }else{
     if( index=TokenIndex( p ) ){
       token.type=operator[ index ].token;
       p+=strlen( operator[ index ].op );
       if( token.type < EXP_VALID )
         token.type+=unary_flag? EXP_UNARY : EXP_ADDITIVE;
     }
	 else if(!is_variable(p,&token))
       longjmp( jmp, EXP_ERR_INVALIDOPERATOR );
   }
 }else
   token.type=EXP_END;
 return( p );
}

BYTE
 *ExpValue( BYTE *p )
{
 TOKEN
   tokenOld;

 p=ExpToken( p, UNARY_YES );
 memcpy( &tokenOld, &token, sizeof( TOKEN ) );
 if( tokenOld.type & EXP_UNARY ){
   p=ExpValue( p );
   if( token.type & EXP_NUMBER )
     token.value=operator[ OperatorIndex( tokenOld.type ) ].Operation( token.value, NOT_USED );
    else
     longjmp( jmp, EXP_ERR_INVALIDOPERAND );
 }else{
   if( token.type == EXP_PAREN_L ){
     p=Expression( p );
     if( ( token.type == EXP_PAREN_R ) == 0 )
       longjmp( jmp, EXP_ERR_NOPARENCLOSE );
      else
       token.type=EXP_NUMBER;
   }
 }
 return( p );
}

////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////

BYTE
 *ExpOperand( BYTE *p )
{
 p=ExpValue( p );
 if( token.type != EXP_NUMBER )
   longjmp( jmp, EXP_ERR_SYNTAX );
 p=ExpToken( p, UNARY_NO );
 if( token.type == EXP_NUMBER )
   longjmp( jmp, EXP_ERR_SYNTAX );
 return( p );
}

////////////////////////////////////////////////////////////

BYTE
 *Exp( BYTE *p, BYTE* (*NextLevel)( BYTE* ), WORD type )
{
 TOKEN
   tokenOld;

 p=NextLevel( p );
 while( token.type & type ){
   memcpy( &tokenOld, &token, sizeof( TOKEN ) );
   p=NextLevel( p );
   token.value=operator[ OperatorIndex( tokenOld.type ) ].Operation( tokenOld.value, token.value );
 }
 return( p );
}


////////////////////////////////////////////////////////////
BYTE    *ExpMulti( BYTE *p ){ return( Exp( p, ExpOperand,  EXP_MULTI ) ); }
BYTE   *ExpAdding( BYTE *p ){ return( Exp( p, ExpMulti,    EXP_ADDITIVE ) ); }
BYTE    *ExpShift( BYTE *p ){ return( Exp( p, ExpAdding,   EXP_SHIFT ) ); }
BYTE    *ExpRelat( BYTE *p ){ return( Exp( p, ExpShift,    EXP_RELATION ) ); }
BYTE    *ExpEqual( BYTE *p ){ return( Exp( p, ExpRelat,    EXP_EQUAL ) ); }
BYTE   *ExpBitAnd( BYTE *p ){ return( Exp( p, ExpEqual,    EXP_BITAND ) ); }
BYTE   *ExpBitXor( BYTE *p ){ return( Exp( p, ExpBitAnd,   EXP_BITXOR ) ); }
BYTE    *ExpBitOr( BYTE *p ){ return( Exp( p, ExpBitXor,   EXP_BITOR ) ); }
BYTE *ExpLogicAnd( BYTE *p ){ return( Exp( p, ExpBitOr,    EXP_LOGICAND ) ); }
BYTE  *ExpLogicOr( BYTE *p ){ return( Exp( p, ExpLogicAnd, EXP_LOGICOR ) ); }
////////////////////////////////////////////////////////////
BYTE
 *Expression( BYTE *p )
{
 return( ExpLogicOr( p ) );            // start at lower priority
}
////////////////////////////////////////////////////////////
int is_variable(BYTE *p,TOKEN *token)
{
	int i;
	char name[40];
	int found=FALSE;
	CODE c;
	c.data=p;
	c.len=strlen(p);
	c.offset=0;
	if(get_next_token(&c,name,sizeof(name))){
		char s[80];
		_snprintf(s,sizeof(s),"%s.%s",current_func->name,name);
		for(i=0;i<sizeof(vars)/sizeof(VAR);i++){
			if(vars[i].type==0)
				break;
			if(strcmp(vars[i].name,s)==0){
				found=TRUE;
				break;
			}
		}
		if(found){
			printf("found match %s\n",s);
			token->type=EXP_NUMBER;
			token->value=0;
		}
		else{
			if(strstr(current_func->args,name)){
				token->type=EXP_NUMBER;
				token->value=0;
				printf("found in args\n");
				found=TRUE;
			}
		}
	}
	else
		printf("cant get variable name\n");
	return found;
}

////////////////////////////////////////////////////////////
int report_error(int e)
{
	printf("%s\n",error[e]);
}

int get_char(CODE *c,char *a)
{
	if(c->offset>=c->len)
		return FALSE;
	*a=c->data[c->offset++];
	return TRUE;
}

int seek_nonwhitespace(CODE *c)
{
	char a;
	int found=FALSE;
	while(get_char(c,&a)){
		if(is_whitespace(a))continue;
		else{found=TRUE;c->offset--;break;}
	}
	return found;
}
int seek_to_char(CODE *c,char b)
{
	int i;
	int found=FALSE;
	char a;
	do{
		if(get_char(c,&a)){
			if(a==b){
				found==TRUE;
				break;
			}
		}
		else{
			printf("EOF\n");
			break;
		}
	}while(TRUE);
	return found;
}
int seek_to_str(CODE *c,char *str)
{
	int found=FALSE;
	int index=0;
	int len=strlen(str);
	char a;
	while(get_char(c,&a)){
		if(a==str[index])
			index++;
		else
			index=0;
		if(index>=len){
			found=TRUE;
			break;
		}
	}
	return found;
}
int seek_endcomment(CODE *c)
{
	int i;
	int found=FALSE;
	for(i=c->offset;i<c->len;i++){/**/
		if(c->data[i]=='*' && c->data[i+1]=='/'){found=TRUE;i+=2;break;}
	}
	c->offset=i;
	return found;
}
int seek_end_statement(CODE *c)
{
	int i;
	char a;
	for(i=c->offset;i<c->len;i++){
		a=c->data[i];
		if(is_whitespace(a))continue;
		if(a==';'){c->offset=i+1;return TRUE;}
		break;
	}
	c->offset=i;
	return FALSE;
}
int handle_comment(CODE *c,char a)
{
	int found=FALSE;
	if(c->offset<c->len-1){
		if(a=='/' && c->data[c->offset]=='/'){
			found=TRUE;
			seek_to_char(c,'\n');
		}
		else if(a=='/' && c->data[c->offset]=='*'){
			if(seek_to_str(c,"*/"))
				found=TRUE;
		}
	}
	return found;
}
int is_whitespace(char c)
{
	if(c==' ' || c=='\t' || c=='\r' || c=='\n')return TRUE;
	return FALSE;
}
int is_valid_token_start(char c)
{
	if(c>='A' && c<='Z')return TRUE;
	if(c>='a' && c<='z')return TRUE;
	if(c=='_')return TRUE;
	return FALSE;
}
int is_valid_token_char(char c)
{
	if(c>='0' && c<='9')return TRUE;
	if(c>='A' && c<='Z')return TRUE;
	if(c>='a' && c<='z')return TRUE;
	if(c=='_')return TRUE;
	return FALSE;
}
int is_variable_type(char *t)
{
	if(strstr(t,"int"))
		return TRUE;
	if(strstr(t,"float"))
		return TRUE;
	return FALSE;
}
int is_conditional(char *t)
{
	if(strstr(t,"if"))
		return TRUE;
	if(strstr(t,"else"))
		return TRUE;
	if(strstr(t,"while"))
		return TRUE;
	return FALSE;
}
int is_keyword(char *t)
{
	if(strstr(t,"int"))
		return 1;
	if(strstr(t,"float"))
		return 1;
	if(strstr(t,"static"))
		return 2; //2 parts
	if(strstr(t,"return"))
		return 1;
	if(strstr(t,"if"))
		return 1;
	if(strstr(t,"else"))
		return 1;
	if(strstr(t,"while"))
		return 1;
	return 0;
}
int get_next_token(CODE *c,char *token,int len)
{
	int i,index=0;
	int found=FALSE;
	int tstart=FALSE;
	char a;
	do{
		if(get_char(c,&a)){
			if(tstart){
				if(is_whitespace(a)){
					found=TRUE;
					token[index++]=0;
					break;
				}
				else if(is_valid_token_char(a))
					token[index++]=a;
				else if(a=='(' || a==')' || a=='{' || a=='}'){
					found=TRUE;
					c->offset--;
					token[index++]=0;
					break;
				}
				else{ //could be comment or garbage
					found=TRUE;
					c->offset--;
					token[index++]=0;
					break;
				}
				if(index>=len){
					found=FALSE;
					printf("token too long\n");
					break;
				}
			}
			else if(is_valid_token_start(a)){
				token[index++]=a;
				tstart=TRUE;continue;
			}
			else if(is_whitespace(a))
				continue;
			else if(handle_comment(c,a))
				continue;
			else{ //illegal token start
				c->offset--;
				return FALSE;
			}
		}
		else
			printf("EOF getting token\n");

	}while(TRUE);
	return found;
}
int check_assignment(CODE *c,int type,int *val,float *f)
{
	int i;
	char a;
	int eq_found=FALSE;
	while(get_char(c,&a)){
		if(is_whitespace(a))
			continue;
		if(a=='='){
			eq_found=TRUE;break;}
		if(a==','){*val=0;*f=0;c->offset--;return TRUE;}
		if(a==';'){*val=0;*f=0;c->offset--;return TRUE;}
		printf("assignment error\n");
		return FALSE;
	}
	if(eq_found){
		char str[40];
		int index=0;
		int number_found=FALSE;
		int point_found=FALSE;
		while(get_char(c,&a)){
			if(number_found){
				if(a>='0' && a<='9')
					str[index++]=a;
				else if(a=='.'){
					if(!(type==FLOAT)){
						number_found=FALSE;break;}
					if(point_found){
						number_found=FALSE;break;}
					str[index++]=a;
					point_found=TRUE;
				}
				else if(is_whitespace(a) || a==';'){
					c->offset--;str[index++]=0;break;}
				else if(a==','){
					c->offset--;break;}
				else{number_found=FALSE;break;}
				if(index>=sizeof(str)-1){number_found=FALSE;break;}

			}
			else if(is_whitespace(a))continue;
			else if(a>='0' && a<='9'){
				str[index++]=a;number_found=TRUE;
			}
			else 
				break;		
		}
		if(number_found){
			if(type==FLOAT){
				if(sscanf(str,"%f",f)!=1)number_found=FALSE;
			}
			else 
				*val=strtol(str,0,0);
			if(number_found)
				return TRUE;
		}
	}
	return FALSE;
}
int handle_variable(CODE *c,char *token,FUNC *func,int stat)
{
	char a;
	char name[40];
nextvar:
	if(is_variable_type(token)){
		int type,val=0;
		float f=0;
		if(strstr(token,"int"))type=INT;
		else type=FLOAT;
		if(get_next_token(c,name,sizeof(name))){
			if(check_assignment(c,type,&val,&f)){
				if(!add_var(func,name,type,stat,val,f))
					return FALSE;
			}
		}
		while(get_char(c,&a)){
			if(is_whitespace(a))continue;
			if(a==',') goto nextvar;
			if(a==';')return TRUE;
			break;
		}

	}
	return FALSE;
}
int get_conditional_args(CODE *c,char *args,int len)
{
	char a;
	int found=FALSE;
	int lparen=0;
	int index=0;
	while(get_char(c,&a)){
		if(is_whitespace(a))
			continue;
		args[index++]=a;
		if(index>=len-1){
			printf("length error %i",__LINE__);
			found=FALSE;
			break;
		}
		if(found){
			if(a=='('){
				lparen++;
			}
			else if(a==')'){
				lparen--;
			}
			if(lparen==0)
				break;
		}
		if(a=='('){
			found=TRUE;
			lparen++;
		}
	}
	args[index++]=0;
	return found;
}
int get_func_args(CODE *c,FUNC *func)
{
	char a;
	int found=FALSE;
	int lparen=0;
	int index=0;
	func->argc=0;
	while(get_char(c,&a)){
		if(is_whitespace(a))
			continue;
		if(!is_valid_token_char(a))
			if(a!=',' && a!=')' && a!='(')
				return FALSE;
		if(found){
			if(a==',')
				func->argc++;
			if(a=='(')
				lparen++;
			if(a==')')
				lparen--;
			if(lparen<0)
				return FALSE;
			func->args[index++]=a;
			if(lparen==0){
				func->argc++;
				break;
			}
			if(index>=sizeof(func->args)-1){
				printf("args too long\n");
				return FALSE;
			}
		}
		if(a=='('){
			found=TRUE;
			lparen++;
			func->args[index++]=a;
		}
	}
	if(found)
		func->args[index++]=0;
	return found;
}
int handle_conditional(CODE *c,char *token)
{
	char args[80];
	int result=FALSE;
	int rc;
	if(get_conditional_args(c,args,sizeof(args))){
		rc=setjmp(jmp);
		if(rc==EXP_OK){
			Expression(args);
		}
		else{
			printf("%s\n",error[rc]);
		}
	}
	return result;
}
int parse_function(CODE *c,FUNC *func)
{
	char a;
	char token[40];
	char token2[40];
	while(get_char(c,&a)){
		if(is_whitespace(a))
			continue;
		if(a=='{')
			break;
		else
			return FALSE;
	}
	do{
		current_func=func;
		if(get_next_token(c,token,sizeof(token))){
			int i;
			i=is_keyword(token);
			if(i==2 && strstr(token,"static")){
				if(get_next_token(c,token2,sizeof(token2))){
					if(is_variable_type(token2) && !handle_variable(c,token2,func,TRUE))
						printf("error\n");
				}
			}
			else if(i==1 && is_variable_type(token)){
				if(!handle_variable(c,token2,func,FALSE))
					printf("error\n");
			}
			else if(i==1 && (strstr(token,"if")||strstr(token,"while")) ){ //possible conditional
				printf("conditional %s\n",token);
				handle_conditional(c,token);
			}
			else{ //assignment check for variable
				printf("assignment %s\n",token);
			}
		}
		else{ //check if its end
			get_char(c,&a);
			if(a=='}')
				break;//handle func cleanup
			else{
				printf("bad char\n");
				break;
			}
		}
	}while(TRUE);
}
int add_var(FUNC *func,char *token,int type,int stat,int val,float f)
{
	int i;
	for(i=0;i<sizeof(vars)/sizeof(VAR);i++){
		if(vars[i].type==0){
			vars[i].type=type;
			vars[i].stat=stat;
			_snprintf(vars[i].name,sizeof(vars[i].name),"%s.%s",func->name,token);
			if(type==FLOAT)
				vars[i].f=f;
			else
				vars[i].val=val;
			break;
		}
	}
	printf("added var %s val=%u type=%i static=%i\n",vars[i].name,vars[i].val,vars[i].type,vars[i].stat);
	return TRUE;
}
int find_func_or_var(CODE *c,int *bcode,int addr)
{
	char token[40],token2[40];
	FUNC func;
	int i;
	memset(&func,0,sizeof(func));
	while(get_next_token(c,token,sizeof(token))){
		i=is_keyword(token);
		if(i==2 && strstr(token,"static")){
			if(get_next_token(c,token2,sizeof(token2))){
				if(is_variable_type(token2) && !handle_variable(c,token2,&func,TRUE))
					printf("error\n");
			}
		}
		else if(i==1 && is_variable_type(token)){
			if(!handle_variable(c,token2,&func,FALSE))
				printf("error\n");
		}
		else if(i==1){
			printf("invalid function name\n");
		}
		else{ //start of function
			strncpy(func.name,token,sizeof(func.name));
			if(get_func_args(c,&func)){
				if(parse_function(c,&func)){
				}
			}
		}
	}
}
int test(CODE *c,FILE *f)
{
	int i;
	const char *begin,*end;
	const char *error = NULL;
extern FILE *yyin;
extern char *yytext;
	yyin=f;
	while(yyparse()!=0){
		printf("%u=[%s]\n",i,yytext);
	}
	printf("done\n");
	getch();
	return;
	while((i=yylex())!=0){
		printf("%u=[%s]\n",i,yytext);
	}
	printf("done\n");
	getch();

}
int compile_text(char *code,int len)
{
	int offset=0;
	int addr=0;
	FILE *f;
	memset(PROGRAM_MEM,0,sizeof(PROGRAM_MEM));
	memset(vars,0,sizeof(vars));
	f=fopen(".\\scripts\\test.ac","rt");
	if(f!=0){
		int len;
		BYTE *buf;
		CODE c;
		fseek(f,0,SEEK_END);
		len=ftell(f);
		fseek(f,0,SEEK_SET);
		buf=malloc(0x100000);
		memset(buf,0,0x100000);
		if(buf!=0){
//			fread(buf,1,len,f);
//			fclose(f);
//			f=0;
			fseek(f,0,SEEK_SET);
			c.data=buf;
			c.len=len;
			c.offset=0;
			test(&c,f);
			//find_func_or_var(&c,PROGRAM_MEM,0);
		}
		if(f!=0)
			fclose(f);
	}
}