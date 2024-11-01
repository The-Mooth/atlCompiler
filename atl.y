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
  syntax_node_ptr syntax_node;
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
%right '='
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
%type<syntax_node> dec_list
%type<syntax_node> var_dec_list

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
stmt_list : {$$ = NULL;} 
    | stmt
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
elif_clause : {$$ = NULL;} 
    | ELIF expr THEN stmt_list elif_clause
    ;

/* */
else_clause : {$$ = NULL;} 
    | ELSE stmt_list
    ;

/* */
expr : expr '+' expr
    | expr '-' expr
    | '-' expr
    | expr MUL_OP expr
    | expr REL_OP expr
    | '(' expr ')'
    | ID '(' aparam_list ')'
    | var 
    | STRING
    | int_const
    ;

/* */
int_const : NUMBER  {$$ = $1;}
    | '-' NUMBER    {$$ = $2 * -1;}
    ;

/* */
dec_list : {$$ = NULL;}
    |   dec
    |   dec_list ',' dec
    ;

/* check that id is a type, then assign typing to var_dec_list*/
dec : var_dec_list ':' ID
    |   ID is var_dec
    ;

/* */
var_dec_list : {$$ = NULL;}
    | var_dec 
    | var_dec_list ',' var_dec
    ;


/* check for ik_type*/
var_dec : ID {/* make sure not in symtab (just cur level?), process typing later*/ }
    ;

/* check if id in symtab. if not, error.*/
var : ID  {}
  | ID '[' NUMBER ']'
  ;


  
%%

/* c code */
int is_declared(char* identifier){
    if (find_id(identifier) == -2) {
        return 0;
    }
    return 1;
}

void iterate_and_reverse (syntax_node_ptr cur, void (*operator)(syntax_node_ptr)){

    syntax_node_ptr temp = NULL;
    syntax_node_ptr prev = NULL;
    

    while(cur) {
        
        if (operator) {
            operator(cur);
        }

        temp = cur;
        cur = cur->next_node;
        temp->next_node = prev;
        prev = temp;
        cur = cur->next_node;
    }
}

