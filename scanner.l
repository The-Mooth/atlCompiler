%{
//definitions section

#include "defs.h"
#include "global.h"

//token definitions from yacc
#include "y.tab.h"


DIGIT   [0-9]
ID      [a-z][a-z0-9]*
WHITESPACE [ \t]+

%}
%option yy_no_unput
%%

%{
//rules section
%}



%%

//user code section