#include <stdio.h>
typedef unsigned char BYTE;
typedef unsigned int _DWORD;
#define TRUE 1
#define FALSE 0
FILE *yyin = (FILE *) 0, *yyout = (FILE *) 0;
char *yytext;


static const short int yy_accept[]={
    0,    0,    0,   71,   69,   68,   68,   56,
   62,   55,   69,   50,   51,   60,   59,   47,
   58,   54,   61,   22,   22,   48,   44,   63,
   49,   64,   67,   19,   52,   53,   65,   19,
   19,   19,   19,   19,   19,   19,   19,   19,
   19,   19,   45,   66,   46,   57,   43,   30,
   38,   31,    0,   23,   28,   36,   26,   37,
   27,    1,    0,   29,   21,    0,   22,   35,
   40,   42,   41,   34,   19,   32,   19,   19,
   19,   19,   19,    8,   19,   19,   19,   19,
   13,   19,   19,   19,   19,   19,   33,   39,
    0,    2,   20,   25,   24,   19,   19,   19,
   19,   19,   19,   19,   11,   19,   14,   19,
   19,   19,   19,    3,   19,    5,   19,   19,
    9,   19,   12,   19,   19,   19,   19,    4,
   19,   19,   19,   19,   19,   19,   18,   19,
   19,   10,   15,   16,   17,   19,    7,    6,
    0,    0,    0,    0}; //count=140

static const int yy_ec[]={
    0,    1,    1,    1,    1,    1,    1,    1,
    1,    2,    3,    2,    2,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    2,    4,    1,    1,    1,    5,    6,    7,
    8,    9,   10,   11,   12,   13,   14,   15,
   16,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   18,   19,   20,   21,   22,   23,
    1,   24,   24,   24,   24,   24,   24,   25,
   25,   25,   25,   25,   25,   25,   25,   25,
   25,   25,   25,   25,   25,   25,   25,   25,
   26,   25,   25,   27,    1,   28,   29,   25,
    1,   30,   31,   32,   33,   34,   35,   36,
   37,   38,   25,   39,   40,   25,   41,   42,
   25,   25,   43,   44,   45,   46,   25,   47,
   48,   25,   25,   49,   50,   51,   52,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1
}; //count=256

static const int yy_meta[]={
    0,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    2,    2,    1,    1,    1,    1,    1,    1,
    2,    3,    3,    1,    1,    1,    2,    2,
    2,    2,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    1,    1,    1,    0}; //count=54

static const short int yy_base[]={
    0,    0,    0,  157,  158,  158,  158,  135,
  134,   47,  147,  158,  158,  132,   43,  158,
   42,  158,   46,   43,   41,  158,  158,   45,
  131,   49,  158,    0,  158,  158,  130,  104,
  106,   32,   38,   33,  106,  105,   41,  112,
   30,  108,  158,   57,  158,  158,  158,  158,
  158,  158,  137,  158,  158,  158,  158,  158,
  158,  158,  140,  158,   67,    0,   69,  121,
  158,  158,  158,  120,    0,  158,   95,  105,
   94,   96,  101,    0,   91,   89,   90,   87,
    0,   86,   85,   99,   90,   89,  158,  158,
  123,  158,    0,  158,  158,   83,   94,   89,
   77,   91,   86,   85,    0,   76,    0,   71,
   71,   61,   65,    0,   65,    0,   65,   56,
    0,   58,    0,   57,   61,   66,   63,    0,
   55,   55,   53,   52,   60,   53,    0,   43,
   43,    0,    0,    0,    0,   53,    0,    0,
  158,  107,  109,  112,   77,    0,    0,    0
}; //count=144

static const short int yy_def[]={
    0,  136,    1,  136,  136,  136,  136,  136,
  136,  136,  137,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  138,  136,  136,  136,  138,
  138,  138,  138,  138,  138,  138,  138,  138,
  138,  138,  136,  136,  136,  136,  136,  136,
  136,  136,  137,  136,  136,  136,  136,  136,
  136,  136,  139,  136,  136,  140,  136,  136,
  136,  136,  136,  136,  138,  136,  138,  138,
  138,  138,  138,  138,  138,  138,  138,  138,
  138,  138,  138,  138,  138,  138,  136,  136,
  139,  136,  140,  136,  136,  138,  138,  138,
  138,  138,  138,  138,  138,  138,  138,  138,
  138,  138,  138,  138,  138,  138,  138,  138,
  138,  138,  138,  138,  138,  138,  138,  138,
  138,  138,  138,  138,  138,  138,  138,  138,
  138,  138,  138,  138,  138,  138,  138,  138,
    0,  136,  136,  136,  136,    0,    0,    0
}; //count=144

static const short int yy_nxt[]={
    0,    4,    5,    6,    7,    8,    9,   10,
   11,   12,   13,   14,   15,   16,   17,   18,
   19,   20,   21,   22,   23,   24,   25,   26,
   27,   27,   27,   28,   29,   30,   31,   32,
   33,   34,   35,   36,   37,   27,   38,   27,
   27,   27,   27,   39,   40,   27,   27,   41,
   27,   42,   43,   44,   45,   48,   53,   55,
   57,   62,   62,   60,   60,   58,   72,   56,
   54,   63,   64,   59,   49,   61,   66,   67,
   74,   76,   73,   83,   80,   84,   86,   90,
   75,   77,   81,   60,   60,   62,   62,  135,
  134,  133,  132,   61,  131,  130,  129,  128,
  127,  126,  125,  124,  123,  122,  121,  120,
  119,  118,  117,   87,   50,   50,   50,   68,
   68,   88,   88,   88,  116,  115,  114,  113,
  112,  111,  110,  109,  108,  107,   89,  106,
  105,  104,  103,  102,  101,  100,   99,   98,
   97,   96,   95,   94,   93,   92,   91,   89,
   51,   85,   82,   79,   78,   71,   70,   69,
   65,   52,   51,   47,   46,  136,    3,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,    0}; //count=212

