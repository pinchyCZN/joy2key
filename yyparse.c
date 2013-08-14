#include <stdio.h>
#include <string.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

static const char yytranslate[]={
  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2, 50,  2,  2,  2, 52, 45,  2, 42, 43, 47, 46, 44, 48,  2, 51,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2, 58, 60, 53, 59, 54, 57,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2, 55,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2, 61, 56, 62, 49,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16,
 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
 33, 34, 35, 36, 37, 38, 39, 40, 41,  0,  0,  0,  0,  0,  0,  0
};//count=304 (0x0130)

static const short yyr1[]={
   0,  63,  63,  63,  63,  64,  65,  64,  64,  64,  66,  66,  67,  67,  68,  68,
  68,  68,  68,  68,  69,  69,  69,  69,  70,  70,  70,  70,  71,  71,  71,  72,
  72,  72,  73,  73,  73,  73,  73,  74,  74,  74,  75,  75,  76,  76,  77,  77,
  78,  78,  79,  79,  80,  80,  81,  81,  81,  82,  82,  82,  82,  82,  82,  82,
  82,  82,  82,  83,  83,  84,  85,  86,  86,  87,  87,  88,  88,  89,  89,  89,
  89,  90,  90,  90,  90,  90,  90,  91,  91,  91,  92,  94,  93,  95,  95,  95,
  95,  96,  96,  97,  97,  98,  98,  99,  99,  99, 100, 100, 100, 100, 100, 100,
 100, 100, 100, 100, 102, 101, 103, 103, 103, 103, 103, 104, 104, 105, 105, 106,
 106, 107, 107, 107, 109, 108, 110, 110, 111, 111, 112, 112, 113,   0,   0,   0
};//count=144 (0x0090)

static const short yyr2[]={
   0,   1,   1,   1,   3,   1,   0,   4,   2,   2,   1,   2,   1,   3,   1,   2,
   2,   2,   2,   2,   1,   1,   1,   1,   1,   3,   3,   3,   1,   3,   3,   1,
   3,   3,   1,   3,   3,   3,   3,   1,   3,   3,   1,   3,   1,   3,   1,   3,
   1,   3,   1,   3,   1,   5,   1,   3,   3,   1,   1,   1,   1,   1,   1,   1,
   1,   1,   1,   1,   3,   1,   3,   1,   2,   1,   3,   1,   3,   1,   1,   1,
   1,   1,   1,   1,   1,   1,   1,   3,   4,   3,   2,   0,   3,   1,   2,   2,
   3,   1,   2,   1,   2,   1,   2,   5,   7,   5,   5,   7,   6,   7,   7,   8,
   7,   8,   8,   9,   0,   2,   3,   2,   2,   2,   3,   1,   2,   1,   1,   1,
   2,   2,   2,   4,   0,   4,   1,   2,   1,   3,   1,   2,   1,   0,   0,   0
};//count=144 (0x0090)

static const short yydefact[]={
   0, 140,  80,  77,  78,  79, 126,   0,  71,   0, 123, 125, 127,   0,   0,   0,
  73,  72, 128,  75, 124,   0, 130,   0, 129, 132,   0,  70,   0,   2,   0,   0,
   3,   0,   0,   0,  20,  21,  22,  23,   5,  14,  24,   0,  28,  31,  34,  39,
  42,  44,  46,  48,  50,  52,   0,   1,   0,   0,   0,   0,   0, 116,   0,   0,
   0,   0,   0, 101,  91,  93,  24,  54,  67,   0,  97,   0,  99,  81,  82,  90,
   0,   0,  83,  84,  85,  86,   1,   0,  74,  75,  76,  15,  16,   0,  17,  18,
   8,   9,  19,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   0,   0,   0,   0, 131,   6,  69,   0,   0,   0,   0,   0,   0,   0,
   0,   0, 119, 120, 121,   0,   0,  57,  58,  59,  60,  61,  62,  63,  64,  65,
  66,   0,   0,   0, 102,  95,  98,   0,  94, 100,   0,   0, 134, 133,   0, 136,
 138,   4,  25,  26,  27,  29,  30,  32,  33,  37,  38,  35,  36,  40,  41,  43,
  45,  47,  49,  51,   0,   0,   0,  89,   0,   0,   0,   0, 117,   0,   0, 118,
 122
};//count=193 (0x00C1)

static const short yydefgoto[]={
  92,  55,  56,  68,  96,  87, 139, 135,   0,   0,  10,   7,   0,  12,  88,   0,
   0, 116,   0,   0,   0,   0, 137,  53,  11,   0, 103, 105, 106,   0, 116,   0,
   0,   0,   0,  13,   0,   0, 108, 116, 116,   0, 116,   0,   0, 104, 107, 109,
 110, 116, 112, 116, 116,   0, 111, 113, 114, 116, 115,   0,   0,   0,   0,  40,
  41, 181, 204, 205,  70,  43,  44,  45,  46,  47,  48,  49,  50,  51,  52,  53,
  71,  72, 146,  73, 121,   6,  75,  15,  16,   8,  76,  77,  24,  78, 134,  79,
  80,  81,  82,  83,  84, 126, 127,  85,   9,  10,  11,  12,  13,  87, 157, 158,
 159,  55,   0
};//count=115 (0x0073)

static const short yypact[]={
 121,-32768,-32768,-32768,-32768,-32768,-32768, 121,-32768,  51,-32768,-32768,-32768,  40,  19, -28,
-32768,-32768,-32768, -23,-32768, 538,-32768, 185,-32768,-32768,  71,-32768, 538,-32768, 538, 538,
-32768, 538, 538, 538,-32768,-32768,-32768,-32768,-32768,  16,-32768, 538,  39,  77,  75,  -4,
 145, -18,  33,  94,  83,   1,  85, 136, 538, 142, 160, 161, 162,-32768, 165,  71,
 157, 168, 394,-32768,-32768,-32768, 120,-32768,-32768, -16,-32768, 121,-32768,-32768,-32768,-32768,
 233, 281,-32768,-32768,-32768,-32768,  -1,  17,-32768, 125,-32768,-32768,-32768,  89,-32768,-32768,
-32768,-32768,-32768, 538, 538, 538, 538, 538, 538, 538, 538, 538, 538, 538, 538, 538,
 538, 538, 538, 538, 538, 538,-32768,-32768,-32768, 182, 377, 538, 538, 538, 207, 377,
 425, 183,-32768,-32768,-32768, -15, 185,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768, 538, 538, 538,-32768,-32768,-32768, 329,-32768,-32768, 377,  71,-32768,-32768, 116,-32768,
-32768,-32768,-32768,-32768,-32768,  39,  39,  77,  77,  75,  75,  75,  75,  -4,  -4, 145,
 -18,  33,  94,  83, -11, 303, 377,-32768, 118, 122, 124, 200,-32768, 442,  12,-32768,
-32768
};//count=193 (0x00C1)

static const short yypgoto[]={
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,  15, 538,-32768,-32768, 126,-32768,-32768, 377,
 377,-32768, 538, 474,  24, 458,-32768,-32768,-32768, 538, 212,-32768,-32768, 128,-32768, 131,
 490, 506,  29,-32768, 377, 188,-32768,-32768,-32768, 133,-32768, 143, 522,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768, 149,-32768,-32768,-32768,-32768,-32768, 249,-32768,   0,   0,-32768,
-32768,-32768,-32768,-32768,   3,-32768,  61,  92,  22,  88, 138, 139, 137, 140, 141, 148,
 -17,-133,-32768, -31,-32768, -13,   8,-32768, 227,  -6, -56,-32768,-32768,-32768,-32768, 154,
-32768, 174,-32768,-32768,-32768,-180,-32768,-32768,-32768, 247,-32768, 269,-32768,-32768,-32768,-32768,
  76,   0,   0
};//count=115 (0x0073)

