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
 
 //inventory of tokens (remember, caps = leaf token)

/* %token program */
%token  DO IF IS OF OR AND END NOT ELSE THEN TYPE
%token YYBEGIN WHILE ARRAY ELIF UNTIL VALUE
%token REPEAT RETURN
%token VARIABLE FUNCTION PROCEDURE
%token ID NUMBER STRING
/* precedence is in ascending order */
%nonassoc ASSIGN
%right '='
%nonassoc REL_OP 
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
%type<syntax_node> type_dec_list
%type<syntax_node> var_dec_list

/* leaf token typing*/
%type<i_value> NUMBER
%type<s_value> ID
%type<i_value> REL_OP 
%type<i_value> MUL_OP

/* to be implemented 
%type<s_value> STRING 


*/

/* grammar rules */
%%
PROGRAM : PROGRAM ID {init_symtab($2); make_syntax_node(PROGRAM, NULL);} block '.' 

/* */
block : type_dec_list YYBEGIN stmt_list END ID {$$ = make_syntax_node(BLOCK, $3, $1);}

 
/* */
stmt_list : {$$ = NULL;} 
    | stmt {$$ = $1;}
    | stmt_list stmt {$2->next_node = $1;
        $$ = $2;}
    ;

/* whenever list returns, call reverse()*/
stmt : var ASSIGN expr {$$ = make_syntax_node(ASSIGN, $1, $3);}
    | IF expr THEN stmt_list elif_clause else_clause  {$$ = make_syntax_node(IF, $2, $4, $5, $6);}
    | WHILE expr DO stmt_list  {$$ = make_syntax_node(WHILE, $2, $4);}
    | REPEAT stmt_list UNTIL expr  {$$ = make_syntax_node(REPEAT, $2, $4);}
    | FUNCTION ID '(' param_list ')' ':' type_desc  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO!
    | PROCEDURE ID '(' param_list ')'  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    | FUNCTION ID '(' param_list ')' ':' type_desc block  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    | PROCEDURE ID '(' param_list ')' block  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    | RETURN expr  {$$ = make_syntax_node(RETURN, $2);}
    | RETURN  {$$ = make_syntax_node(RETURN, NULL);}
    ;

/* */
else_clause : {$$ = NULL;} 
    | ELSE stmt_list {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    ;

/* */
expr : expr '+' expr {$$ = make_syntax_node(BINARY, '+', $1, $3, NULL);}
    | expr '-' expr {$$ = make_syntax_node(BINARY, '-', $1, $3, NULL);}
    | '-' expr {$$ = make_syntax_node(UNARY);}
    | expr MUL_OP expr {$$ = make_syntax_node(BINARY, $2, $1, $3, NULL);}
    | expr REL_OP expr {$$ = make_syntax_node(BINARY, $2, $1, $3, NULL);}
    | '(' expr ')' {$$ = make_syntax_node(PAREN, $2);}
    | ID '(' aparam_list ')' {$$ = make_syntax_node(FUNCTIONEX);}//TODO
    | var  {$$ = make_syntax_node(SIMPLE, $1);}
    | STRING {$$ = make_syntax_node(STRING);}
    | int_const {$$ = make_syntax_node(CONS, $1);}
    ;

/* */
int_const : NUMBER  {$$ = $1;}
    | '-' NUMBER    {$$ = $2 * -1;}
    ;

/* */
type_dec_list : {$$ = NULL;}
    |   type_dec
    |   type_dec_list ',' type_dec
    ;

/* check that id is a type, then assign typing to var_dec_list*/
type_dec : var_dec_list ':' ID
    |   ID IS var_dec
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

int is_same_type(type_desc_ptr first, type_desc_ptr second) {
    return first == second;
}