static const short int yy_chk[]={
    0,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    9,   14,   16,
   18,   20,   20,   19,   19,   18,   33,   16,
   14,   23,   23,   18,    9,   19,   25,   25,
   34,   35,   33,   40,   38,   40,   43,  140,
   34,   35,   38,   60,   60,   62,   62,  133,
  128,  127,  125,   19,  124,  123,  122,  121,
  120,  118,  117,  116,  115,  113,  111,  110,
  108,  106,  105,   43,  137,  137,  137,  138,
  138,  139,  139,  139,  104,  103,  101,   99,
   98,   97,   96,   95,   94,   93,   88,   85,
   84,   83,   82,   81,   79,   78,   77,   76,
   74,   73,   72,   71,   70,   67,   63,   58,
   50,   41,   39,   37,   36,   32,   31,   30,
   24,   13,   10,    8,    7,    3,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,  136,  136,  136,  136,  136,
  136,  136,  136,    0}; //count=212




static char yy_hold_char;
static int yy_n_chars;		/* number of characters read into yy_ch_buf */
int yyleng;
/* Points to current character in buffer. */
static char *yy_c_buf_p = (char *) 0;
static int yy_init = 1;		/* whether we need to initialize */
static int yy_start = 0;	/* start state number */
/* Flag which is used to allow yywrap()'s to do buffer switches
 * instead of setting up a fresh yyin.  A bit of a hack ...
 */
static int yy_did_buffer_switch_on_eof;
struct yy_buffer_state
	{
	FILE *yy_input_file;
	char *yy_ch_buf;		/* input buffer */
	char *yy_buf_pos;		/* current position in input buffer */

	/* Size of input buffer in bytes, not including room for EOB
	 * characters.
	 */
	unsigned int yy_buf_size;

	/* Number of characters read into yy_ch_buf, not including EOB
	 * characters.
	 */
	int yy_n_chars;

	/* Whether we "own" the buffer - i.e., we know we created it,
	 * and can realloc() it to grow it, and should free() it to
	 * delete it.
	 */
	int yy_is_our_buffer;

	/* Whether this is an "interactive" input source; if so, and
	 * if we're using stdio for input, then we want to use getc()
	 * instead of fread(), to make sure we stop fetching input after
	 * each newline.
	 */
	int yy_is_interactive;

	/* Whether we're considered to be at the beginning of a line.
	 * If so, '^' rules will be active on the next match, otherwise
	 * not.
	 */
	int yy_at_bol;

	/* Whether to try to fill the input buffer when we reach the
	 * end of it.
	 */
	int yy_fill_buffer;

	int yy_buffer_status;
#define YY_BUFFER_NEW 0
#define YY_BUFFER_NORMAL 1
	/* When an EOF's been seen but there's still some text to process
	 * then we mark the buffer as YY_EOF_PENDING, to indicate that we
	 * shouldn't try reading from the input source any more.  We might
	 * still have a bunch of tokens to match, though, because of
	 * possible backing-up.
	 *
	 * When we actually see the EOF, we change the status to "new"
	 * (via yyrestart()), so that the user can continue scanning by
	 * just pointing yyin at a new input file.
	 */
#define YY_BUFFER_EOF_PENDING 2
	};
typedef struct yy_buffer_state *YY_BUFFER_STATE;
static YY_BUFFER_STATE yy_current_buffer = 0;

static int yy_last_accepting_state;
static char *yy_last_accepting_cpos;
#define LOBYTE(var) (var) 
int keyword_pointer=0;

static void yy_fatal_error( const char msg[] )
{
	(void) fprintf( stderr, "%s\n", msg );
	exit( 1 );
}
void yy_load_buffer_state( void )
{
	yy_n_chars = yy_current_buffer->yy_n_chars;
	yytext = yy_c_buf_p = yy_current_buffer->yy_buf_pos;
	yyin = yy_current_buffer->yy_input_file;
	yy_hold_char = *yy_c_buf_p;
}

void yy_flush_buffer( YY_BUFFER_STATE b )
{
	if ( ! b )
		return;
	b->yy_n_chars = 0;
	/* We always need two end-of-buffer characters.  The first causes
	* a transition to the end-of-buffer state.  The second causes
	* a jam in that state.
	*/
	b->yy_ch_buf[0] = 0;
	b->yy_ch_buf[1] = 0;
	
	b->yy_buf_pos = &b->yy_ch_buf[0];
	
	b->yy_at_bol = 1;
	b->yy_buffer_status = YY_BUFFER_NEW;
	
	if ( b == yy_current_buffer )
		yy_load_buffer_state();
}

void yy_init_buffer( YY_BUFFER_STATE b, FILE *file )
{
	yy_flush_buffer( b );
	
	b->yy_input_file = file;
	b->yy_fill_buffer = 1;
	
	b->yy_is_interactive = file ? (isatty( fileno(file) ) > 0) : 0;
}
static void *yy_flex_alloc( int size )
{
	return (void *) malloc( size );
}
static void *yy_flex_realloc(void *Memory, int NewSize)
{
  return realloc(Memory, NewSize);
}