static const short yytable[]={
  14,  17,  93, 116,  54, 106, 107,  19,   7,  14,  74,  90, 194, 195, 196, 116,
  26,   7,   1,  25,   1,  96,  97,  86,  42, 153,  89, 112, 147, 147, 221,  42,
  27,  91,  92, 133,  28,  94,  95, 120, 155, 119, 155, 231, 148, 192,  98, 202,
 206, 108, 109, 252, 240, 241,   1, 243, 147, 154, 117,  42, 156,  25, 247, 129,
 248, 249, 183, 150, 147,  17, 251, 188, 214, 147,   1,  89,   2,   3,   4,   5,
  86,  86, 104, 105, 225, 228,  99, 160, 113, 237, 100, 101, 184, 185, 186, 153,
 115, 190, 198,  21,  22,  23, 162, 163, 164,  42,  42,  42,  42,  42,  42,  42,
  42,  42,  42,  42,  42,  42,  42,  42,  42,  74,  86, 102,   1, 103, 207,  86,
 169, 170, 171, 172, 161, 147,  86, 135, 136, 137, 138, 139, 140, 141, 142, 143,
 144, 118,   2,   3,   4,   5, 114,  86, 219, 220,  86, 199, 110, 111, 213, 200,
 201, 208, 147, 165, 166, 209, 147, 210, 147, 217, 218, 230, 147, 238, 232, 147,
 242, 147, 119, 145, 222, 224,  86, 227,  28, 216, 244, 147,   1,  29,  30,  31,
 250, 147, 234, 236, 167, 168, 173, 174, 122, 160, 123, 124, 125,  42, 246, 128,
  86,  86,   2,   3,   4,   5,  56,  57,  58, 130,  59,  60,  61,  62,  63,  64,
  65,  66,  32,  33, 131,  86,  34,  35,  36,  37,  38,  39,   1,  29,  30,  31,
 182, 187, 211, 191, 229,  67,  68,  69, 239, 253, 175, 177, 176,  88, 151, 178,
  20, 179,   2,   3,   4,   5,  56,  57,  58, 180,  59,  60,  61,  62,  63,  64,
  65,  66,  32,  33,  18, 215,  34,  35,  36,  37,  38,  39,   1,  29,  30,  31,
 193,   0,   0,   0,   0,  67,  68, 149,   0,   0,   0,   0,   0,   0,   0,   0,
   0,   0,   1,  29,  30,  31,  56,  57,  58,   0,  59,  60,  61,  62,  63,  64,
  65,  66,  32,  33,   0,   0,  34,  35,  36,  37,  38,  39,   1,  29,  30,  31,
   0,   0,   0,   0,   0,  67,  68, 152,  32,  33, 203,   0,  34,  35,  36,  37,
  38,  39,   0,   0,   0,   0,  56,  57,  58,   0,  59,  60,  61,  62,  63,  64,
  65,  66,  32,  33,   0,   0,  34,  35,  36,  37,  38,  39,   1,  29,  30,  31,
   0,   0,   0,   0,   0,  67,  68, 197,   0,   0,   0,   0,   0,   1,  29,  30,
  31,   0,   0,   0,   0,   0,  56,  57,  58,   0,  59,  60,  61,  62,  63,  64,
  65,  66,  32,  33,   0,   0,  34,  35,  36,  37,  38,  39,   1,  29,  30,  31,
   0,   0,   0,  32,  33,  67,  68,  34,  35,  36,  37,  38,  39,   1,  29,  30,
  31,   0,   0,   0,   0,   0, 132,   0,   0,   0,   0,   0,   0,   1,  29,  30,
  31,   0,  32,  33,   0,   0,  34,  35,  36,  37,  38,  39,   0,   1,  29,  30,
  31,   0,   0,  32,  33, 189,   0,  34,  35,  36,  37,  38,  39,   1,  29,  30,
  31,   0,   0,  32,  33,   0, 212,  34,  35,  36,  37,  38,  39,   1,  29,  30,
  31,   0,   0,  32,  33, 223, 226,  34,  35,  36,  37,  38,  39,   1,  29,  30,
  31,   0,   0,  32,  33, 233,   0,  34,  35,  36,  37,  38,  39,   1,  29,  30,
  31,   0,   0,  32,  33, 235,   0,  34,  35,  36,  37,  38,  39,   0,   0,   0,
   0,   0,   0,  32,  33, 245,   0,  34,  35,  36,  37,  38,  39,   0,   0,   0,
   0,   0,   0,  32,  33,   0,   0,  34,  35,  36,  37,  38,  39,   0,   0,   0
};//count=592 (0x0250)

static const short yycheck[]={
   0,   7,  33,  14,  21,   9,  10,   7,   0,   9,  23,  28, 145, 146, 147,  14,
  44,   9,   3,  42,   3,   5,   6,  23,  21,  81,  26,  45,  44,  44, 210,  28,
  60,  30,  31,  66,  59,  34,  35,  56,  25,  42,  25, 223,  60,  60,  43,  58,
 181,  53,  54,   0, 232, 233,   3, 235,  44,  58,  57,  56,  43,  42, 242,  63,
 244, 245, 122,  80,  44,  75, 250, 127,  60,  44,   3,  75,  25,  26,  27,  28,
  80,  81,   7,   8,  60, 218,  47,  87,  55,  60,  51,  52, 123, 124, 125, 151,
  13, 128, 154,  59,  60,  61,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108,
 109, 110, 111, 112, 113, 114, 115, 116, 117, 134, 122,  46,   3,  48, 182, 127,
 106, 107, 108, 109,  43,  44, 134,  15,  16,  17,  18,  19,  20,  21,  22,  23,
  24,  60,  25,  26,  27,  28,  56, 151, 208, 209, 154, 155,  11,  12, 189,  43,
  44,  43,  44, 102, 103,  43,  44,  43,  44,  43,  44,  43,  44, 229,  43,  44,
  43,  44,  42,  59, 211, 212, 182, 214,  59, 202,  43,  44,   3,   4,   5,   6,
  43,  44, 225, 226, 104, 105, 110, 111,  58, 201,  42,  42,  42, 202, 237,  42,
 208, 209,  25,  26,  27,  28,  29,  30,  31,  60,  33,  34,  35,  36,  37,  38,
  39,  40,  41,  42,  60, 229,  45,  46,  47,  48,  49,  50,   3,   4,   5,   6,
  58,  34,  42,  60,  32,  60,  61,  62,  60,   0, 112, 114, 113,  26,  80, 115,
   9, 116,  25,  26,  27,  28,  29,  30,  31, 117,  33,  34,  35,  36,  37,  38,
  39,  40,  41,  42,   7, 201,  45,  46,  47,  48,  49,  50,   3,   4,   5,   6,
 134,  -1,  -1,  -1,  -1,  60,  61,  62,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
  -1,  -1,   3,   4,   5,   6,  29,  30,  31,  -1,  33,  34,  35,  36,  37,  38,
  39,  40,  41,  42,  -1,  -1,  45,  46,  47,  48,  49,  50,   3,   4,   5,   6,
  -1,  -1,  -1,  -1,  -1,  60,  61,  62,  41,  42,  43,  -1,  45,  46,  47,  48,
  49,  50,  -1,  -1,  -1,  -1,  29,  30,  31,  -1,  33,  34,  35,  36,  37,  38,
  39,  40,  41,  42,  -1,  -1,  45,  46,  47,  48,  49,  50,   3,   4,   5,   6,
  -1,  -1,  -1,  -1,  -1,  60,  61,  62,  -1,  -1,  -1,  -1,  -1,   3,   4,   5,
   6,  -1,  -1,  -1,  -1,  -1,  29,  30,  31,  -1,  33,  34,  35,  36,  37,  38,
  39,  40,  41,  42,  -1,  -1,  45,  46,  47,  48,  49,  50,   3,   4,   5,   6,
  -1,  -1,  -1,  41,  42,  60,  61,  45,  46,  47,  48,  49,  50,   3,   4,   5,
   6,  -1,  -1,  -1,  -1,  -1,  60,  -1,  -1,  -1,  -1,  -1,  -1,   3,   4,   5,
   6,  -1,  41,  42,  -1,  -1,  45,  46,  47,  48,  49,  50,  -1,   3,   4,   5,
   6,  -1,  -1,  41,  42,  60,  -1,  45,  46,  47,  48,  49,  50,   3,   4,   5,
   6,  -1,  -1,  41,  42,  -1,  60,  45,  46,  47,  48,  49,  50,   3,   4,   5,
   6,  -1,  -1,  41,  42,  43,  60,  45,  46,  47,  48,  49,  50,   3,   4,   5,
   6,  -1,  -1,  41,  42,  43,  -1,  45,  46,  47,  48,  49,  50,   3,   4,   5,
   6,  -1,  -1,  41,  42,  43,  -1,  45,  46,  47,  48,  49,  50,  -1,  -1,  -1,
  -1,  -1,  -1,  41,  42,  43,  -1,  45,  46,  47,  48,  49,  50,  -1,  -1,  -1,
  -1,  -1,  -1,  41,  42,  -1,  -1,  45,  46,  47,  48,  49,  50,   0
};//count=590 (0x024E)

