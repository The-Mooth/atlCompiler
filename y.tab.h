#define DO 257
#define IF 258
#define IS 259
#define OF 260
#define OR 261
#define AND 262
#define END 263
#define NOT 264
#define ELSE 265
#define THEN 266
#define TYPE 267
#define YYBEGIN 268
#define WHILE 269
#define ARRAY 270
#define ELIF 271
#define UNTIL 272
#define VALUE 273
#define REPEAT 274
#define RETURN 275
#define VARIABLE 276
#define FUNCTION 277
#define PROCEDURE 278
#define ID 279
#define NUMBER 280
#define STRING 281
#define ASSIGN 282
#define RELATION 283
#define MUL_OP 284
#define UMINUS 285
#define dec_list 286
#define statement 287
#define param_list 288
#define type_desc 289
#define aparam_list 290
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
