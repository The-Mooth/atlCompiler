#define FUNC 257
#define PROC 258
#define BEGIN 259
#define WHILE 260
#define DO 261
#define ASSIGN 262
#define EQ 263
#define GT 264
#define LT 265
#define GTE 266
#define LTE 267
#define UMINUS 268
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  id_info_ptr id_value;
  type_desc_ptr type_value;
  int i_value;
  char* s_value;

} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