int yynerrs=0;
int yychar=0;

int tmp_yyvs=0;
extern int keyword_pointer;

extern int dword_45B464;
extern int dword_45B468;
extern int dword_45B46C;
extern int dword_45B470;

int dword_45B5B4=0;

int dword_45B5E8=0;
int dword_45B480[1000];
int dword_45B548=0;
int Memory;

signed int __cdecl yyparse()
{
  int *yyvsp; // ebx@1
  signed int yystate; // edi@1
  int size; // esi@3
  unsigned int yychar_; // eax@8
  signed int yyn__; // esi@8
  signed int yychar1; // ecx@12
  int yyn_; // esi@16
  signed int _yyn; // edx@19
  int yyn___; // ecx@21
  int yylen; // esi@22
  int v10; // eax@28
  int v11; // ecx@28
  int v12; // ecx@31
  int v13; // ST18_4@31
  int v14; // ST1C_4@31
  int v15; // eax@32
  int v16; // ST18_4@32
  int v17; // ST1C_4@32
  int v18; // eax@33
  void *v19; // ST10_4@46
  int v20; // ST14_4@46
  int v21; // ST18_4@46
  int v22; // ST1C_4@46
  void *v23; // eax@47
  void *v24; // ST04_4@64
  int v25; // ST08_4@64
  int v26; // ST0C_4@64
  void *v27; // ST10_4@64
  int v28; // ST14_4@64
  int v29; // ST18_4@64
  int v30; // ST1C_4@64
  int v31; // eax@77
  int v32; // edi@81
  int v33; // ST0C_4@81
  int v34; // ST18_4@107
  int v35; // ST1C_4@107
  int v36; // edx@110
  int v37; // ST18_4@110
  int v38; // ST1C_4@110
  int v39; // ST14_4@114
  int v40; // ST18_4@114
  int v41; // ST1C_4@114
  int v42; // ST14_4@120
  int v43; // ST18_4@120
  int v44; // ST1C_4@120
  int v45; // ecx@126
  int v46; // ST18_4@126
  int v47; // ST1C_4@126
  int v48; // edx@131
  int v49; // eax@135
  int v50; // ecx@135
  int v51; // edi@135
  int v52; // eax@138
  int v53; // edx@138
  char *errstr_p; // ST18_4@146
  int yyvs_offset; // ST1C_4@146
  int _yyerrstatus; // eax@158
  int __yyssp; // ecx@167
  signed int v_yyn; // eax@168
  int _v_yyn; // eax@169
  signed int yyn_2; // eax@172
  int _yyssp; // eax@2
  char yyssp_compare_stacksize; // cf@2
  int __yyss; // edx@3
  int _yystacksize; // eax@4
  int v_2xsize; // ebx@6
  int v_4xsize; // edi@6
  int v_24xsize; // esi@6
  int v_yyssp; // eax@6
  char v_yychar1; // sf@16
  int v71; // edx@21
  void *v72; // eax@25
  int v73; // eax@27
  void *v74; // eax@28
  int v75; // eax@28
  int v76; // eax@28
  void *v77; // ST1C_4@29
  int v78; // ST18_4@29
  int v79; // ST10_4@29
  int v80; // eax@29
  int v81; // eax@29
  int v82; // eax@29
  int v83; // eax@34
  void *v84; // eax@37
  void *v85; // eax@39
  void *v86; // edi@64
  int v87; // ST18_4@66
  int v88; // ST14_4@66
  void *v89; // eax@66
  int v90; // eax@66
  int v91; // eax@66
  int v92; // eax@66
  signed int v93; // eax@78
  void *v94; // eax@82
  int v95; // eax@82
  int v96; // eax@82
  int v97; // eax@82
  int v98; // eax@85
  int v99; // eax@85
//  int v100; // eax@86
//  int v101; // eax@87
//  int v102; // eax@88
  int v103; // eax@89
  int v104; // ST1C_4@102
  int v105; // eax@102
  int v106; // eax@102
  void *v107; // edi@103
  int v108; // eax@104
  int v109; // eax@104
  int v110; // eax@104
  int v111; // eax@122
  int v112; // eax@122
  int v113; // eax@123
  int v114; // eax@123
  int v115; // eax@124
  int v116; // eax@124
  int v117; // eax@126
  int v118; // eax@126
  int v119; // eax@126
  int v120; // eax@126
  int v121; // edi@128
  void *v122; // ST18_4@128
  void *v123; // eax@128
  int v124; // eax@128
  int v125; // eax@128
  int v126; // eax@128
  int v127; // ecx@135
  int v128; // eax@138
  int v129; // esi@138
  char v130; // sf@138
  void *v_yyvs; // edi@158
  char c_yyerrstatus; // zf@158
  int yyn_3; // eax@178
  void *_yyvs; // edi@180
  char v135[200]; // [sp+15ECh] [bp-1B8h]@1
  int _yyss; // [sp+1788h] [bp-1Ch]@1
//  __int16 v137[200]; // [sp+15EAh] [bp-1BAh]@1
  int yyssp; // [sp+1794h] [bp-10h]@1
  char v139[200]; // [sp+12CCh] [bp-4D8h]@1
  int yyss; // [sp+1784h] [bp-20h]@1
  char yyvsa[200]; // [sp+Ch] [bp-1798h]@1
  int v_yyvsa; // [sp+1780h] [bp-24h]@1
  signed int yystacksize; // [sp+1790h] [bp-14h]@1
  signed int yyn; // [sp+1798h] [bp-Ch]@1
  int yyerrstatus; // [sp+178Ch] [bp-18h]@1
  int yyvs; // [sp+179Ch] [bp-8h]@1
  int yyls; // [sp+177Ch] [bp-28h]@3
  int yyss1; // [sp+0h] [bp-17A4h]@6
  signed int yyval; // [sp+17A0h] [bp-4h]@23

  _yyss = (int)&v135;
  yystate = 0;
  yyssp = _yyss-2; //(int)&v137;
  yyss = (int)&v139;
  v_yyvsa = (int)&yyvsa;
  yystacksize = 200;
  yyn = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = -2;
  yyvsp = (int *)&v139;
  yyvs = (int)&yyvsa;
  while ( 1 )
  {
yynewstate:
    _yyssp = yyssp + 2;
    yyssp_compare_stacksize = yyssp + 2 < (unsigned int)(_yyss + 2 * yystacksize - 2);
    yyssp += 2;
    *(WORD *)_yyssp = yystate;
    if ( !yyssp_compare_stacksize )
    {
      __yyss = yyss;
      yyss = _yyss;
      yyvs = __yyss;
      size = ((yyssp - _yyss) >> 1) + 1;
      yyls = v_yyvsa;
      if ( yystacksize >= 10000 )
      {
        yyerror("parser stack overflow");
        return 2;
      }
      _yystacksize = 2 * yystacksize;
      yystacksize *= 2;
      if ( _yystacksize > 10000 )
        yystacksize = 10000;
      v_2xsize = 2 * size;
      _yyss = (int)&yyss1;
      _yy_memcpy(yyss, (int)&yyss1, 2 * size);
      v_4xsize = 4 * size;
      yyss = (int)&yyss1;
      _yy_memcpy(yyvs, (int)&yyss1, 4 * size);
      v_24xsize = 24 * size;
      v_yyvsa = (int)&yyss1;
      _yy_memcpy(yyls, (int)&yyss1, v_24xsize);
      v_yyssp = v_2xsize + _yyss - 2;
      yyvsp = (int *)(v_4xsize + yyss - 4);
      yyssp = v_yyssp;
      yyvs = v_24xsize + v_yyvsa - 24;
      if ( v_yyssp >= (unsigned int)(_yyss + 2 * yystacksize - 2) )
        return 1;
      yystate = yyn;
    }
    yyn__ = yypact[yystate];
    yychar_ = yychar;
    if ( yyn__ == -32768 )
      goto yydefault;
    if ( yychar == -2 )
    {
      yychar_ = yylex();
      yychar = yychar_;
    }
    if ( (signed int)yychar_ > 0 )
    {
      if ( yychar_ > 0x128 )
        yychar1 = 114;
      else
        yychar1 = yytranslate[yychar_];
    }
    else
    {
      yychar1 = 0;
      yychar_ = 0;
      yychar = 0;
    }
    v_yychar1 = yychar1 + yyn__ < 0;
    yyn_ = yychar1 + yyn__;
    if ( v_yychar1 || yyn_ > 588 || yycheck[yyn_] != yychar1 )
    {
yydefault:
      yyn___ = yydefact[yystate];
      yyn = yydefact[yystate];
      if ( !yyn___ )
        goto yyerrlab;
yyreduce:
      yylen = yyr2[yyn___];
      if ( yylen > 0 )
        yyval = yyvsp[-yylen + 1];
      switch ( yyn___ )
      {
        case 1:
          v72 = (void *)handle_symbol(*yyvsp, yyvs);
          yyval = realloc_mem(v72, 32);
          goto LABEL_135;
        case 2:
          yyval = resize_mem(0, 272, *yyvsp);
          goto LABEL_135;
        case 6:
          v73 = dword_45B5E8++ + 1;
          dword_45B480[v73] = 0;
          goto LABEL_135;
        case 7:
          v74 = (void *)handle_symbol(*(yyvsp - 3), yyvs - 72);
          v75 = realloc_mem(v74, 32);
          v76 = realloc_mem((void *)v75, 128);
          v11 = v76;
          yyval = v76;
          v10 = dword_45B480[dword_45B5E8];
          if ( v10 )
          {
            v77 = (void *)v11;
            v78 = -1 - v10;
            v79 = *yyvsp;
            v80 = realloc_mem(0, 147);
            v81 = more_mem(v80, (void *)v79);
            v82 = resize_mem((void *)v81, 400, v78);
            yyval = more_mem(v82, v77);
          }
          --dword_45B5E8;
          goto LABEL_135;
        case 8:
          v12 = *(yyvsp - 1);
          v14 = 33;
          v13 = yyvs - 24;
          goto LABEL_37;
        case 9:
          v15 = *(yyvsp - 1);
          v17 = 34;
          v16 = yyvs - 24;
          goto LABEL_39;
        case 12:
          v18 = realloc_mem((void *)*yyvsp, 147);
          goto LABEL_35;
        case 13:
          v83 = realloc_mem((void *)*yyvsp, 147);
          v18 = more_mem(*(yyvsp - 2), (void *)v83);
LABEL_35:
          yyval = v18;
          ++dword_45B480[dword_45B5E8];
          goto LABEL_135;
        case 15:
          v12 = *yyvsp;
          v14 = 35;
          v13 = yyvs;
LABEL_37:
          v84 = (void *)expression_handler(v12, v13);
          yyval = realloc_mem(v84, v14);
          goto LABEL_135;
        case 16:
          v15 = *yyvsp;
          v17 = 36;
          v16 = yyvs;
LABEL_39:
          v85 = (void *)expression_handler(v15, v16);
          yyval = realloc_mem(v85, v17);
          goto LABEL_135;
        case 17:
          yyval = expression_handler(*yyvsp, yyvs);
          goto LABEL_135;
        case 19:
          yyval = realloc_mem((void *)*yyvsp, *(yyvsp - 1));
          goto LABEL_135;
        case 20:
          yyval = 32;
          goto LABEL_135;
        case 21:
          yyval = 66;
          goto LABEL_135;
        case 22:
          yyval = 65;
          goto LABEL_135;
        case 23:
          yyval = 64;
          goto LABEL_135;
        case 25:
          v22 = 596;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 26:
          v23 = (void *)*(yyvsp - 2);
          v22 = 597;
          v21 = *yyvsp;
          v20 = 147;
          goto LABEL_84;
        case 27:
          v22 = 598;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 29:
          v22 = 594;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 30:
          v23 = (void *)*(yyvsp - 2);
          v22 = 595;
          v21 = *yyvsp;
          v20 = 147;
          goto LABEL_84;
        case 32:
          v22 = 592;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 33:
          v22 = 593;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 35:
          v23 = (void *)*(yyvsp - 2);
          v22 = 611;
          v21 = *yyvsp;
          v20 = 147;
          goto LABEL_84;
        case 36:
          v22 = 610;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 37:
          v22 = 613;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 38:
          v23 = (void *)*(yyvsp - 2);
          v22 = 612;
          v21 = *yyvsp;
          v20 = 147;
          goto LABEL_84;
        case 40:
          v22 = 608;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 41:
          v22 = 609;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 43:
          v23 = (void *)*(yyvsp - 2);
          v22 = 599;
          v21 = *yyvsp;
          v20 = 147;
          goto LABEL_84;
        case 45:
          v22 = 601;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 47:
          v22 = 600;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 49:
          v23 = (void *)*(yyvsp - 2);
          v22 = 614;
          v21 = *yyvsp;
          v20 = 147;
          goto LABEL_84;
        case 51:
          v22 = 615;
          v21 = *yyvsp;
          v20 = 147;
          v19 = (void *)*(yyvsp - 2);
          goto LABEL_85;
        case 53:
          v86 = (void *)*(yyvsp - 2);
          v30 = *yyvsp;
          v29 = sub_40CA20(*yyvsp);
          v28 = 368;
          v27 = v86;
          v26 = sub_40CA20(v86) + 2;
          v25 = 370;
          v24 = (void *)*(yyvsp - 4);
          goto LABEL_104;
        case 55:
          v22 = 561;
          v21 = *yyvsp;
          v20 = 147;
          v23 = (void *)expression_handler(*(yyvsp - 2), yyvs - 48);
          goto LABEL_84;
        case 56:
          v87 = *(yyvsp - 1);
          v88 = *yyvsp;
          v89 = (void *)expression_handler(*(yyvsp - 2), yyvs - 48);
          v90 = resize_mem(v89, 147, 32);
          v91 = realloc_mem((void *)v90, 147);
          v92 = more_mem(v91, (void *)v88);
          yyval = resize_mem((void *)v92, v87, 561);
          goto LABEL_135;
        case 57:
          yyval = 596;
          goto LABEL_135;
        case 58:
          yyval = 597;
          goto LABEL_135;
        case 59:
          yyval = 598;
          goto LABEL_135;
        case 60:
          yyval = 594;
          goto LABEL_135;
        case 61:
          yyval = 595;
          goto LABEL_135;
        case 62:
          yyval = 592;
          goto LABEL_135;
        case 63:
          yyval = 593;
          goto LABEL_135;
        case 64:
          yyval = 599;
          goto LABEL_135;
        case 65:
          yyval = 601;
          goto LABEL_135;
        case 66:
          yyval = 600;
          goto LABEL_135;
        case 68:
          v31 = *yyvsp;
          goto LABEL_97;
        case 70:
          v93 = *(yyvsp - 1);
          dword_45B548 = 0;
          yyval = v93;
          goto LABEL_135;
        case 74:
          yyval = more_mem(*(yyvsp - 2), (void *)*yyvsp);
          goto LABEL_135;
        case 75:
          sub_40C8C0(*yyvsp, dword_45B548, yyvs);
          yyval = 0;
          goto LABEL_135;
        case 76:
          v32 = yyvs - 48;
          sub_40C8C0(*(yyvsp - 2), dword_45B548 | 0x10, yyvs - 48);
          v22 = 561;
          v21 = *yyvsp;
          v20 = 147;
          v33 = *(yyvsp - 2);
          if ( *(DWORD *)(*(yyvsp - 2) + 16) )
          {
            v94 = (void *)handle_symbol(v33, v32);
            v95 = realloc_mem(v94, 147);
            v96 = more_mem(v95, (void *)v21);
            v97 = realloc_mem((void *)v96, 561);
            Memory = (void *)more_mem((int)Memory, (void *)v97);
            yyval = 0;
          }
          else
          {
            v23 = (void *)handle_symbol(v33, v32);
LABEL_84:
            v19 = v23;
LABEL_85:
            v98 = realloc_mem(v19, v20);
            v99 = more_mem(v98, (void *)v21);
            yyval = realloc_mem((void *)v99, v22);
          }
          goto LABEL_135;
        case 77:
          dword_45B548 |=1;
          goto LABEL_135;
        case 78:
          dword_45B548 |= 2;
          goto LABEL_135;
        case 79:
          dword_45B548 |= 8;
          goto LABEL_135;
        case 80:
          dword_45B548 |= 4;
          goto LABEL_135;
        case 5:
        case 83:
        case 86:
          yyval = *yyvsp;
          goto LABEL_135;
        case 14:
        case 67:
        case 69:
        case 81:
        case 84:
        case 90:
          yyval = *yyvsp;
          goto LABEL_135;
        case 91:
          sub_40C4F0(0);
          goto LABEL_135;
        case 92:
          yyval = sub_40C530((void *)*yyvsp, 0);
          goto LABEL_135;
        case 11:
        case 94:
          yyval = *(yyvsp - 1);
          goto LABEL_135;
        case 95:
          yyval = *(yyvsp - 1);
          goto LABEL_135;
        case 96:
          v31 = *(yyvsp - 1);
LABEL_97:
          yyval = more_mem(*(yyvsp - 2), (void *)v31);
          goto LABEL_135;
        case 98:
          yyval = more_mem(*(yyvsp - 1), (void *)*yyvsp);
          goto LABEL_135;
        case 100:
          yyval = more_mem(*(yyvsp - 1), (void *)*yyvsp);
          goto LABEL_135;
        case 10:
        case 93:
        case 101:
          yyval = 0;
          goto LABEL_135;
        case 4:
        case 102:
          yyval = *(yyvsp - 1);
          goto LABEL_135;
        case 103:
          v104 = *yyvsp;
          v105 = sub_40CA20(*yyvsp);
          v106 = resize_mem((void *)*(yyvsp - 2), 370, v105);
          yyval = more_mem(v106, (void *)v104);
          goto LABEL_135;
        case 104:
          v107 = (void *)*(yyvsp - 2);
          v30 = *yyvsp;
          v29 = sub_40CA20(*yyvsp);
          v28 = 368;
          v27 = v107;
          v26 = sub_40CA20(v107) + 2;
          v25 = 370;
          v24 = (void *)*(yyvsp - 4);
LABEL_104:
          v108 = resize_mem(v24, v25, v26);
          v109 = more_mem(v108, v27);
          v110 = resize_mem((void *)v109, v28, v29);
          yyval = more_mem(v110, (void *)v30);
          goto LABEL_135;
        case 106:
          yyval = sub_40C800(0, 0, *(yyvsp - 2), 0, *yyvsp);
          goto LABEL_135;
        case 107:
          yyval = sub_40C800(1, 0, *(yyvsp - 2), 0, *(yyvsp - 5));
          goto LABEL_135;
        case 108:
          v35 = *yyvsp;
          v34 = 0;
          goto LABEL_109;
        case 109:
          v35 = *yyvsp;
          v34 = *(yyvsp - 2);
LABEL_109:
          yyval = sub_40C800(0, 0, 0, v34, v35);
          goto LABEL_135;
        case 110:
          v36 = *(yyvsp - 3);
          v38 = *yyvsp;
          v37 = 0;
          goto LABEL_112;
        case 111:
          v36 = *(yyvsp - 4);
          v38 = *yyvsp;
          v37 = *(yyvsp - 2);
LABEL_112:
          yyval = sub_40C800(0, 0, v36, v37, v38);
          goto LABEL_135;
        case 112:
          yyval = sub_40C800(0, (void *)*(yyvsp - 4), 0, 0, *yyvsp);
          goto LABEL_135;
        case 113:
          v41 = *yyvsp;
          v40 = *(yyvsp - 2);
          v39 = 0;
          goto LABEL_116;
        case 114:
          v41 = *yyvsp;
          v40 = 0;
          v39 = *(yyvsp - 3);
LABEL_116:
          yyval = sub_40C800(0, (void *)*(yyvsp - 5), v39, v40, v41);
          goto LABEL_135;
        case 115:
          yyval = sub_40C800(0, (void *)*(yyvsp - 6), *(yyvsp - 4), *(yyvsp - 2), *yyvsp);
          goto LABEL_135;
        case 116:
          sub_40C4F0(2);
          goto LABEL_135;
        case 18:
        case 82:
        case 85:
        case 117:
          yyval = *yyvsp;
          goto LABEL_135;
        case 119:
          v44 = 0;
          v43 = 2545;
          v42 = yyvs - 24;
          goto LABEL_122;
        case 120:
          v44 = 0;
          v43 = 2544;
          v42 = yyvs - 24;
LABEL_122:
          v111 = sub_40C680(2, v42);
          v112 = resize_mem(0, 3473, v111 << 16);
          yyval = resize_mem((void *)v112, v43, v44);
          goto LABEL_135;
        case 121:
          v113 = sub_40C680(1, yyvs - 24);
          v114 = resize_mem(0, 3473, v113 << 16);
          yyval = realloc_mem((void *)v114, 130);
          goto LABEL_135;
        case 122:
          v115 = sub_40C680(1, yyvs - 48);
          v116 = resize_mem((void *)*(yyvsp - 1), 3473, v115 << 16);
          yyval = realloc_mem((void *)v116, 130);
          goto LABEL_135;
        case 128:
          dword_45B548 = 0;
          goto LABEL_135;
        case 129:
          v117 = sub_40CA20(dword_45B5B4);
          sub_40C480(*(DWORD *)(*(yyvsp - 1) + 20), (v117 + 2) | 0x10000000);
          v118 = sub_40C530((void *)*yyvsp, 0);
          v119 = realloc_mem((void *)v118, 130);
          dword_45B5B4 = more_mem(dword_45B5B4, (void *)v119);
          v120 = dword_45B548;
          v45 = *(yyvsp - 1);
          v120 = (BYTE)dword_45B548 | 0x30;
          v47 = yyvs - 24;
          v46 = v120;
          goto LABEL_134;
        case 130:
          sub_40C530(0, 0);
          goto LABEL_135;
        case 131:
          sub_40C530(0, 0);
          v121 = yyvs - 72;
          sub_40C8C0(*(yyvsp - 3), 48, yyvs - 72);
          v122 = (void *)*(yyvsp - 1);
          v123 = (void *)handle_symbol(*(yyvsp - 3), v121);
          v124 = realloc_mem(v123, 147);
          v125 = more_mem(v124, v122);
          v126 = realloc_mem((void *)v125, 561);
          Memory = (void *)more_mem((int)Memory, (void *)v126);
          goto LABEL_135;
        case 132:
          sub_40C8C0(*(yyvsp - 1), dword_45B548 | 0x20, yyvs - 24);
          sub_40C4F0(1);
          goto LABEL_135;
        case 133:
          yyval = *(yyvsp - 3);
          goto LABEL_135;
        case 138:
          v48 = yyvs;
          goto LABEL_133;
        case 139:
          v48 = yyvs - 24;
LABEL_133:
          v45 = *yyvsp;
          v47 = v48;
          v46 = dword_45B548;
LABEL_134:
          sub_40C8C0(v45, v46, v47);
          goto LABEL_135;
        default:
LABEL_135:
          v51 = yyssp + -2 * yylen;
          yyssp += -2 * yylen;
          v127 = yyvs;
          yyvsp = (int *)((char *)yyvsp + 4 - 4 * yylen);
          *yyvsp = yyval;
          v49 = 24 * yylen;
          v50 = 24 - 24 * yylen + v127;
          yyvs = v50;
          if ( yylen )
          {
            *(DWORD *)(v50 + 12) = *(DWORD *)(v49 + v50 - 12);
            *(DWORD *)(v50 + 16) = *(DWORD *)(v49 + v50 - 8);
          }
          else
          {
            *(DWORD *)(v50 + 4) = dword_45B464;
            *(DWORD *)(v50 + 8) = dword_45B468;
            *(DWORD *)(v50 + 12) = *(DWORD *)(v50 - 12);
            *(DWORD *)(v50 + 16) = *(DWORD *)(v50 - 8);
            *(DWORD *)(v50 + 20) = yylen;
          }
          v53 = yyr1[yyn];
          v128 = yypgoto[v53];
          v129 = *(WORD *)v51;
          v130 = v129 + v128 < 0;
          v52 = v129 + v128;
          if ( v130 || v52 > 588 || yycheck[v52] != *(WORD *)v51 )
          {
            yystate = yydefgoto[v53];
            yyn = yydefgoto[v53];
          }
          else
          {
            yystate = yytable[v52];
            yyn = yytable[v52];
          }
          continue;
        case 3:
          yyvs_offset = yyvs;
          errstr_p = "invalid key description";
          break;
        case 87:
          yyvs_offset = yyvs - 48;
          errstr_p = "labels not supported";
          break;
        case 88:
          yyvs_offset = yyvs - 72;
          errstr_p = "case keyword not supported";
          break;
        case 89:
          yyvs_offset = yyvs - 48;
          errstr_p = "default keyword not supported";
          break;
        case 105:
          yyvs_offset = yyvs - 96;
          errstr_p = "switch keyword not supported";
          break;
        case 118:
          yyvs_offset = yyvs - 48;
          errstr_p = "goto keyword not supported";
          break;
      }
      error_message(errstr_p, yyvs_offset);
      return 1;
    }
    _yyn = yytable[yyn_];
    if ( _yyn < 0 )
      break;
    if ( !_yyn )
      goto yyerrlab;
    if ( _yyn == 253 )
      return 0;
    if ( yychar_ )
      yychar = -2;
    ++yyvsp;
    v_yyvs = (void *)(yyvs + 24);
    *yyvsp = keyword_pointer;
    _yyerrstatus = yyerrstatus;
    yyvs = (int)v_yyvs;
    c_yyerrstatus = yyerrstatus == 0;
    memcpy(v_yyvs, &tmp_yyvs, 0x18u);
    if ( !c_yyerrstatus )
      yyerrstatus = _yyerrstatus - 1;
    yystate = _yyn;
    yyn = _yyn;
  }
  if ( _yyn != -32768 )
  {
    v71 = -_yyn;
    yyn = v71;
    yyn___ = v71;
    goto yyreduce;
  }
yyerrlab:
  if ( !yyerrstatus )
  {
    ++yynerrs;
    yyerror("parse error");
    yychar_ = yychar;
  }
  if ( yyerrstatus == 3 )
  {
    if ( yychar_ )
    {
      yychar = -2;
      goto yyerrlab1;
    }
    return 1;
  }
yyerrlab1:
  yyerrstatus = 3;
  __yyssp = yyssp;
  while ( 1 )
  {
    v_yyn = yypact[yystate];
    if ( v_yyn == -32768 || (_v_yyn = v_yyn + 1, _v_yyn < 0) || _v_yyn > 588 || yycheck[_v_yyn] != 1 )
      goto yyerrpop;
    yyn_2 = yytable[_v_yyn];
    if ( yyn_2 >= 0 )
      break;
    if ( yyn_2 != -32768 )
    {
      yyn_3 = -yyn_2;
      yyn = yyn_3;
      yyn___ = yyn_3;
      goto yyreduce;
    }
yyerrpop:
    if ( __yyssp == _yyss )
      return 1;
    --yyvsp;
    yystate = *(WORD *)(__yyssp - 2);
    __yyssp -= 2;
    yyssp = __yyssp;
    yyvs -= 24;
  }
  if ( !yyn_2 )
    goto yyerrpop;
  if ( yyn_2 != 253 )
  {
    ++yyvsp;
    _yyvs = (void *)(yyvs + 24);
    yyvs += 24;
    *yyvsp = keyword_pointer;
    memcpy(_yyvs, &tmp_yyvs, 0x18u);
    yyn = yyn_2;
    yystate = yyn_2;
    goto yynewstate;
  }
  return 0;
}

