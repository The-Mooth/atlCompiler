#ifndef _yy_defines_h_
#define _yy_defines_h_

#define DO 257
#define IF 258
#define IS 259
#define END 260
#define ELSE 261
#define THEN 262
#define YYBEGIN 263
#define WHILE 264
#define ARRAY 265
#define ELIF 266
#define UNTIL 267
#define VALUE 268
#define REPEAT 269
#define RETURN 270
#define NUMBER 271
#define aparam_list 272
#define FUNCTION 273
#define PROCEDURE 274
#define STRING 275
#define STMT 276
#define ID 277
#define ASSIGN 278
#define REL_OP 279
#define MUL_OP 280
#define UMINUS 281
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union YYSTYPE {
  id_info_ptr id_value;
  type_desc_ptr type_value;
  int i_value;
  char* s_value;
  syntax_node_ptr syntax_node;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;

#endif /* _yy_defines_h_ */