int yy_create_buffer( FILE *file, int size )
{
	YY_BUFFER_STATE b;
	
	b = (YY_BUFFER_STATE) yy_flex_alloc( sizeof( struct yy_buffer_state ) );
	if ( ! b )
		yy_fatal_error( "out of dynamic memory in yy_create_buffer()" );
	
	b->yy_buf_size = size;
	
	/* yy_ch_buf has to be 2 characters longer than the size given because
	* we need to put in 2 end-of-buffer characters.
	*/
	b->yy_ch_buf = (char *) yy_flex_alloc( b->yy_buf_size + 2 );
	if ( ! b->yy_ch_buf )
		yy_fatal_error( "out of dynamic memory in yy_create_buffer()" );
	
	b->yy_is_our_buffer = 1;
	
	yy_init_buffer( b, file );
	
	return b;
}
void yy_new_file( FILE *input_file ) //yyrestart
{
	if ( ! yy_current_buffer )
		yy_current_buffer = yy_create_buffer( yyin, 16384 );
	yy_init_buffer( yy_current_buffer, input_file );
	yy_load_buffer_state();
}
int yywrap()
{ return 1; }
static int yy_get_previous_state()
{
	register int yy_current_state;
	register char *yy_cp;
	
	yy_current_state = yy_start;
	
	for ( yy_cp = yytext ; yy_cp < yy_c_buf_p; ++yy_cp )
	{
		register unsigned char yy_c = (*yy_cp ? yy_ec[(unsigned int) (unsigned char)(*yy_cp)] : 1);
		if ( yy_accept[yy_current_state] )
		{
			yy_last_accepting_state = yy_current_state;
			yy_last_accepting_cpos = yy_cp;
		}
		while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
		{
			yy_current_state = (int) yy_def[yy_current_state];
			if ( yy_current_state >= 137 )
				yy_c = yy_meta[(unsigned int) yy_c];
		}
		yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	}
	
	return yy_current_state;
}

static int yy_try_NUL_trans( int yy_current_state )
{
	register int yy_is_jam;
	register char *yy_cp = yy_c_buf_p;
	
	register unsigned char yy_c = 1;
	if ( yy_accept[yy_current_state] )
	{
		yy_last_accepting_state = yy_current_state;
		yy_last_accepting_cpos = yy_cp;
	}
	while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	{
		yy_current_state = (int) yy_def[yy_current_state];
		if ( yy_current_state >= 137 )
			yy_c = yy_meta[(unsigned int) yy_c];
	}
	yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	yy_is_jam = (yy_current_state == 136);
	
	return yy_is_jam ? 0 : yy_current_state;
}
void yyrestart( FILE *input_file )
{
	if ( ! yy_current_buffer )
		yy_current_buffer = yy_create_buffer( yyin, 16384 );
	yy_init_buffer( yy_current_buffer, input_file );
	yy_load_buffer_state();
}
static int yy_get_next_buffer()
{
	register char *dest = yy_current_buffer->yy_ch_buf;
	register char *source = yytext;
	register int number_to_move, i;
	int ret_val;
	
	if ( yy_c_buf_p > &yy_current_buffer->yy_ch_buf[yy_n_chars + 1] )
		yy_fatal_error(
		"fatal flex scanner internal error--end of buffer missed" );
	
	if ( yy_current_buffer->yy_fill_buffer == 0 )
	{ /* Don't try to fill the buffer, so this is an EOF. */
		if ( yy_c_buf_p - yytext == 1 )
		{
		/* We matched a single character, the EOB, so
		* treat this as a final EOF.
			*/
			return 1;
		}
		else
		{
		/* We matched some text prior to the EOB, first
		* process it.
			*/
			return 2;
		}
	}
	
	/* Try to read more data. */
	
	/* First move last chars to start of buffer. */
	number_to_move = (int) (yy_c_buf_p - yytext) - 1;
	
	for ( i = 0; i < number_to_move; ++i )
		*(dest++) = *(source++);
	
	if ( yy_current_buffer->yy_buffer_status == YY_BUFFER_EOF_PENDING )
	/* don't do the read, it's not guaranteed to return an EOF,
	* just force an EOF
	*/
	yy_current_buffer->yy_n_chars = yy_n_chars = 0;
	
	else
	{
		int num_to_read =
			yy_current_buffer->yy_buf_size - number_to_move - 1;
		
		while ( num_to_read <= 0 )
		{ /* Not enough room in the buffer - grow it. */
			
			/* just a shorter name for the current buffer */
			YY_BUFFER_STATE b = yy_current_buffer;
			
			int yy_c_buf_p_offset =
				(int) (yy_c_buf_p - b->yy_ch_buf);
			
			if ( b->yy_is_our_buffer )
			{
				int new_size = b->yy_buf_size * 2;
				
				if ( new_size <= 0 )
					b->yy_buf_size += b->yy_buf_size / 8;
				else
					b->yy_buf_size *= 2;
				
				b->yy_ch_buf = (char *)
					/* Include room in for 2 EOB chars. */
					yy_flex_realloc( (void *) b->yy_ch_buf,
					b->yy_buf_size + 2 );
			}
			else
				/* Can't grow it, we don't own it. */
				b->yy_ch_buf = 0;
			
			if ( ! b->yy_ch_buf )
				yy_fatal_error(
				"fatal error - scanner input buffer overflow" );
			
			yy_c_buf_p = &b->yy_ch_buf[yy_c_buf_p_offset];
			
			num_to_read = yy_current_buffer->yy_buf_size -
				number_to_move - 1;
		}
		
		if ( num_to_read > 8192 )
			num_to_read = 8192;
		
		//YY_INPUT( (&yy_current_buffer->yy_ch_buf[number_to_move]),
		//	yy_n_chars, num_to_read );
		yy_n_chars=fread(&yy_current_buffer->yy_ch_buf[number_to_move],1,num_to_read,yyin);
		if(yy_n_chars==0)
			yy_fatal_error("input in flex scanner failed");
		
		
		yy_current_buffer->yy_n_chars = yy_n_chars;
	}
	
	if ( yy_n_chars == 0 )
	{
		if ( number_to_move == 0 )
		{
			ret_val = 1;
			yyrestart( yyin );
		}
		
		else
		{
			ret_val = 2;
			yy_current_buffer->yy_buffer_status =
				YY_BUFFER_EOF_PENDING;
		}
	}
	
	else
		ret_val = 0;
	
	yy_n_chars += number_to_move;
	yy_current_buffer->yy_ch_buf[yy_n_chars] = 0;
	yy_current_buffer->yy_ch_buf[yy_n_chars + 1] = 0;
	
	yytext = &yy_current_buffer->yy_ch_buf[0];
	
	return ret_val;
}
int dword_429C9C,dword_429CA0,dword_429CA4,dword_429CA8;
int dword_429CAC;
int dword_45B464,dword_45B468,dword_45B46C,dword_45B470;
char sub_40B940(char a1)
{
  int v1; // eax@1

  LOBYTE(v1) = a1;
  if ( a1 == 10 ) // \n
  {
    dword_429CA8 = 0;
    v1 = dword_429CA4++ + 1;
  }
  else
  {
    if ( a1 == 9 ) // \t
    {
      v1 = dword_429CA8 % -8;
      dword_429CA8 += 8 - dword_429CA8 % -8;
    }
    else
    {
      ++dword_429CA8;
    }
  }
  return v1;
}