extern int dword_429C9C,dword_429CA0,dword_429CA8,dword_429CA4;
extern int dword_429CAC;
int dword_45B5B8=0;
int dword_45B5D8,dword_45B5C0,dword_45B5C8,dword_45B5E0,dword_45B5B8;
int unk_45B560[1000];
int pointer=0;
int dword_45B5D0,dword_45B5DC=&pointer,dword_45B600;
int dword_45B608=0;

int yyerror(int a1)
{
  int result; // eax@1

  result = dword_45B5B8;
  if ( !dword_45B5B8 )
  {
    dword_45B5D8 = dword_429C9C;
    dword_45B5C0 = dword_429CA0;
    dword_45B5C8 = dword_429CA8;
    result = 0;
    dword_45B5E0 = dword_429CA4;
    dword_45B5B8 = 1;
    strcpy((char *)&unk_45B560, (const char *)a1);
  }
  return result;
}

int error_message(int a1, int a2)
{
  int result; // eax@1
  signed int v3; // ecx@2
  int v4; // edi@2
  char v5; // zf@4
  unsigned int v6; // ecx@6

  result = dword_45B5B8;
  if ( !dword_45B5B8 )
  {
    v4 = a1;
    dword_45B5D8 = *(DWORD *)(a2 + 4);
    dword_45B5C0 = *(DWORD *)(a2 + 8);
    dword_45B5E0 = *(DWORD *)(a2 + 12);
    v3 = -1;
    dword_45B5C8 = *(DWORD *)(a2 + 16);
    dword_45B5B8 = 1;
    do
    {
      if ( !v3 )
        break;
      v5 = *(BYTE *)v4++ == 0;
      --v3;
    }
    while ( !v5 );
    v6 = ~v3;
    result = v6;
    memcpy(&unk_45B560, (const void *)(v4 - v6), v6);
  }
  return result;
}

