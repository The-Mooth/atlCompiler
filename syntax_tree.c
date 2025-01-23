#include "definitions.h"
#include "globals.h"


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
    case fBLOCK:
      handle_BLOCK(node, args);
      debug_printf("    AST Node: BLOCK\n");
      break;

    case fPROGRAM:
      handle_PROGRAM(node, args);
      debug_printf("    AST Node: PROGRAM\n");
      break;
        
    case fSUBPROGRAM:
      handle_SUBPROGRAM(node, args);
      debug_printf("    AST Node: SUBPROGRAM\n");
      break;
        
    case stASSIGN:
      handle_ASSIGN(node, args);
      debug_printf("    AST Node: ASSIGN\n");
      break;
        
    case stREPEAT:
      handle_REPEAT(node, args);
      debug_printf("    AST Node: REPEAT\n");
      break;
        
    case stWHILE:
      handle_WHILE(node, args);
      debug_printf("    AST Node: WHILE\n");
      break;
        
    case stFUNCTIONST:
      handle_FUNCTIONST(node, args);
      debug_printf("    AST Node: FUNCTIONST\n");
      break;
        
    case stRETURN:
      handle_RETURN(node, args);
      debug_printf("    AST Node: RETURN\n");
      break;
        
    case stIF:
      handle_IF(node, args);
      debug_printf("    AST Node: IF\n");
      break;
        
    case stELSE:
      handle_ELSE(node, args);
      debug_printf("    AST Node: ELSE\n");
      break;
        
    case stELIF:
      handle_ELIF(node, args);
      debug_printf("    AST Node: ELIF\n");
      break;
        
    case BINARY:
      handle_BINARY(node, args);
      debug_printf("    AST Node: BINARY\n");
      break;
        
    case UNARY:
      handle_UNARY(node, args);
      debug_printf("    AST Node: UNARY\n");
      break;
        
    case FUNCTIONEX:
      handle_FUNCTIONEX(node, args);
      debug_printf("    AST Node: FUNCTIONEX\n");
      break;
        
    case SIMPLE:
      handle_SIMPLE(node, args);
      debug_printf("    AST Node: SIMPLE\n");
      break;
        
    case CONS:
      handle_CONS(node, args);
      debug_printf("    AST Node: CONS\n");
      break;
        
    case PAREN: 
      handle_PAREN(node, args);
      debug_printf("    AST Node: PAREN\n");
      break;
        
    case INDEX:
      handle_INDEX(node, args);
      debug_printf("    AST Node: INDEX\n");
      break;
        
    case APARAM:
      handle_APARAM(node, args);
      debug_printf("    AST Node: APARAM\n");
      break;
        
    case MPARAM:
      handle_MPARAM(node, args);
      debug_printf("    AST Node: MPARAM\n");
      break;
        
    default:
      yyerror("ast node type does not exist?\n");
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

void handle_BLOCK(syntax_node_ptr node, va_list args) {
  node->data.fmt.block.stmt_list = va_arg(args, syntax_node_ptr);
  node->data.fmt.block.dec_list = va_arg(args, syntax_node_ptr);
  node->data.fmt.block.name = va_arg(args, char*);
}

void handle_PROGRAM(syntax_node_ptr node, va_list args) {
  node->data.fmt.program.block = va_arg(args, syntax_node_ptr);
}

void handle_SUBPROGRAM(syntax_node_ptr node, va_list args) {
  //to be added
}

void handle_REPEAT(syntax_node_ptr node, va_list args) {
  node->data.stmt.repeat.stmt_list = va_arg(args, syntax_node_ptr);
  node->data.stmt.repeat.expr = va_arg(args, syntax_node_ptr);
}

void handle_ASSIGN(syntax_node_ptr node, va_list args) {
  node->data.stmt.assign.var = va_arg(args, id_info_ptr);
  node->data.stmt.assign.expr = va_arg(args, syntax_node_ptr);
}

void handle_WHILE(syntax_node_ptr node, va_list args) {
  node->data.stmt.while_node.expr = va_arg(args, syntax_node_ptr);
  node->data.stmt.while_node.stmt_list = va_arg(args, syntax_node_ptr);
}

void handle_FUNCTIONST(syntax_node_ptr node, va_list args) {
  node->data.stmt.function_st.stmt_list = va_arg(args, syntax_node_ptr);
}

void handle_RETURN(syntax_node_ptr node, va_list args) {
  node->data.stmt.return_node.expr = va_arg(args, syntax_node_ptr);
}

void handle_IF(syntax_node_ptr node, va_list args) {
  node->data.stmt.if_node.expr = va_arg(args, syntax_node_ptr);
  node->data.stmt.if_node.then = va_arg(args, syntax_node_ptr);
  node->data.stmt.if_node.elif = va_arg(args, syntax_node_ptr);
  node->data.stmt.if_node.else_node = va_arg(args, syntax_node_ptr);
}

void handle_ELSE(syntax_node_ptr node, va_list args) {
  node->data.stmt.else_node.stmt_list = va_arg(args, syntax_node_ptr);
}

void handle_ELIF(syntax_node_ptr node, va_list args) {
  node->data.stmt.elif.expr = va_arg(args, syntax_node_ptr);
  node->data.stmt.elif.then= va_arg(args, syntax_node_ptr);
}

void handle_BINARY(syntax_node_ptr node, va_list args) {
  node->data.expr.binary.op = va_arg(args, int);
  node->data.expr.binary.expr1 = va_arg(args, syntax_node_ptr);
  node->data.expr.binary.expr2 = va_arg(args, syntax_node_ptr);
  node->data.expr.binary.result = va_arg(args, type_desc_ptr);
}

void handle_UNARY(syntax_node_ptr node, va_list args) {
  node->data.expr.unary.op = va_arg(args, int);
  node->data.expr.unary.expr = va_arg(args, syntax_node_ptr);
  node->data.expr.unary.result = va_arg(args, type_desc_ptr);
}

void handle_FUNCTIONEX(syntax_node_ptr node, va_list args) {
    //TODO
}

void handle_SIMPLE(syntax_node_ptr node, va_list args) {
  node->data.expr.simple.variable = va_arg(args, id_info_ptr);
}

void handle_CONS(syntax_node_ptr node, va_list args) {
  node->data.expr.constant.value = va_arg(args, int);
}

void handle_PAREN(syntax_node_ptr node, va_list args) {
  node->data.expr.parentheses.contents = va_arg(args, syntax_node_ptr);
}

void handle_INDEX(syntax_node_ptr node, va_list args) {
  node->data.expr.index.pos = va_arg(args, int);
}

void handle_APARAM(syntax_node_ptr node, va_list args) {
  node->data.expr.aparam.expr = va_arg(args, syntax_node_ptr);
}

void handle_MPARAM(syntax_node_ptr node, va_list args) {
  //tentative
  node->data.expr.mparam.aparam = va_arg(args, syntax_node_ptr);
}