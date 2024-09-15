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
    0,    1,    2,    2,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    6,    6,    7,    7,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    8,
    8,    9,    4,    4,
};
static const YYINT yylen[] = {                            2,
    5,    5,    0,    2,    4,    7,    5,    5,    8,    6,
    9,    7,    3,    2,    0,    5,    0,    2,    3,    3,
    3,    3,    3,    2,    3,    4,    1,    1,    1,    1,
    2,    2,    1,    4,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    3,    1,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    4,    0,    0,   30,
   28,    0,    0,   27,    0,   29,    2,    0,    0,   14,
    0,    0,    0,    0,    0,    0,   30,    0,    0,    3,
    0,    0,    0,    0,    0,    3,    0,   13,    0,    0,
    0,    0,    0,   25,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   34,    5,   26,    0,    0,    7,
    8,    0,    0,    0,    3,    0,    0,   10,    0,    3,
    0,    6,    0,   12,    0,    9,    0,   16,   11,
};
static const YYINT yydgoto[] = {                          1,
    5,    8,   17,   24,   25,   69,   76,   26,    0,
};
static const YYINT yysindex[] = {                         0,
 -262,  -41, -264, -244,   -5,    0,    0, -134,  -37, -249,
  -37, -231,  -40, -219, -216,  -26,    0, -214,  -24,    0,
    0,  -34,  -37,    0,  -33,    0,    0,   12, -200,    0,
   47,   35,   37, -202,  -37, -211,    0,  -22,  129,    0,
  -37,  -37,  -37,  -37,  -37,    0,  -37,    0, -207, -203,
   -7,   73,   46,    0, -122,  -22,  -22,  136,  136,  136,
  -52,   80,   50,   52,    0,    0,    0,  -37, -177,    0,
    0,   39,  -58,  -16,    0,   40, -191,    0,   49,    0,
 -110,    0,  -57,    0, -122,    0,   53,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -171,    0,    0,   -9,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   -6,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -46,   -1,    2,    5,    7,   10,
    0,    0,    0,    0,    0,    0,    0,    0,   54,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   62,    0,    0,    0,  -46,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  -21,   34,    0,   15,   60,   41,    0,    0,    0,
};
#define YYTABLESIZE 276
static const YYINT yytable[] = {                         23,
   78,   86,   23,   45,   22,   23,   70,   22,   44,   41,
   22,   42,   15,   43,   45,   36,    2,    3,   30,   44,
   45,    4,   18,    6,   43,   44,   41,   33,   42,   27,
   43,   33,   33,   33,   24,   33,   24,   33,   24,   19,
    7,   19,   20,   19,   20,   21,   20,   22,   45,   33,
   23,   79,   24,   44,   41,   29,   42,   19,   43,   32,
   20,   87,   33,   21,   34,   22,   34,   35,   23,   18,
   28,   47,   31,   55,   49,   18,   50,   51,   53,   61,
   63,   38,   39,   45,   64,   65,   67,   75,   44,   41,
   72,   42,   73,   43,   52,   18,   77,   83,   82,   18,
   56,   57,   58,   59,   60,   48,   62,   84,   81,   45,
   33,   89,   17,   85,   44,   41,   45,   42,    0,   43,
   18,   44,   41,    9,   42,   88,   43,   74,   10,    0,
    0,   66,    0,    0,   11,    9,    0,    0,   71,   12,
   13,    0,   14,   15,   16,    0,   11,    9,   68,    0,
    0,   12,   13,    0,   14,   15,   16,    0,   11,    0,
    0,    0,    0,   12,   13,   45,   14,   15,   16,   54,
   44,   41,   45,   42,    0,   43,    0,   44,   41,    0,
   42,    0,   43,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    9,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   11,    0,   15,    0,
    0,   12,   13,    0,   14,   15,   16,    4,    4,    0,
    0,    0,   40,    0,    0,    0,    0,    0,   19,   20,
   21,   19,   20,   21,   19,   37,   21,   33,    0,   80,
   24,    0,    0,    0,    0,   19,   33,    0,   20,   24,
    0,   21,    0,   22,   19,    0,   23,   20,   46,    0,
   21,    0,   22,    0,    0,   23,
};
static const YYINT yycheck[] = {                         40,
   59,   59,   40,   37,   45,   40,   59,   45,   42,   43,
   45,   45,   59,   47,   37,   40,  279,   59,   59,   42,
   37,  286,    8,  268,   47,   42,   43,   37,   45,  279,
   47,   41,   42,   43,   41,   45,   43,   47,   45,   41,
   46,   43,   41,   45,   43,   41,   45,   41,   37,   59,
   41,   73,   59,   42,   43,  287,   45,   59,   47,  279,
   59,   83,  279,   59,   91,   59,   91,  282,   59,   55,
   11,  272,   13,   40,   40,   61,   40,  280,  290,   46,
  288,   22,   23,   37,  288,   93,   41,  265,   42,   43,
   41,   45,   41,   47,   35,   81,   58,  289,   59,   85,
   41,   42,   43,   44,   45,   59,   47,   59,   75,   37,
  282,   59,   59,   80,   42,   43,   37,   45,   -1,   47,
   59,   42,   43,  258,   45,   85,   47,   68,  263,   -1,
   -1,   59,   -1,   -1,  269,  258,   -1,   -1,   59,  274,
  275,   -1,  277,  278,  279,   -1,  269,  258,  271,   -1,
   -1,  274,  275,   -1,  277,  278,  279,   -1,  269,   -1,
   -1,   -1,   -1,  274,  275,   37,  277,  278,  279,   41,
   42,   43,   37,   45,   -1,   47,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
#define YYUNDFTOKEN 302
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
0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : PROGRAM",
"PROGRAM : PROGRAM ID ';' block '.'",
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
#line 319 "y.tab.c"

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
	{ 

}
break;
case 2:
#line 52 "atl.y"
	{
 
}
break;
#line 533 "y.tab.c"
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