int sub_40C480(int a1, int a2)
{
  int result; // eax@1
  int v3; // eax@1
  int v4; // eax@1
  int v5; // eax@1

  v3 = resize_mem(Memory, 272, a1 | 0x20000000);
  Memory = (void *)v3;
  v4 = realloc_mem((void *)v3, 147);
  Memory = (void *)v4;
  v5 = resize_mem((void *)v4, 272, a2);
  Memory = (void *)v5;
  result = realloc_mem((void *)v5, 561);
  Memory = (void *)result;
  return result;
}

int sub_40C680(int a1, int a2)
{
  int v2; // eax@1
  int result; // eax@4

  v2 = dword_45B5DC;
  if ( dword_45B5DC < (unsigned int)&dword_45B600 )
  {
LABEL_4:
    error_message((int)"you must be in a loop to use this", a2);
    result = 0;
  }
  else
  {
    while ( !(a1 & *(DWORD *)(v2 + 4)) )
    {
      v2 -= 12;
      if ( v2 < (unsigned int)&dword_45B600 )
        goto LABEL_4;
    }
    result = *(DWORD *)v2;
  }
  return result;
}
int  sub_40CA20(int a1)
{
  int result; // eax@1
  result = a1;
  if ( a1 )
    result = *(DWORD *)a1;
  return result;
}


