%{
//definitions section

#include "definitions.h"
#include "globals.h"
int handle_rel_op(char* op);
//token definitions from yacc
#include "y.tab.h"

// verbose (?) mode, print each line as it comes
int yylex(void) {
  int lex_state = yylex_internal();
  debug_printf(" Token / %s / received\n", yytext);
  return lex_state;
}
  

%}

%option nounput
%option noinput
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

"/*" BEGIN COMMENT;
<COMMENT>"*/" BEGIN 0;
<COMMENT>\n line_no++;
<COMMENT><<EOF>> {yyerror("UNTERMINATED COMMENT");}
<COMMENT>. {/*in comment: do nothing*/;}

[\n] {line_no++;}

\".*\" {
  yylval.s_value = strdup(yytext);
  return STRING;
}






{WHITESPACE} ; 


"+"|"-"|";"|"("|")"|","|"."|":" {
	return((int)yytext[0]);
}

"*"|"%"|"/" {yylval.i_value = yytext[0]; 
  return(MUL_OP);
}

"=="|">="|"<="|"<"|">" {yylval.i_value = handle_rel_op(yytext);
  return(REL_OP);
}

"->" return(ASSIGN);

(?i:do) return(DO);

(?i:if) return(IF);

(?i:is) return(IS);

(?i:end) return(END);

(?i:else) return(ELSE);

(?i:then) return(THEN);

(?i:array) return(ARRAY);

(?i:begin) return(YYBEGIN);

(?i:elif) return(ELIF);

(?i:until) return(UNTIL);

(?i:while) return(WHILE);

(?i:repeat) return(REPEAT);

(?i:return) return(RETURN);

(?i:function) return(FUNCTION);

(?i:procedure) return(PROCEDURE);

{ID} { yylval.s_value = strdup(yytext);
  return ID;
}

{DIGIT}+ { yylval.i_value = atoi(yytext);
  return NUMBER;
}


. yyerror("Unrecognized Token: %s", yytext);

%%

//user code section

int handle_rel_op(char* op){

  if (!strncmp(op, "==", 2)) {
    return 247;
  }

  if (!strncmp(op, ">=", 2)) {
    return 242;
  }

  if (!strncmp(op, "<=", 2)) {
    return 243;
  }

  return op[0];

}


#ifdef TESTSCAN


#endif