

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
  FUNCTION,
  RETURN,
  IF,
  ELSE,
  ELIF,

  //expression nodes
  BINARY,
  UNARY,
  FUNCTION,
  SIMPLE,
  CONS,
  PAREN,
  INDEX,
  APARAM,
  MPARAM


} node_type;

typedef struct syntax_node* syntax_node_ptr;

typedef union {     
  struct{} repeat;
  struct{} assign;
  struct{} while_node;
  struct{} function;
  struct{} return_node;
  struct{} if_node;
  struct{} else_node;
  struct{} elif;
} format;

typedef union {
  struct{} block;
  struct{} program;
  struct{} subprogram;
}statement;

typedef union{
  struct{
    char op;
    syntax_node_ptr expr1;
    syntax_node_ptr exp2;
    type_desc_ptr result;
  } binary;
  struct{
    char op;
    syntax_node_ptr expr;
    type_desc_ptr res;
  } unary;
  struct{
    id_info_ptr variable;
  } simple;
  struct{
    int value;
  } constant;
  struct{
    char* value;
  } string;
  struct{
    syntax_node_ptr contents;
  } parentheses;
  struct{
    int pos;
  } index;
  struct{
    syntax_node_ptr expr;
  } aparam;
  struct{
    /*TODO: what do I need to track here?
    probably required parameter type,
    and default value assuming no type supplied.
    I may be able to accomplish this using a
    generated actual param as reference, like so-
    */
    syntax_node_ptr aparam;
  } mparam;
}expression;

struct syntax_node {
  //int lvl?
  //int offset?
  node_type type;

  syntax_node_ptr next_node;

  union {
  format fmt;
  statement stmt;
  expression expr;
  } type;

} syntax_node;

#endif;