int sub_40C800(int a1, void *Memory, int a3, int a4, int a5)
{
  void *v5; // eax@1
  int v6; // ebx@1
  int v7; // ebp@1
  int v8; // edi@1
  int v9; // esi@1
  int v10; // esi@3
  int v12; // eax@6
  int v13; // eax@7
  int v14; // eax@7
  int v15; // eax@7

  v8 = a3;
  v6 = sub_40CA20(a3);
  v9 = sub_40CA20(a4);
  v7 = sub_40CA20(a5);
  v5 = Memory;
  if ( v8 )
    v6 += 2;
  v10 = v9 + 2;
  if ( v8 )
  {
    if ( a1 )
      v5 = (void *)resize_mem(Memory, 368, v6);
    v12 = more_mem((int)v5, (void *)v8);
    v5 = (void *)resize_mem((void *)v12, 370, v7 + v10);
  }
  v13 = more_mem((int)v5, (void *)a5);
  v14 = sub_40C530((void *)v13, v10);
  v15 = more_mem(v14, (void *)a4);
  return resize_mem((void *)v15, 368, -(v6 + v10 + v7));
}


int sub_40C530(void *Memory, int a2)
{
  void *v2; // esi@1
  int v3; // edx@4
  int v4; // ebx@4
  int v5; // eax@5
  int v6; // ecx@6
  __int16 v7; // di@8
  int v8; // ecx@12
  int v9; // eax@13
  int v10; // edx@13
  int v11; // edi@13
  int v13; // eax@3
  int v14; // eax@3
  int v15; // eax@3
  int v16; // eax@3
  int v17; // ecx@9
  int v18; // ebx@18

  v2 = Memory;
  if ( Memory )
  {
    if ( *(DWORD *)(dword_45B5DC + 8) )
    {
      v13 = realloc_mem(0, 400);
      v14 = realloc_mem((void *)v13, *(DWORD *)(dword_45B5DC + 8));
      v15 = more_mem(v14, v2);
      v16 = realloc_mem((void *)v15, 400);
      v2 = (void *)realloc_mem((void *)v16, -*(DWORD *)(dword_45B5DC + 8));
    }
    v3 = *(DWORD *)v2;
    v4 = 0;
    if ( *(DWORD *)v2 > 0 )
    {
      v5 = (int)((char *)v2 + 12);
      do
      {
        v6 = *(DWORD *)(v5 - 4);
        if ( (v6) & 4 )
        {
          if ( v4 + 1 < v3 )
          {
            v7 = *(WORD *)v5;
            if ( (signed __int16)(*(DWORD *)v5 >> 16) == *(DWORD *)dword_45B5DC )
            {
              (v17) = (v6) & 0xF3;
              *(DWORD *)(v5 - 4) = v17;
              *(DWORD *)v5 = v7;
            }
          }
        }
        v3 = *(DWORD *)v2;
        ++v4;
        v5 += 4;
      }
      while ( v4 < *(DWORD *)v2 );
    }
    if ( *(BYTE *)(dword_45B5DC + 4) & 2 )
    {
      v8 = 0;
      if ( *(DWORD *)v2 > 0 )
      {
        v11 = a2;
        v9 = (int)((char *)v2 + 8);
        v10 = (int)((char *)v2 + 12);
        do
        {
          if ( *(DWORD *)v9 == 2544 )
          {
            *(DWORD *)v9 = 368;
            *(DWORD *)v10 = *(DWORD *)v2 - v8 + v11 - 2;
          }
          if ( *(DWORD *)v9 == 2545 )
          {
            *(DWORD *)v9 = 368;
            *(DWORD *)v10 = *(DWORD *)v2 - v8 - 2;
          }
          v18 = *(DWORD *)v9;
          if ( (v18) & 1 )
          {
            ++v8;
            v10 += 4;
            v9 += 4;
          }
          ++v8;
          v10 += 4;
          v9 += 4;
        }
        while ( v8 < *(DWORD *)v2 );
      }
    }
  }
  if ( *(DWORD *)dword_45B5DC > 0 )
    sub_40C7A0(*(DWORD *)dword_45B5DC);
  dword_45B5DC -= 12;
  return v2;
}


