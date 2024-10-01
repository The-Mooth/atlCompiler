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
  syntax_node_pointer syntax_node;
}
/* Once YYSTYPE has been defined as a union, you may specify a particular interpretation of the union by including a statement of the form:
%type <interpretation> symbol */

/* tokens */
/* token BANK 
write read (?)
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
%nonassoc <s_value> REL_OP 
%left '+' '-'
%left <c_value> MUL_OP

%left UMINUS

/* format token typing*/
%type<syntax_node> block
%type<syntax_node> stmt_list
%type<syntax_node> stmt
%type<syntax_node> elif_clause
%type<syntax_node> else_clause
%type<syntax_node> expr
%type<i_value> int_const
%type<syntax_node> var_dec
%type<id_value> var

/* leaf token typing*/
%type<i_value> NUMBER
%type<s_value> ID 

/* to be implemented 
%type<s_value> STRING 


*/

/* grammar rules */
%%
PROGRAM : PROGRAM ID {init_symtab($2);}';' block '.' { 

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
    | '-' expr
    | expr MUL_OP expr
    | REL_OP expr
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

ID
  
%%
/* c code */