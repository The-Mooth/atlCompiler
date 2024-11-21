

#ifndef SYNTAX_TREE
#define SYNTAX_TREE

//to be used as the values in the key/value tree
//will store necessary info for yacc components

typedef enum node_type {

  //format nodes
  BLOCK,
  PROGRAM,
  SUBPROGRAM,

  //statement nodes
  ASSIGN,
  REPEAT,
  WHILE,
  FUNCTIONST,
  RETURN,
  IF,
  ELSE,
  ELIF,

  //expression nodes
  BINARY,
  UNARY,
  FUNCTIONEX,
  SIMPLE,
  CONS,
  PAREN,
  INDEX,
  APARAM,
  MPARAM


} node_type;

typedef struct syntax_node* syntax_node_ptr;

typedef union Format{
  struct Block{
    syntax_node_ptr stmt_list;
    syntax_node_ptr dec_list;
    char* name;
  } block;
  struct Program{
    syntax_node_ptr block;
  } program;
  struct Subprogram{
    //this is only if I decide to do it later
    //will be used for nested programs
  } subprogram;
}format;

typedef union Statement{     
  struct Repeat{
    syntax_node_ptr stmt_list;
    syntax_node_ptr expr;
  } repeat;
  struct Assign{
    id_info_ptr var;
    syntax_node_ptr expr;
  } assign;
  struct While_node{
    syntax_node_ptr expr;
    syntax_node_ptr stmt_list;
  } while_node;
  struct Function_st{
    syntax_node_ptr stmt_list;
  } function_st;
  struct Return_node{
    syntax_node_ptr expr;
  } return_node;
  struct If_node{
    syntax_node_ptr expr;
    syntax_node_ptr then;
    syntax_node_ptr elif;
    syntax_node_ptr else_node;
  } if_node;
  struct Else_node{
    syntax_node_ptr stmt_list;
  } else_node;
  struct Elif{
    syntax_node_ptr expr;
    syntax_node_ptr then;
    syntax_node_ptr next_elif;
    syntax_node_ptr else_node;
  } elif;
}statement;

typedef union Expression{
  struct Binary{
    int op;
    syntax_node_ptr expr1;
    syntax_node_ptr expr2;
    type_desc_ptr result;
  } binary;
  struct Unary{
    int op;
    syntax_node_ptr expr;
    type_desc_ptr result;
  } unary;
   struct Function_ex{
    //TODO
  } function_ex;
  struct Simple{
    id_info_ptr variable;
  } simple;
  struct Constant{
    int value;
  } constant;
  struct String{
    char* value;
  } string;
  struct Parentheses{
    syntax_node_ptr contents;
  } parentheses;
  struct Index{
    int pos;
  } index;
  struct Aparam{
    syntax_node_ptr expr;
  } aparam;
  struct Mparam{
    /*TODO: what do I need to track here?
    probably required parameter type,
    and default value assuming no type supplied.
    I may be able to accomplish this using a
    generated actual param as reference, like so-
    */
    syntax_node_ptr aparam;
  } mparam;
}expression;

typedef struct syntax_node {
  //int lvl?
  //int offset?
  node_type type;

  syntax_node_ptr next_node;

  union Data{
  format fmt;
  statement stmt;
  expression expr;
  }data;

} syntax_node;


void choose_node_type(syntax_node_ptr node, va_list args);

//functions to handle node types
void handle_BLOCK(syntax_node_ptr node, va_list args);
void handle_PROGRAM(syntax_node_ptr node, va_list args);
void handle_SUBPROGRAM(syntax_node_ptr node, va_list args);
void handle_ASSIGN(syntax_node_ptr node, va_list args);
void handle_REPEAT(syntax_node_ptr node, va_list args);
void handle_WHILE(syntax_node_ptr node, va_list args);
void handle_FUNCTIONST(syntax_node_ptr node, va_list args);
void handle_RETURN(syntax_node_ptr node, va_list args);
void handle_IF(syntax_node_ptr node, va_list args);
void handle_ELSE(syntax_node_ptr node, va_list args);
void handle_ELIF(syntax_node_ptr node, va_list args);
void handle_BINARY(syntax_node_ptr node, va_list args);
void handle_UNARY(syntax_node_ptr node, va_list args);
void handle_FUNCTIONEX(syntax_node_ptr node, va_list args);
void handle_SIMPLE(syntax_node_ptr node, va_list args);
void handle_CONS(syntax_node_ptr node, va_list args);
void handle_PAREN(syntax_node_ptr node, va_list args);
void handle_INDEX(syntax_node_ptr node, va_list args);
void handle_APARAM(syntax_node_ptr node, va_list args);
void handle_MPARAM(syntax_node_ptr node, va_list args);
#endif