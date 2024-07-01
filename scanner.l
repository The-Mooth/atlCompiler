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
/*
*/
%}

{WHITESPACE} ;

"/*" BEGIN COMMENT;
<COMMENT>"*/" BEGIN 0;
<COMMENT>\n line_no++;
<COMMENT><<EOF>> {yyerror("UNTERMINATED COMMENT")}
<COMMENT>. {/*in comment: do nothing*/}



\"()\" {
  yylval.s_value = strdup(yytext);
  return STRING;
}






{WHITESPACE} ; //do nothing


"+"|"-"|";"|"("|")"|","|"."|":" {
	return((int)yytext[0]);
}

"*"|"%"|"/" {yylval.i_value = yytext[0]; 
  return(MUL_OP);
}

  //reserved words

(?i:do) return(DO);

(?i:if) return(IF);

(?i:is) return(IS);

(?i:of) return(OF);

(?i:or) return(OR);

(?i:and) return(AND);

(?i:end) return(END);

(?i:not) return(NOT);

(?i:else) return(ELSE);

(?i:then) return(THEN);

(?i:type) return(TYPE);

(?i:array) return(ARRAY);

(?i:begin) return(YYBEGIN);

(?i:elif) return(ELIF);

(?i:until) return(UNTIL);

(?i:value) return(VALUE);

(?i:while) return(WHILE);

(?i:repeat) return(REPEAT);

(?i:return) return(RETURN);

(?i:program) return(PROGRAM);

(?i:variable) return(VARIABLE);

(?i:function) return(FUNCTION);

(?i:procedure) return(PROCEDURE);

{ID} { yylval.s_value = strdup(yytext);
  return ID;
}

{DIGIT}+ { yylval.i_value = atoi(yytext);
  return NUMBER;
}
. yyerror("Unrecognized Token: %s", yytext);//does yyerror take formatted arguments?

%%

//user code section


//manage nested comments?


#ifdef TESTSCAN


#endif