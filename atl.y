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
%left MUL_OP

%left UMINUS


/* format token typing*/
%type<syntax_node> block
%type<syntax_node> stmt_list
%type<syntax_node> stmt
%type<syntax_node> elif_clause_list
%type<syntax_node> elif_clause
%type<syntax_node> else_clause
%type<syntax_node> expr
%type<i_value> int_const
%type<syntax_node> var_dec
%type<id_value> var
%type<syntax_node> type_dec_list
%type<syntax_node> var_dec_list
%type<syntax_node> aparam_list

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
PROGRAM : ID {init_symtab($1); root = make_syntax_node(PROGRAM, NULL);} block {root->data.fmt.program.block = $3;}'.' 

/* */
block : type_dec_list YYBEGIN stmt_list END ID {$$ = make_syntax_node(BLOCK, $3, $1);}

type_dec_list : {$$ = NULL;}
    | type_dec
    | type_dec_list type_dec ',' type_dec
    ;

/* check that id is a type, then assign typing to var_dec_list. ID IS ID for declaring arrays*/
type_dec : var_dec_list ':' ID {assign_typing_and_insert($1, check_descriptor($3));}
    ID IS ID
    ;

/* */
var_dec_list : var_dec {$$ = $1;}
    | var_dec_list ',' var_dec {$2->next_node = $1; $$ = $2}
    ;


/* for declaring IDs. check for ik_type*/
var_dec : ID {$$ = $1;}
    ;

/*to be reversed*/
stmt_list : {$$ = NULL;} 
    | stmt_list stmt {$2->next_node = $1; $$ = $2;}
    ;

/* whenever list returns, call reverse()?*/
stmt : var ASSIGN expr {$$ = make_syntax_node(ASSIGN, $1, $3);}
    | IF expr THEN stmt_list elif_clause_list else_clause  {$$ = make_syntax_node(IF, $2, $4, $5, $6);}
    | WHILE expr DO stmt_list  {$$ = make_syntax_node(WHILE, $2, $4);}
    | REPEAT stmt_list UNTIL expr  {$$ = make_syntax_node(REPEAT, $2, $4);}
    /*
    | FUNCTION ID '(' param_list ')' ':' type_desc  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO!
    | PROCEDURE ID '(' param_list ')'  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    | FUNCTION ID '(' param_list ')' ':' type_desc block  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    | PROCEDURE ID '(' param_list ')' block  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    */
    | RETURN expr  {$$ = make_syntax_node(RETURN, $2);}
    | RETURN  {$$ = make_syntax_node(RETURN, NULL);}
    ;


elif_clause_list : {$$ = NULL;}
    | elif_clause_list elif_clause {$2->next_node = $1; $$ = $2;}
    ;

elif_clause : ELIF expr THEN stmt_list {$$ = make_syntax_node(ELIF, $2, $4);}

else_clause : {$$ = NULL;} 
    | ELSE stmt_list {$$ = make_syntax_node(ELSE, $2);}
    ;

/* */
expr : expr '+' expr {$$ = make_syntax_node(BINARY, '+', $1, $3, NULL);}
    | expr '-' expr {$$ = make_syntax_node(BINARY, '-', $1, $3, NULL);}
    | '-' expr {$$ = make_syntax_node(UNARY);}                                      %prec UMINUS
    | expr MUL_OP expr {$$ = make_syntax_node(BINARY, $2, $1, $3, NULL);}
    | expr REL_OP expr {$$ = make_syntax_node(BINARY, $2, $1, $3, NULL);}
    | '(' expr ')' {$$ = make_syntax_node(PAREN, $2);}
    | /* ID '(' aparam_list ')' {$$ = make_syntax_node(FUNCTIONEX);}//TODO */
    | var  {$$ = make_syntax_node(SIMPLE, $1);}
    | STRING {$$ = make_syntax_node(STRING);}
    | int_const {$$ = make_syntax_node(CONS, $1);}
    //TODO: add logic operators (and, or, etc)
    ;

/* */
int_const : NUMBER  {$$ = $1;}
    | '-' NUMBER    {$$ = $2 * -1;}
    ;

/* for IDs already declared. check if id in symtab. if not, error.*/
var : ID  {id_info_ptr lookup = find_id($1); $$ = lookup ? lookup : make_id_info($1, ik_VAR, err_desc, NULL);}
  | ID '[' NUMBER ']' 
  ;


  
%%

/* c code */

type_desc_ptr check_descriptor(type_desc_ptr type) {
    id_info_ptr descriptor = find+id(type->name);

    if (!descriptor) {
        yyerror("type \"%s\" not found", type->name);
        return err_ptr;
    }

    if (!(descriptor->id == ik_type)) {
        yyerror("\"%s\" is not a type descriptor", type->name);
        return err_ptr;
    }

    return type;
}

int is_declared(char* identifier){
    if (find_id(identifier) == -2) {
        return 0;
    }
    return 1;
}

void assign_typing_and_insert(id_info_ptr cur, type_desc_ptr assignment) {
    cur->desc = assignment;
    id_info_ptr temp = cur;

    while(temp->next) {
        temp = temp->next;
        temp->desc = assignment;
    }
}

void iterate_and_reverse(syntax_node_ptr cur, void (*operator)(void*, void*), void* param1, void* param2){

    syntax_node_ptr temp = NULL;
    syntax_node_ptr prev = NULL;

    while(cur) {
        
        if (operator) {
            operator(cur, );
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
