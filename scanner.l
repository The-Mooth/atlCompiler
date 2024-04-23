%{
//definitions section

#include "definitions.h"
#include "globals.h"

//token definitions from yacc
#include "y.tab.h"
%}

%option nounput

%x COMMENT


DIGIT   [0-9]
ID      [a-z][a-z0-9]*
WHITESPACE [ \t]+

%%

%{
//rules section
//should go smallest to largest, since lex finds biggest match first

//keywords first?
//no, comments
/*
*/
%}

{WHITESPACE}

"/*" BEGIN COMMENT;
<COMMENT>"*/" BEGIN 0;
<COMMENT>\n {line_no++}
<COMMENT>. {/*in comment: do nothing*/}


\"(\\.|[^"\\]|[^\"])*\" {yylval.s_val = strdup(yytext)}


{ID} return ID;

{DIGIT}+ return NUMBER;


{WHITESPACE} printf("hello");




. yyerror("Unrecognized Token: %s", yytext);//does yyerror take formatted arguments?

%%

//user code section

#ifdef TESTSCAN


#endif