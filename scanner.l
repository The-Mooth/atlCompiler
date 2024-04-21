%{
//definitions section

#include "definitions.h"
#include "globals.h"

//token definitions from yacc
#include "y.tab.h"


DIGIT   [0-9]
ID      [a-z][a-z0-9]*
WHITESPACE [ \t]+



%}
%option nounput
%%

%{
//rules section

{ID} ECHO 


{WHITESPACE}+ //remove whitespace


. yyerror("Unrecognized Token: %s", yytext);//does yyerror take formatted arguments?
%}



%%

//user code section

#ifdef TESTSCAN


#endif