int sub_40C4F0(int a1)
{
  int result; // eax@1
  int v2; // eax@1
  int v3; // ecx@1
  int v4; // ecx@1

  v2 = dword_45B5DC + 12;
  v3 = dword_45B5D0 + 1;
  dword_45B5DC += 12;
  ++dword_45B5D0;
  *(DWORD *)v2 = v3;
  result = dword_45B5DC;
  v4 = a1;
  *(DWORD *)(dword_45B5DC + 8) = 0;
  *(DWORD *)(dword_45B5DC + 4) = v4;
  return result;
}


int sub_40C8C0(int a1, int a2, int a3)
{
  char v3; // bl@1
  int v4; // ebp@1
  int v5; // esi@1
  int result; // eax@20

  v4 = a3;
  v3 = a2;
  v5 = a1;
  if ( *(DWORD *)(a1 + 4) )
  {
    if ( (a2 & 0x30) != 48 || *(DWORD *)(a1 + 12) || *(DWORD *)(a1 + 8) )
    {
      if ( (a2 & 0x30) != 32 || *(DWORD *)(a1 + 12) || *(DWORD *)(a1 + 8) )
        error_message((int)"symbol already declared before", a3);
    }
  }
  if ( !*(DWORD *)(v5 + 4) )
    *(DWORD *)(v5 + 12) = *(DWORD *)dword_45B5DC;
  if ( v3 & 0x10 )
    *(DWORD *)(v5 + 8) = 1;
  if ( v3 & 8 )
    error_message((int)"extern keyword not supported", v4);
  if ( !*(DWORD *)(v5 + 12) || v3 & 1 )
  {
    if ( v3 & 2 )
      error_message((int)"symbol cannot be both auto and static", v4);
    *(DWORD *)(v5 + 16) = 1;
  }
  result = *(DWORD *)(v5 + 4);
  if ( !result )
  {
    if ( *(DWORD *)(v5 + 16) )
    {
      *(DWORD *)(v5 + 20) = dword_45B608;
      result = dword_45B608++ + 1;
      *(DWORD *)(v5 + 4) = 1;
      return result;
    }
    *(DWORD *)(v5 + 20) = *(DWORD *)(dword_45B5DC + 8);
    result = dword_45B5DC;
    ++*(DWORD *)(dword_45B5DC + 8);
  }
  *(DWORD *)(v5 + 4) = 1;
  return result;
}