int sub_40B990()
{
  int v0; // esi@1
  char v1; // al@2
  int result; // eax@4

  dword_429C9C = dword_429CA4;
  dword_429CA0 = dword_429CA8;
  v0 = 0;
  if ( *yytext )
  {
    v1 = *yytext;
    do
    {
      sub_40B940(v1);
      ++v0;
      v1 = yytext[v0];
    }
    while ( v1 );
  }
  dword_45B464 = dword_429C9C;
  result = dword_429CA8;
  dword_45B468 = dword_429CA0;
  dword_45B46C = dword_429CA4;
  dword_45B470 = dword_429CA8;
  return result;
}
int sub_40C6E0(const char *a1)
{
  void *v1; // edi@1
  const char *v2; // ecx@2
  int v3; // esi@2
  unsigned __int8 v4; // cf@3
  char v5; // dl@5
  int v6; // ecx@7
  void *v7; // edx@11
  signed int v8; // ecx@11
  void *v9; // ebp@11
  const char *v10; // edi@11
  void *result; // eax@15
  unsigned __int8 v12; // al@5
  const char *v13; // esi@11
  void *v14; // eax@11
  char v15; // zf@13
  unsigned int v16; // ecx@15
  char v17; // al@15
  const void *v18; // esi@15
  const void *v19; // esi@15
  void *v20; // edi@15

  v1 = dword_429CAC;
  if ( dword_429CAC )
  {
    while ( 1 )
    {
      v3 = *(_DWORD *)v1;
      v2 = a1;
      while ( 1 )
      {
        v4 = (unsigned __int8)*v2 < *(BYTE *)v3;
        if ( *v2 != *(BYTE *)v3 )
          break;
        if ( !*v2 )
          goto LABEL_7;
        v12 = *(v2 + 1);
        v5 = *(v2 + 1);
        v4 = v12 < *(BYTE *)(v3 + 1);
        if ( v12 != *(BYTE *)(v3 + 1) )
          break;
        v2 += 2;
        v3 += 2;
        if ( !v5 )
        {
LABEL_7:
          v6 = 0;
          goto LABEL_9;
        }
      }
      v6 = -v4 - (v4 - 1);
LABEL_9:
      if ( !v6 )
        break;
      v1 = (void *)*((_DWORD *)v1 + 6);
      if ( !v1 )
        goto LABEL_11;
    }
    result = v1;
  }
  else
  {
LABEL_11:
    v13 = a1;
    v9 = malloc(0x1Cu);
    v14 = malloc(strlen(a1));
    v7 = v14;
    v10 = v13;
    v8 = -1;
    *(_DWORD *)v9 = v14;
    do
    {
      if ( !v8 )
        break;
      v15 = *v10++ == 0;
      --v8;
    }
    while ( !v15 );
    v16 = ~v8;
    v17 = v16;
    v18 = &v10[-v16];
    v16 >>= 2;
    memcpy(v7, v18, 4 * v16);
    v19 = (char *)v18 + 4 * v16;
    v20 = (char *)v7 + 4 * v16;
    LOBYTE(v16) = v17;
    result = v9;
    memcpy(v20, v19, v16 & 3);
    *((_DWORD *)v9 + 1) = 0;
    *((_DWORD *)v9 + 2) = 0;
    *((_DWORD *)v9 + 4) = 0;
    *((_DWORD *)v9 + 3) = 0;
    *((_DWORD *)v9 + 5) = 0;
    *((_DWORD *)v9 + 6) = dword_429CAC;
    dword_429CAC = v9;
  }
  return result;
}
typedef struct{
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;
	char *name;
}KEYVALS;
KEYVALS keyvals[]={
{0xA3,0x9D,0xE4,0x00,"rcontrol"},
{0xA2,0x1D,0xE0,0x00,"lcontrol"},
{0x11,0x1D,0xE0,0x00,"control"},
{0xA1,0x36,0xE5,0x00,"rshift"},
{0xA0,0x2A,0xE1,0x00,"lshift"},
{0x10,0x2A,0xE1,0x00,"shift"},
{0xA5,0xB8,0xE6,0x00,"ralt"},
{0xA4,0x38,0xE2,0x00,"lalt"},
{0x12,0x38,0xE2,0x00,"alt"},
{0x5C,0xDC,0xE7,0x00,"rwin"},
{0x5B,0xDB,0xE3,0x00,"lwin"},
{0x5B,0xDB,0xE3,0x00,"win"},
{0x70,0x3B,0x3A,0x00,"f1"},
{0x71,0x3C,0x3B,0x00,"f2"},
{0x72,0x3D,0x3C,0x00,"f3"},
{0x73,0x3E,0x3D,0x00,"f4"},
{0x74,0x3F,0x3E,0x00,"f5"},
{0x75,0x40,0x3F,0x00,"f6"},
{0x76,0x41,0x40,0x00,"f7"},
{0x77,0x42,0x41,0x00,"f8"},
{0x78,0x43,0x42,0x00,"f9"},
{0x79,0x44,0x43,0x00,"f10"},
{0x7A,0x57,0x44,0x00,"f11"},
{0x7B,0x58,0x45,0x00,"f12"},
{0x7C,0x64,0x68,0x00,"f13"},
{0x7D,0x65,0x69,0x00,"f14"},
{0x7E,0x66,0x6A,0x00,"f15"},
{0x7F,0x00,0x6B,0x00,"f16"},
{0x80,0x00,0x6C,0x00,"f17"},
{0x81,0x00,0x6D,0x00,"f18"},
{0x82,0x00,0x6E,0x00,"f19"},
{0x83,0x00,0x6F,0x00,"f20"},
{0x84,0x00,0x70,0x00,"f21"},
{0x85,0x00,0x71,0x00,"f22"},
{0x86,0x00,0x72,0x00,"f23"},
{0x87,0x00,0x73,0x00,"f24"},
{0x41,0x1E,0x04,0x00,"a"},
{0x42,0x30,0x05,0x00,"b"},
{0x43,0x2E,0x06,0x00,"c"},
{0x44,0x20,0x07,0x00,"d"},
{0x45,0x12,0x08,0x00,"e"},
{0x46,0x21,0x09,0x00,"f"},
{0x47,0x22,0x0A,0x00,"g"},
{0x48,0x23,0x0B,0x00,"h"},
{0x49,0x17,0x0C,0x00,"i"},
{0x4A,0x24,0x0D,0x00,"j"},
{0x4B,0x25,0x0E,0x00,"k"},
{0x4C,0x26,0x0F,0x00,"l"},
{0x4D,0x32,0x10,0x00,"m"},
{0x4E,0x31,0x11,0x00,"n"},
{0x4F,0x18,0x12,0x00,"o"},
{0x50,0x19,0x13,0x00,"p"},
{0x51,0x10,0x14,0x00,"q"},
{0x52,0x13,0x15,0x00,"r"},
{0x53,0x1F,0x16,0x00,"s"},
{0x54,0x14,0x17,0x00,"t"},
{0x55,0x16,0x18,0x00,"u"},
{0x56,0x2F,0x19,0x00,"v"},
{0x57,0x11,0x1A,0x00,"w"},
{0x58,0x2D,0x1B,0x00,"x"},
{0x59,0x15,0x1C,0x00,"y"},
{0x5A,0x2C,0x1D,0x00,"z"},
{0x30,0x0B,0x27,0x00,"0"},
{0x31,0x02,0x1E,0x00,"1"},
{0x32,0x03,0x1F,0x00,"2"},
{0x33,0x04,0x20,0x00,"3"},
{0x34,0x05,0x21,0x00,"4"},
{0x35,0x06,0x22,0x00,"5"},
{0x36,0x07,0x23,0x00,"6"},
{0x37,0x08,0x24,0x00,"7"},
{0x38,0x09,0x25,0x00,"8"},
{0x39,0x0A,0x26,0x00,"9"},
{0x6B,0x4E,0x57,0x00,"add"},
{0x00,0x00,0x79,0x00,"again"},
{0xDE,0x28,0x34,0x00,"apostrophe"},
{0x5D,0xDD,0x65,0x00,"apps"},
{0x08,0x0E,0x2A,0x00,"back"},
{0xDC,0x2B,0x31,0x00,"backslash"},
{0x14,0x3A,0x39,0x00,"capital"},
{0xBC,0x33,0x36,0x00,"comma"},
{0x00,0x00,0x7C,0x00,"copy"},
{0x00,0x00,0x7B,0x00,"cut"},
{0x28,0xD0,0x51,0x00,"down"},
{0x6E,0x53,0x63,0x00,"decimal"},
{0x6F,0xB5,0x54,0x00,"divide"},
{0x2E,0xD3,0x4C,0x00,"delete"},
{0x23,0xCF,0x4D,0x00,"end"},
{0x0D,0x1C,0x28,0x00,"enter"},
{0xBB,0x0D,0x2E,0x00,"equals"},
{0x1B,0x01,0x29,0x00,"escape"},
{0x2B,0x00,0x74,0x00,"execute"},
{0x00,0x00,0x7E,0x00,"find"},
{0xC0,0x29,0x35,0x00,"grave"},
{0x2F,0x00,0x75,0x00,"help"},
{0x24,0xC7,0x4A,0x00,"home"},
{0x2D,0xD2,0x49,0x00,"insert"},
{0xDB,0x1A,0x2F,0x00,"lbracket"},
{0x25,0xCB,0x50,0x00,"left"},
{0xBD,0x0C,0x2D,0x00,"minus"},
{0x00,0x00,0x32,0x00,"misc1"},
{0x00,0x00,0x64,0x00,"misc2"},
{0x00,0x00,0x76,0x00,"miscmenu"},
{0x6A,0x37,0x55,0x00,"multiply"},
{0x00,0xA0,0x7F,0x00,"mute"},
{0x60,0x52,0x62,0x00,"numpad0"},
{0x61,0x4F,0x59,0x00,"numpad1"},
{0x62,0x50,0x5A,0x00,"numpad2"},
{0x63,0x51,0x5B,0x00,"numpad3"},
{0x64,0x4B,0x5C,0x00,"numpad4"},
{0x65,0x4C,0x5D,0x00,"numpad5"},
{0x66,0x4D,0x5E,0x00,"numpad6"},
{0x67,0x47,0x5F,0x00,"numpad7"},
{0x68,0x48,0x60,0x00,"numpad8"},
{0x69,0x49,0x61,0x00,"numpad9"},
{0x00,0xB3,0x85,0x00,"numpadcomma"},
{0x00,0x8D,0x67,0x00,"numpadequals"},
{0x00,0x9C,0x58,0x00,"numpadenter"},
{0x90,0x45,0x53,0x00,"numlock"},
{0x22,0xD1,0x4E,0x00,"pagedown"},
{0x21,0xC9,0x4B,0x00,"pageup"},
{0x00,0x00,0x7D,0x00,"paste"},
{0x13,0xC5,0x48,0x00,"pause"},
{0xBE,0x34,0x37,0x00,"period"},
{0x5E,0xDE,0x66,0x00,"power"},
{0x2A,0xB7,0x46,0x00,"printscreen"},
{0x27,0xCD,0x4F,0x00,"right"},
{0xDD,0x1B,0x30,0x00,"rbracket"},
{0x91,0x46,0x47,0x00,"scroll"},
{0x29,0x00,0x77,0x00,"select"},
{0xBA,0x27,0x33,0x00,"semicolon"},
{0xBF,0x35,0x38,0x00,"slash"},
{0x20,0x39,0x2C,0x00,"space"},
{0x00,0x95,0x78,0x00,"stop"},
{0x6D,0x4A,0x56,0x00,"subtract"},
{0x09,0x0F,0x2B,0x00,"tab"},
{0x00,0x93,0x7A,0x00,"undo"},
{0x26,0xC8,0x52,0x00,"up"},
{0x00,0xAE,0x81,0x00,"volumedown"},
{0x00,0xB0,0x80,0x00,"volumeup"},
0
};
int sub_413550(char *str)
{
	int i,j;
	int match;
	KEYVALS *k=keyvals;
	i=0;
	do{
		match=TRUE;
		j=0;
		do{
			if(k[i].name[j]!=str[j]){
				match=FALSE;
				break;
			}
			j++;
		}while(k[i].name[j]!=0);
		if(match){
			return k[i].c;
		}
		i++;
	}while(k[i].name!=0);
	return 0;
}

