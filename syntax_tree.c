#include "definitions.h"
#include "globals.h"

//current plan: use an array of function pointers
//over a switch statement, because its interesting
//slight cost in performance though
//and readability

syntax_node_ptr make_syntax_node(node_type type, ...) {

  va_list args;
  va_start(args, type);

  syntax_node_ptr node = (syntax_node_ptr) malloc(sizeof(struct syntax_node));

  node->type = type;

  choose_node_type(node, args);
  
  va_end(args);

  return node;

}

void choose_node_type(syntax_node_ptr node, va_list args){

  switch (node->type) {
    case BLOCK:
      handle_BLOCK(node, args);
      break;

    case PROGRAM:
      handle_PROGRAM(node, args);
      break;
        
    case SUBPROGRAM:
      handle_SUBPROGRAM(node, args);
      break;
        
    case ASSIGN:
      handle_ASSIGN(node, args);
      break;
        
    case REPEAT:
      handle_REPEAT(node, args);
      break;
        
    case WHILE:
      handle_WHILE(node, args);
      break;
        
    case FUNCTIONST:
      handle_FUNCTIONST(node, args);
      break;
        
    case RETURN:
      handle_RETURN(node, args);
      break;
        
    case IF:
      handle_IF(node, args);
      break;
        
    case ELSE:
      handle_ELSE(node, args);
      break;
        
    case ELIF:
      handle_ELIF(node, args);
      break;
        
    case BINARY:
      handle_BINARY(node, args);
      break;
        
    case UNARY:
      handle_UNARY(node, args);
      break;
        
    case FUNCTIONEX:
      handle_FUNCTIONEX(node, args);
      break;
        
    case SIMPLE:
      handle_SIMPLE(node, args);
      break;
        
    case CONS:
      handle_CONS(node, args);
      break;
        
    case PAREN: 
      handle_PAREN(node, args);
      break;
        
    case INDEX:
      handle_INDEX(node, args);
      break;
        
    case APARAM:
      handle_APARAM(node, args);
      break;
        
    case MPARAM:
      handle_MPARAM(node, args);
      break;
        
    default:
      break;
    }
}
/*
possible solutions for structuring syntax tree:
-case based on union (format/expr/statement)
-passing specific struct to handlers, as opposed to whole node
-suck it up and pass whole node

*/
//Below are the case handlers for individual node types, who will take different arguments
void handle_BLOCK(format fmt, va_list args) {
    
}

void handle_PROGRAM(syntax_node_ptr node, va_list args) {
    
}

void handle_SUBPROGRAM(syntax_node_ptr node, va_list args) {
    
}

void handle_ASSIGN(syntax_node_ptr node, va_list args) {
    
}

void handle_REPEAT(syntax_node_ptr node, va_list args) {
    
}

void handle_WHILE(syntax_node_ptr node, va_list args) {
    
}

void handle_FUNCTIONST(syntax_node_ptr node, va_list args) {
    
}

void handle_RETURN(syntax_node_ptr node, va_list args) {
    
}

void handle_IF(syntax_node_ptr node, va_list args) {
    
}

void handle_ELSE(syntax_node_ptr node, va_list args) {
    
}

void handle_ELIF(syntax_node_ptr node, va_list args) {
    
}

void handle_BINARY(syntax_node_ptr node, va_list args) {
    
}

void handle_UNARY(syntax_node_ptr node, va_list args) {
    
}

void handle_FUNCTIONEX(syntax_node_ptr node, va_list args) {
    
}

void handle_SIMPLE(syntax_node_ptr node, va_list args) {
    
}

void handle_CONS(syntax_node_ptr node, va_list args) {
    
}

void handle_PAREN(syntax_node_ptr node, va_list args) {
    
}

void handle_INDEX(syntax_node_ptr node, va_list args) {
    
}

void handle_APARAM(syntax_node_ptr node, va_list args) {
    
}

void handle_MPARAM(syntax_node_ptr node, va_list args) {
    
}