int sub_40C7A0(int a1)
{
  void *v1; // ebx@1
  void *v2; // esi@1
  signed int v3; // ebp@2
  void *v4; // edi@3

  v2 = dword_429CAC;
  v1 = 0;
  if ( dword_429CAC )
  {
    v3 = a1;
    do
    {
      v4 = v2;
      v2 = (void *)*((DWORD *)v2 + 6);
      if ( v3 == -1 || *((DWORD *)v4 + 3) == v3 )
      {
        free(*(void **)v4);
        free(v4);
        if ( v1 )
          *((DWORD *)v1 + 6) = v2;
        else
          dword_429CAC = v2;
      }
      else
      {
        v1 = v4;
      }
    }
    while ( v2 );
  }
}

int walk_stack(int a1)
{
  int result; // eax@2
  int v2; // ecx@3
  int v3; // edx@4

  if ( a1 )
  {
    result = 0;
    v2 = 0;
    if ( *(DWORD *)a1 > 0 )
    {
      v3 = a1 + 8;
      do
      {
        result = *(DWORD *)v3;
        if ( (result) & 1 )
        {
          ++v2;
          v3 += 4;
        }
        ++v2;
        v3 += 4;
      }
      while ( v2 < *(DWORD *)a1 );
    }
  }
  else
  {
    result = 0;
  }
  return result;
}

int expression_handler(int a1, int a2)
{
  int v2; // esi@1
  int result; // eax@2

  v2 = a1;
  if ( walk_stack(a1) == 32 )
  {
    --*(DWORD *)v2;
    result = v2;
  }
  else
  {
    error_message((int)"cannot modify an expression", a2);
    result = v2;
  }
  return result;
}

int more_mem(int a1, void *Memory)
{
  void *v2; // esi@1
  void *result; // eax@2
  int v4; // edi@3
  int v5; // ebp@5
  int v6; // esi@6
  int v7; // ebx@7
  signed int v8; // eax@9
  int v9; // ST04_4@10

  v2 = Memory;
  if ( Memory )
  {
    v4 = a1;
    if ( a1 )
    {
      a1 = move_mem(a1);
      v5 = 0;
      if ( *(DWORD *)v2 > 0 )
      {
        v6 = (int)((char *)v2 + 8);
        do
        {
          v7 = *(DWORD *)v6;
          v4 = realloc_mem((void *)v4, *(DWORD *)v6);
          if ( (v7) & 1 )
          {
            if ( v5 < *(DWORD *)Memory )
            {
              v8 = *(DWORD *)(v6 + 4);
              v6 += 4;
              ++v5;
              if ( (v7) & 4 )
                v9 = ((signed __int16)(v8 >> 16) << 16) | (unsigned __int16)(*(WORD *)v6 - (WORD)a1);
              else
                v9 = v8;
              v4 = realloc_mem((void *)v4, v9);
            }
          }
          ++v5;
          v6 += 4;
        }
        while ( v5 < *(DWORD *)Memory );
        v2 = Memory;
      }
      free(v2);
      result = (void *)v4;
    }
    else
    {
      result = Memory;
    }
  }
  else
  {
    result = (void *)a1;
  }
  return result;
}


int resize_mem(void *Memory, int a2, int a3)
{
  void *v3; // ebx@1
  int v4; // ebp@1
  int v5; // esi@2
  int v7; // eax@4

  v3 = Memory;
  v4 = a2;
  if ( a2 & 0x400 )
    v5 = (unsigned __int16)(a3 - move_mem(Memory)) | ((signed __int16)(a3 >> 16) << 16);
  else
    v5 = a3;
  v7 = realloc_mem(v3, v4);
  return realloc_mem((void *)v7, v5);
}

int realloc_mem(void *Memory, int a2)
{
  int *v2; // ebx@1
  int v3; // eax@3
  void *v5; // eax@2
  void *v6; // eax@4
  void *v7; // ebp@4

  v2 = Memory;
  if ( Memory )
  {
    v3 = *((DWORD *)Memory + 1);
    if ( *(DWORD *)Memory == v3 )
    {
      v6 = malloc(8 * v3 + 8);
      v7 = v6;
      *(DWORD *)v6 = *(DWORD *)v2;
      *((DWORD *)v6 + 1) = 2 * *((DWORD *)v2 + 1);
      memcpy((char *)v6 + 8, (char *)v2 + 8, 4 * *(DWORD *)v2);
      free(v2);
      v2 = v7;
    }
  }
  else
  {
    v5 = malloc(0x28u);
    v2 = v5;
    *(DWORD *)v5 = 0;
    *((DWORD *)v5 + 1) = 8;
  }
  *((DWORD *)v2 + *(DWORD *)v2++ + 2) = a2;
  return v2;
}

int handle_symbol(int a1, int a2)
{
  int result; // eax@2

  if ( *(DWORD *)(a1 + 4) )
  {
    if ( *(DWORD *)(a1 + 16) )
      result = resize_mem(0, 272, *(DWORD *)(a1 + 20) | 0x20000000);
    else
      result = resize_mem(0, 3474, (*(DWORD *)(a1 + 12) << 16) | (unsigned __int16)*(DWORD *)(a1 + 20));
  }
  else
  {
    error_message((int)"undeclared symbol", a2);
    result = 0;
  }
  return result;
}


int _yy_memcpy(int a1, int a2, int a3)
{
  int result; // eax@1
  int v4; // ecx@2
  int v5; // esi@2

  result = a1;
  if ( a3 > 0 )
  {
    v4 = a2 - a1;
    v5 = a3;
    do
    {
      *(BYTE *)(result + v4) = *(BYTE *)result;
      ++result;
      --v5;
    }
    while ( v5 );
  }
  return result;
}


int move_mem(int a1)
{
  int result; // eax@1
  int v2; // edx@3
  int v3; // edi@4
  int v4; // esi@4
  signed int v5; // ecx@5

  result = 0;
  if ( a1 )
  {
    v2 = 0;
    if ( *(DWORD *)a1 > 0 )
    {
      v3 = a1 + 12;
      v4 = a1 + 8;
      do
      {
        v5 = *(DWORD *)v4;
        if ( *(DWORD *)v4 == 400 )
        {
          result += *(DWORD *)v3;
        }
        else
        {
          if ( v5 == 147 )
          {
            ++result;
          }
          else
          {
            if ( (v5) & 2 )
              --result;
          }
        }
        if ( (v5) & 1 )
        {
          ++v2;
          v4 += 4;
          v3 += 4;
        }
        ++v2;
        v4 += 4;
        v3 += 4;
      }
      while ( v2 < *(DWORD *)a1 );
    }
  }
  return result;
}
