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
<COMMENT>\n {line_no++}
<COMMENT><<EOF>> {yyerror("UNTERMINATED COMMENT")}
<COMMENT>. {/*in comment: do nothing*/}



\"()\" {
  yylval.s_val = strdup(yytext);
  return STRING;}






{WHITESPACE} ; //do nothing


"+"|"-"|";"|"("|")"|","|"."|":" {
	  return((int)yytext[0]);
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

(?i:elsif) return(ELSIF);

(?i:until) return(UNTIL);

(?i:value) return(VALUE);

(?i:while) return(WHILE);

(?i:repeat) return(REPEAT);

(?i:return) return(RETURN);

(?i:returns) return(RETURNS);

(?i:program) return(PROGRAM);

(?i:variable) return(VARIABLE);

(?i:function) return(FUNCTION);

(?i:procedure) return(PROCEDURE);

"*"|(?i:mod)|"/" return(MUL_OP);

{ID} return ID;

{DIGIT}+ return NUMBER;

. yyerror("Unrecognized Token: %s", yytext);//does yyerror take formatted arguments?

%%

//user code section

#ifdef TESTSCAN


#endif