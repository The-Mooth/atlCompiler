/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 3 "atl.y"
#include "definitions.h"
#include "globals.h"

#line 12 "atl.y"
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
#line 40 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

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
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    1,    0,    2,    3,    3,    4,    4,    4,    4,    4,
    4,    4,    4,    4,    4,    7,    7,    8,    8,    6,
    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
    9,    9,   10,    5,    5,
};
static const YYINT yylen[] = {                            2,
    0,    6,    5,    0,    2,    4,    7,    5,    5,    8,
    6,    9,    7,    3,    2,    0,    5,    0,    2,    3,
    3,    3,    3,    3,    2,    3,    4,    1,    1,    1,
    1,    2,    2,    1,    4,
};
static const YYINT yydefred[] = {                         0,
    0,    1,    0,    0,    0,    0,    4,    2,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    5,    0,    0,
   31,   29,    0,    0,   28,    0,   30,    3,    0,    0,
   15,    0,    0,    0,    0,    0,    0,   31,    0,    0,
    4,    0,    0,    0,    0,    0,    4,    0,   14,    0,
    0,    0,    0,    0,   26,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   35,    6,   27,    0,    0,
    8,    9,    0,    0,    0,    4,    0,    0,   11,    0,
    4,    0,    7,    0,   13,    0,   10,    0,   17,   12,
};
static const YYINT yydgoto[] = {                          1,
    3,    6,    9,   18,   25,   26,   70,   77,   27,    0,
};
static const YYINT yysindex[] = {                         0,
 -262,    0,  -41, -264, -245,  -22,    0,    0, -141,  -37,
 -238,  -37, -235,  -40, -223, -219,  -20,    0, -202,  -24,
    0,    0,  -34,  -37,    0,  -33,    0,    0,   12, -188,
    0,   64,   45,   46, -191,  -37, -200,    0,  -17,   36,
    0,  -37,  -37,  -37,  -37,  -37,    0,  -37,    0, -197,
 -190,    9,   71,   59,    0, -127,  -17,  -17,  124,  124,
  124,  -52,   82,   62,   63,    0,    0,    0,  -37, -153,
    0,    0,   57,  -58,  -16,    0,   67, -168,    0,   73,
    0, -115,    0,  -57,    0, -127,    0,   76,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -143,    0,    0,   -9,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   -6,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -46,   -1,    2,    5,    7,
   10,    0,    0,    0,    0,    0,    0,    0,    0,   81,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   86,    0,    0,    0,  -46,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,   -2,   29,    0,    6,   51,   60,    0,    0,    0,
};
#define YYTABLESIZE 276
static const YYINT yytable[] = {                         24,
   79,   87,   24,   46,   23,   24,   71,   23,   45,   42,
   23,   43,   16,   44,   19,   37,    2,    4,   31,   46,
   46,    5,    7,    8,   45,   45,   42,   34,   43,   44,
   44,   34,   34,   34,   25,   34,   25,   34,   25,   20,
   28,   20,   21,   20,   21,   22,   21,   23,   46,   34,
   24,   30,   25,   45,   42,   33,   43,   20,   44,   34,
   21,   19,   29,   22,   32,   23,   35,   19,   24,   56,
   35,   80,   46,   39,   40,   62,   55,   45,   42,   36,
   43,   88,   44,   48,   50,   51,   53,   19,   52,   54,
   64,   19,   57,   58,   59,   60,   61,   65,   63,   68,
   46,   66,   73,   74,   82,   45,   42,   46,   43,   86,
   44,   76,   45,   42,   78,   43,   10,   44,   46,   75,
   84,   11,   49,   45,   42,   83,   43,   12,   44,   67,
   10,   85,   13,   14,   90,   15,   16,   17,   34,   18,
   72,   12,   10,   69,   19,   89,   13,   14,    0,   15,
   16,   17,    0,   12,    0,    0,    0,    0,   13,   14,
   46,   15,   16,   17,    0,   45,   42,    0,   43,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   10,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   12,    0,   16,    0,
    0,   13,   14,    0,   15,   16,   17,    5,    5,    0,
    0,    0,   41,    0,    0,    0,    0,    0,   20,   21,
   22,   20,   21,   22,   20,   38,   22,   34,    0,   81,
   25,    0,    0,    0,    0,   20,   34,    0,   21,   25,
    0,   22,    0,   23,   20,    0,   24,   21,   47,    0,
   22,    0,   23,    0,    0,   24,
};
static const YYINT yycheck[] = {                         40,
   59,   59,   40,   37,   45,   40,   59,   45,   42,   43,
   45,   45,   59,   47,    9,   40,  279,   59,   59,   37,
   37,  286,  268,   46,   42,   42,   43,   37,   45,   47,
   47,   41,   42,   43,   41,   45,   43,   47,   45,   41,
  279,   43,   41,   45,   43,   41,   45,   41,   37,   59,
   41,  287,   59,   42,   43,  279,   45,   59,   47,  279,
   59,   56,   12,   59,   14,   59,   91,   62,   59,   41,
   91,   74,   37,   23,   24,   47,   41,   42,   43,  282,
   45,   84,   47,  272,   40,   40,   36,   82,  280,  290,
  288,   86,   42,   43,   44,   45,   46,  288,   48,   41,
   37,   93,   41,   41,   76,   42,   43,   37,   45,   81,
   47,  265,   42,   43,   58,   45,  258,   47,   37,   69,
  289,  263,   59,   42,   43,   59,   45,  269,   47,   59,
  258,   59,  274,  275,   59,  277,  278,  279,  282,   59,
   59,  269,  258,  271,   59,   86,  274,  275,   -1,  277,
  278,  279,   -1,  269,   -1,   -1,   -1,   -1,  274,  275,
   37,  277,  278,  279,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  258,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  269,   -1,  265,   -1,
   -1,  274,  275,   -1,  277,  278,  279,  286,  286,   -1,
   -1,   -1,  266,   -1,   -1,   -1,   -1,   -1,  279,  280,
  281,  279,  280,  281,  279,  280,  281,  257,   -1,  266,
  257,   -1,   -1,   -1,   -1,  257,  266,   -1,  257,  266,
   -1,  257,   -1,  257,  266,   -1,  257,  266,  257,   -1,
  266,   -1,  266,   -1,   -1,  266,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 290
#define YYUNDFTOKEN 303
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,"'('","')'","'*'","'+'",0,"'-'","'.'","'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'['",
0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"DO","IF","IS","OF","OR","AND","END","NOT","ELSE","THEN","TYPE",
"YYBEGIN","WHILE","ARRAY","ELIF","UNTIL","VALUE","REPEAT","RETURN","VARIABLE",
"FUNCTION","PROCEDURE","ID","NUMBER","STRING","ASSIGN","RELATION","MUL_OP",
"UMINUS","dec_list","statement","param_list","type_desc","aparam_list",0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : PROGRAM",
"$$1 :",
"PROGRAM : PROGRAM ID $$1 ';' block '.'",
"block : dec_list YYBEGIN stmt_list END ID",
"stmt_list :",
"stmt_list : stmt_list stmt",
"stmt : var ASSIGN expr ';'",
"stmt : IF expr THEN stmt_list elif_clause else_clause ';'",
"stmt : WHILE expr DO stmt_list ';'",
"stmt : REPEAT statement UNTIL expr ';'",
"stmt : FUNCTION ID '(' param_list ')' ':' type_desc ';'",
"stmt : PROCEDURE ID '(' param_list ')' ';'",
"stmt : FUNCTION ID '(' param_list ')' ':' type_desc block ';'",
"stmt : PROCEDURE ID '(' param_list ')' block ';'",
"stmt : RETURN expr ';'",
"stmt : RETURN ';'",
"elif_clause :",
"elif_clause : ELIF expr THEN stmt_list elif_clause",
"else_clause :",
"else_clause : ELSE stmt_list",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '/' expr",
"expr : expr '*' expr",
"expr : expr '%' expr",
"expr : '-' expr",
"expr : '(' expr ')'",
"expr : ID '(' aparam_list ')'",
"expr : var",
"expr : STRING",
"expr : int_const",
"int_const : NUMBER",
"int_const : '-' NUMBER",
"var_dec : VARIABLE var",
"var : ID",
"var : ID '[' NUMBER ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 115 "atl.y"
/* c code */
#line 320 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 46 "atl.y"
	{init_symtab(yystack.l_mark[-1]);}
break;
case 2:
#line 46 "atl.y"
	{ 

}
break;
case 3:
#line 52 "atl.y"
	{
 
}
break;
#line 538 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
