/* declarations */
%{
#include "definitions.h"
#include "globals.h"

%}

/* union 
returntypes for $$?
this is YYLVAL
*/
%union {
  id_info_ptr id_value;
  type_desc_ptr type_value;
  int i_value;
  char* s_value;

}
/* Once YYSTYPE has been defined as a union, you may specify a particular interpretation of the union by including a statement of the form:
%type <interpretation> symbol */

/* tokens */
/* token BANK 
write read
or if  
IF IS OF OR AND END NOT ELSE THEN TYPE ARRAY YYBEGIN ElIF UNTIL VALUE WHILE REPEAT RETURN PROGRAM VARIABLE FUNCTION PROCEDURE
*/
%start PROGRAM
 
 //inventory of tokens
%token  DO IF IS OF OR AND END NOT ELSE THEN TYPE
%token YYBEGIN WHILE ARRAY ELIF UNTIL VALUE
%token REPEAT RETURN
%token VARIABLE FUNCTION PROCEDURE
%token ID NUMBER STRING
/* precedence is in ascending order */
%nonassoc ASSIGN
%nonassoc RELATION
%left '+' '-'
%left MUL_OP

%left UMINUS


/* grammar rules */
%%
PROGRAM : PROGRAM ID {init_symtab($1);}';' block '.' { 

}


/* */
block : dec_list YYBEGIN stmt_list END ID {
 
}

/* */
stmt_list : 
    | stmt_list stmt
    ;

/* */
stmt : var ASSIGN expr ';'
    | IF expr THEN stmt_list elif_clause else_clause ';'
    | WHILE expr DO stmt_list ';'
    | REPEAT statement UNTIL expr ';'
    | FUNCTION ID '(' param_list ')' ':' type_desc ';'
    | PROCEDURE ID '(' param_list ')' ';'
    | FUNCTION ID '(' param_list ')' ':' type_desc block ';'
    | PROCEDURE ID '(' param_list ')' block ';'
    | RETURN expr ';'
    | RETURN ';'
    ;

/* */
elif_clause : 
    | ELIF expr THEN stmt_list elif_clause
    ;

/* */
else_clause : 
    | ELSE stmt_list
    ;

/* */
expr : expr '+' expr
    | expr '-' expr
    | expr '/' expr
    | expr '*' expr
    | expr '%' expr
    | '-' expr
    | '(' expr ')'
    | ID '(' aparam_list ')'
    | var
    | STRING
    | int_const
    ;

/* */
int_const : NUMBER
    | '-' NUMBER
    ;

/* */
var_dec : VARIABLE var 
    ;

/* */
var : ID  
  | ID '[' NUMBER ']'
  ;


  
%%
/* c code */