static int input()
{
	int c;
	
	*yy_c_buf_p = yy_hold_char;
	
	if ( *yy_c_buf_p == 0 )
	{
	/* yy_c_buf_p now points to the character we want to return.
	* If this occurs *before* the EOB characters, then it's a
	* valid NUL; if not, then we've hit the end of the buffer.
		*/
		if ( yy_c_buf_p < &yy_current_buffer->yy_ch_buf[yy_n_chars] )
			/* This was really a NUL. */
			*yy_c_buf_p = '\0';
		
		else
		{ /* need more input */
			yytext = yy_c_buf_p;
			++yy_c_buf_p;
			
			switch ( yy_get_next_buffer() )
			{
			case 1:
				{
					if ( yywrap() )
					{
						yy_c_buf_p =
							yytext;
						return EOF;
					}
					
					if ( ! yy_did_buffer_switch_on_eof )
						yy_new_file(yyin);
					return input();
				}
				
			case 0:
				yy_c_buf_p = yytext;
				break;
				
			case 2:
				yy_fatal_error(
					"unexpected last match in input()" );

			}
		}
	}
	
	c = *(unsigned char *) yy_c_buf_p;	/* cast for 8-bit char's */
	*yy_c_buf_p = '\0';	/* preserve yytext */
	yy_hold_char = *++yy_c_buf_p;
	
	
	return c;
}
static void yyunput( int c, register char *yy_bp )
{
	register char *yy_cp = yy_c_buf_p;

	/* undo effects of setting up yytext */
	*yy_cp = yy_hold_char;

	if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
		{ /* need to shift things up to make room */
		/* +2 for EOB chars. */
		register int number_to_move = yy_n_chars + 2;
		register char *dest = &yy_current_buffer->yy_ch_buf[
					yy_current_buffer->yy_buf_size + 2];
		register char *source =
				&yy_current_buffer->yy_ch_buf[number_to_move];

		while ( source > yy_current_buffer->yy_ch_buf )
			*--dest = *--source;

		yy_cp += (int) (dest - source);
		yy_bp += (int) (dest - source);
		yy_n_chars = yy_current_buffer->yy_buf_size;

		if ( yy_cp < yy_current_buffer->yy_ch_buf + 2 )
			yy_fatal_error( "flex scanner push-back overflow" );
		}

	*--yy_cp = (char) c;
	yytext = yy_bp;
	yy_hold_char = *yy_cp;
	yy_c_buf_p = yy_cp;
}


