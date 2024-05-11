

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



struct syntax_node {
  //int lvl?
  //int offset?
  //

  syntax_node_ptr next_node;

  union {
    union {
      
      struct{} repeat;
      struct{} assign;
      struct{} while_node;
      struct{} function;
      struct{} return_node;
      struct{} if_node;
      struct{} else_node;
      struct{} elif;
    } fmt;

    union {
      struct{} block;
      struct{} program;
      struct{} subprogram;
    }stmt;

    union{

      struct{} binary;

      struct{} unary;

      struct{} simple;

      struct{} constant;

      struct{} parentheses;

      struct{} index;

      struct{} aparam;
      
      struct{} mparam;
    }expr;

  } type;
} syntax_node;

#endif;