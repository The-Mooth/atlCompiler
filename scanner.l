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
%}



%%

//user code section