char sub_40BA00(int a1)
{
  char v1; // bl@2
  char result; // al@5
  char v3; // al@2
  char v4; // al@4
  int v5; // [sp+0h] [bp-4h]@1

  v5 = a1;
  while ( 1 )
  {
    v3 = input();
    v1 = v3;
    LOBYTE(v5) = v3;
    if ( v3 != '*' )
    {
      do
      {
        if ( !v1 )
          break;
        sub_40B940(v5);
        v4 = input();
        v1 = v4;
        LOBYTE(v5) = v4;
      }
      while ( v4 != '*' );
    }
    result = input();
    if ( result == '/' )
      break;
    if ( !v1 )
      return result;
    yyunput(result, yytext);
  }
  if ( v1 )
    result = sub_40B940(v5);
  return result;
}

int yylex()
{
  __int16 v0; // bx@1
  FILE *yyin_local; // eax@4
  char *yy_bp,*yy_cp; // ebp@11
  //int yy_cp; // edi@11
  signed int yy_current_state; // esi@11
  int v5; // ecx@13
  int v6; // eax@15
  unsigned __int8 v7; // dl@15
  int yy_act; // eax@21
  char *yytext_ptr_temp; // ecx@23
  int yy_current_buf_temp; // eax@25
  int v11; // esi@25
  int next_buf_switch; // eax@28
  int v13; // eax@29
  int yy_next_state; // eax@35
  int result; // eax@46
  int yy_current_state_temp; // eax@35
  int v17; // ecx@35
  int v18; // ecx@39
  int v19; // edi@40
  int v20; // eax@65
  int v21; // eax@65
  unsigned char yy_c; // [sp+10h] [bp-4h]@13

  v0 = 0;
  if ( yy_init )
  {
    yy_init = 0;
    if ( !yy_start )
      yy_start = 1;
    yyin_local = yyin;
    if ( !yyin )
    {
      yyin_local = stdin;
      yyin = stdin;
    }
    if ( !yyout )
      yyout = stdout;
    if ( !yy_current_buffer )
      yy_current_buffer = yy_create_buffer(yyin_local, 16384);
    yy_load_buffer_state();
  }
TOP_WHILE:
  yy_cp = yy_c_buf_p;
  yy_bp = (char *)yy_c_buf_p;
  *(BYTE *)yy_c_buf_p = yy_hold_char;
  yy_current_state = yy_start;

yy_match:
  do
  {
	  yy_c = yy_ec[(unsigned int) (unsigned char)*yy_cp];
	  if ( yy_accept[yy_current_state] )
	  {
		  yy_last_accepting_state = yy_current_state;
		  yy_last_accepting_cpos = yy_cp;
	  }
	  while ( yy_chk[yy_base[yy_current_state] + yy_c] != yy_current_state )
	  {
		  yy_current_state = (int) yy_def[yy_current_state];
		  if ( yy_current_state >= 137 )
			  yy_c = yy_meta[(unsigned int) yy_c];
	  }
	  yy_current_state = yy_nxt[yy_base[yy_current_state] + (unsigned int) yy_c];
	  ++yy_cp;
  }
  while ( yy_base[yy_current_state] != 158 );
  v0 = 0;
  while ( 1 )
  {
    yy_act = yy_accept[yy_current_state];
    if ( !yy_act )
    {
      yy_cp = yy_last_accepting_cpos;
      yy_act = yy_accept[yy_last_accepting_state];
    }
    yytext = yy_bp;
    yyleng = yy_cp - (_DWORD)yy_bp;
    yy_hold_char = *(BYTE *)yy_cp;
    *(BYTE *)yy_cp = 0;
    yytext_ptr_temp = yytext;
    yy_c_buf_p = yy_cp;
yy_do_action:
    switch ( yy_act )
    {
      case 71:
        *(BYTE *)yy_cp = yy_hold_char;
        yy_current_buf_temp = yy_current_buffer;
        v11 = yy_cp - (_DWORD)yytext_ptr_temp - 1;
        if ( !*(_DWORD *)(yy_current_buffer + 36) )
        {
          yy_n_chars = *(_DWORD *)(yy_current_buffer + 16);
          *(_DWORD *)yy_current_buffer = yyin;
          *(_DWORD *)(yy_current_buffer + 36) = 1;
          yy_current_buf_temp = yy_current_buffer;
        }
        if ( yy_c_buf_p <= (unsigned int)(yy_n_chars + *(_DWORD *)(yy_current_buf_temp + 4)) )
        {
          yy_c_buf_p = (int)&yytext[v11];
          yy_current_state_temp = yy_get_previous_state();
          yy_current_state = yy_current_state_temp;
          yy_next_state = yy_try_NUL_trans(yy_current_state_temp);
          yy_bp = yytext;
          yy_cp = yy_c_buf_p;
          if ( !yy_next_state )
            continue;
          yy_cp = yy_c_buf_p + 1;
          yy_current_state = yy_next_state;
          ++yy_c_buf_p;
          goto yy_match;
        }
        next_buf_switch = yy_get_next_buffer();
        if ( !next_buf_switch )
        {
          yy_c_buf_p = (int)&yytext[v11];
          yy_cp = yy_c_buf_p;
          yy_bp = yytext;
          yy_current_state = yy_get_previous_state();
          goto yy_match;
        }
        v13 = next_buf_switch - 1;
        if ( !v13 )
        {
          yy_did_buffer_switch_on_eof = 0;
          if ( yywrap() )
          {
            yytext_ptr_temp = yytext;
            yy_c_buf_p = (int)yytext;
            yy_act = (yy_start - 1) / 2 + 72;
            goto yy_do_action;
          }
          if ( !yy_did_buffer_switch_on_eof )
            yy_new_file(yyin);
          goto TOP_WHILE;
        }
        if ( v13 != 1 )
          goto TOP_WHILE;
        yy_c_buf_p = yy_n_chars + *(_DWORD *)(yy_current_buffer + 4);
        yy_cp = yy_c_buf_p;
        yy_bp = yytext;
        yy_current_state = yy_get_previous_state();
        break;
      case 0:
        *(BYTE *)yy_cp = yy_hold_char;
        yy_cp = yy_last_accepting_cpos;
        yy_current_state = yy_last_accepting_state;
        continue;
      case 1:
        sub_40B990();
        sub_40BA00(v18);
        goto TOP_WHILE;
      case 2:
        *(BYTE *)yy_cp = yy_hold_char;
        v19 = yy_cp - 1;
        yy_c_buf_p = v19;
        yytext = yy_bp;
        yyleng = v19 - (_DWORD)yy_bp;
        yy_hold_char = *(BYTE *)v19;
        *(BYTE *)v19 = 0;
        yy_c_buf_p = v19;
        sub_40B990();
        goto TOP_WHILE;
      case 68:
      case 69:
        sub_40B990();
        goto TOP_WHILE;
      case 70:
        fwrite(yytext_ptr_temp, yyleng, 1u, yyout);
        goto TOP_WHILE;
      case 3:
        sub_40B990();
        return 282;
      case 4:
        sub_40B990();
        return 294;
      case 5:
        sub_40B990();
        return 284;
      case 6:
        sub_40B990();
        return 293;
      case 7:
        sub_40B990();
        return 285;
      case 8:
        sub_40B990();
        return 290;
      case 9:
        sub_40B990();
        return 287;
      case 10:
        sub_40B990();
        return 283;
      case 11:
        sub_40B990();
        return 291;
      case 12:
        sub_40B990();
        return 292;
      case 13:
        sub_40B990();
        return 286;
      case 14:
        sub_40B990();
        return 280;
      case 15:
        sub_40B990();
        return 295;
      case 16:
        sub_40B990();
        return 281;
      case 17:
        sub_40B990();
        return 288;
      case 18:
        sub_40B990();
        return 289;
      case 19:
        sub_40B990();
        keyword_pointer = sub_40C6E0(yytext);
        return 258;
      case 20:
      case 21:
        sub_40B990();
        return 259;
      case 22:
        sub_40B990();
        keyword_pointer = atoi(yytext);
        return 259;
      case 23:
        sub_40B990();
        v20 = sub_413550(yytext + 1);
        keyword_pointer = v20;
        v21 = -(v20 != 0);
        LOBYTE(v21) = v21 & 0xDB;
        return v21 + 296;
      case 24:
        sub_40B990();
        return 276;
      case 25:
        sub_40B990();
        return 275;
      case 26:
        sub_40B990();
        return 273;
      case 27:
        sub_40B990();
        return 274;
      case 28:
        sub_40B990();
        return 270;
      case 29:
        sub_40B990();
        return 271;
      case 30:
        sub_40B990();
        return 272;
      case 31:
        sub_40B990();
        return 277;
      case 32:
        sub_40B990();
        return 278;
      case 33:
        sub_40B990();
        return 279;
      case 34:
        sub_40B990();
        return 263;
      case 35:
        sub_40B990();
        return 262;
      case 36:
        sub_40B990();
        return 260;
      case 37:
        sub_40B990();
        return 261;
      case 38:
        sub_40B990();
        return 268;
      case 39:
        sub_40B990();
        return 269;
      case 40:
        sub_40B990();
        return 264;
      case 41:
        sub_40B990();
        return 265;
      case 42:
        sub_40B990();
        return 266;
      case 43:
        sub_40B990();
        return 267;
      case 44:
        sub_40B990();
        return 59;
      case 45:
        sub_40B990();
        return 123;
      case 46:
        sub_40B990();
        return 125;
      case 47:
        sub_40B990();
        return 44;
      case 48:
        sub_40B990();
        return 58;
      case 49:
        sub_40B990();
        return 61;
      case 50:
        sub_40B990();
        return 40;
      case 51:
        sub_40B990();
        return 41;
      case 52:
        sub_40B990();
        return 91;
      case 53:
        sub_40B990();
        return 93;
      case 54:
        sub_40B990();
        return 46;
      case 55:
        sub_40B990();
        return 38;
      case 56:
        sub_40B990();
        return 33;
      case 57:
        sub_40B990();
        return 126;
      case 58:
        sub_40B990();
        return 45;
      case 59:
        sub_40B990();
        return 43;
      case 60:
        sub_40B990();
        return 42;
      case 61:
        sub_40B990();
        return 47;
      case 62:
        sub_40B990();
        return 37;
      case 63:
        sub_40B990();
        return 60;
      case 64:
        sub_40B990();
        return 62;
      case 65:
        sub_40B990();
        return 94;
      case 66:
        sub_40B990();
        return 124;
      case 67:
        sub_40B990();
        return 63;
      case 72:
        return 0;
      default:
        yy_fatal_error((int)"fatal flex scanner internal error--no action found");
        return result;
    }
  }
}
