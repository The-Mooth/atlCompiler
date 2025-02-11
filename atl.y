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

%token  DO IF IS END ELSE THEN 
%token YYBEGIN WHILE ARRAY ELIF UNTIL VALUE
%token REPEAT RETURN NUMBER aparam_list
%token FUNCTION PROCEDURE
%token STRING

/* precedence is in ascending order */
%nonassoc BLOCK
%nonassoc STMT
%left IF
%left WHILE
%left REPEAT
%nonassoc RETURN
%nonassoc THEN
%nonassoc ELSE
%nonassoc ELIF

%nonassoc ID

%nonassoc NUMBER

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
%type<syntax_node> aparam_list
%type<syntax_node> r_stmt_list

%type<i_value> int_const

%type<id_value> var_dec
%type<id_value> var
%type<id_value> var_dec_list

%type<id_value> type_dec
%type<id_value> type_dec_list

/* leaf token typing*/
%type<i_value> NUMBER
%type<s_value> ID
%type<i_value> REL_OP 
%type<i_value> MUL_OP
%type<s_value> STRING

/* to be implemented 
%type<s_value> STRING 


*/

//TODO: add a r_stmt_list node
/* grammar rules */
%%
PROGRAM : ID {init_symtab($1); root = make_syntax_node(fPROGRAM, NULL);} ';' block {root->data.fmt.program.block = $4;}'.' {debug_printf("end of file reached!\n");} 

/* */
block : type_dec_list YYBEGIN r_stmt_list END ID {$$ = make_syntax_node(fBLOCK, $3, NULL, $5);} %prec BLOCK

type_dec_list : type_dec
    | type_dec_list ',' type_dec
    ;

/* check that id is a type, then assign typing to var_dec_list. ID IS ID for declaring arrays*/
type_dec : var_dec_list ':' ID {assign_typing_and_insert($1, check_descriptor($3));}
    | var_dec IS ID {$$ = make_id_info("stank", ik_VAR, NULL, NULL, 27, 27);}
    ;

/* */
var_dec_list : var_dec {$$ = $1;}
    | var_dec_list ',' var_dec {$3->next = $1; $$ = $3;}
    ;

var_dec : ID {$$ = make_id_info($1, ik_VAR, NULL, NULL, 27, 27);}
;

r_stmt_list : stmt_list {$$ = reverse($1);}

/*to be reversed*/
stmt_list : stmt {$$ = $1;} 
    | stmt_list stmt {$2->next_node = $1; $$ = $2;}
    ;

/* whenever list returns, call reverse()?*/
stmt : var ASSIGN expr {$$ = make_syntax_node(stASSIGN, $1, $3);}
    | IF expr THEN r_stmt_list elif_clause_list else_clause  {$$ = make_syntax_node(stIF, $2, $4, $5, $6);}
    | WHILE expr DO r_stmt_list  {$$ = make_syntax_node(stWHILE, $2, $4);}
    | REPEAT r_stmt_list UNTIL expr  {$$ = make_syntax_node(stREPEAT, $2, $4);}
    /*
    | FUNCTION ID '(' param_list ')' ':' type_desc  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO!
    | PROCEDURE ID '(' param_list ')'  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    | FUNCTION ID '(' param_list ')' ':' type_desc block  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    | PROCEDURE ID '(' param_list ')' block  {$$ = make_syntax_node(FUNCTIONST, 5);}//TODO
    */
    | RETURN expr  {$$ = make_syntax_node(stRETURN, $2);}
    | RETURN   {$$ = make_syntax_node(stRETURN, NULL);}
    ;


elif_clause_list : {$$ = NULL;}
    | elif_clause_list elif_clause {$2->next_node = $1; $$ = $2;}
    ;

elif_clause : ELIF expr THEN r_stmt_list {$$ = make_syntax_node(stELIF, $2, $4);} 

else_clause : {$$ = NULL;} %prec THEN
    | ELSE r_stmt_list {$$ = make_syntax_node(stELSE, $2);} 
    ;

/* */
expr : expr '+' expr {$$ = make_syntax_node(BINARY, '+', $1, $3, NULL);}
    | expr '-' expr {$$ = make_syntax_node(BINARY, '-', $1, $3, NULL);}
    | '-' expr {$$ = make_syntax_node(UNARY);}                                      %prec UMINUS
    | expr MUL_OP expr {$$ = make_syntax_node(BINARY, $2, $1, $3, NULL);}
    | expr REL_OP expr {$$ = make_syntax_node(BINARY, $2, $1, $3, NULL);}
    | '(' expr ')' {$$ = make_syntax_node(PAREN, $2);}
    /*| ID '(' aparam_list ')' {$$ = make_syntax_node(FUNCTIONEX);}//TODO */
    | var  {$$ = make_syntax_node(SIMPLE, $1);}
    | STRING {$$ = make_syntax_node(STRING);}
    | int_const {$$ = make_syntax_node(CONS, $1);}
    //TODO: add logic operators (and, or, etc)
    ;

/* */
int_const : NUMBER  {$$ = $1;}
    ;

/* for IDs already declared. check if id in symtab. if not, error.*/
var : ID  {id_info_ptr lookup = find_id($1); $$ = lookup ? lookup : make_id_info($1, ik_VAR, err_ptr, NULL);}
  | ID '[' NUMBER ']' {id_info_ptr lookup = find_id($1); $$ = lookup ? lookup : make_id_info($1, ik_VAR, err_ptr, NULL);}

  ;


  
%%

/* c code */

type_desc_ptr check_descriptor(char* type) {
    id_info_ptr descriptor = find_id(type);

    if (!descriptor) {
        yyerror("type \"%s\" not found", type);
        return err_ptr;
    }

    if (!(descriptor->id == ik_TYPE)) {
        yyerror("\"%s\" is not a type descriptor", type);
        return err_ptr;
    }
    return descriptor->desc;
}


void assign_typing_and_insert(id_info_ptr cur, type_desc_ptr assignment) {
    cur->desc = assignment;
    insert_id(cur);
    id_info_ptr temp = cur;


    while(temp->next) {
        temp = temp->next;
        temp->desc = assignment;
        insert_id(temp);
    }
}

syntax_node_ptr reverse(syntax_node_ptr first){

    syntax_node_ptr temp = NULL;
    syntax_node_ptr prev = NULL;
    syntax_node_ptr cur = first;
    while(cur) {
        temp = cur;
        cur = cur->next_node;
        temp->next_node = prev;
        prev = temp;

    }
    return cur;
}


int is_same_type(type_desc_ptr first, type_desc_ptr second) {
    return first == second;
}
