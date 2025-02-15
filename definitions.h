#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_structs.h"
#include "syntax_tree.h"
#include "kv_tree.h"
#include "code_gen.h"

//constants and prototypes. Doesn't require EXTERN, as they reference operations and not values

//constants
#define FALSE 0
#define TRUE 1

//structure prototypes will be in the respective .h files for now.
//TODO?: restructure header files to not use so many globals?

//public function prototypes only, structs will remain in related header files.

  //symbol_structs.c
  type_desc_ptr make_type_desc(type_kind tk_kind, int size, int low, int high, type_desc_ptr arr_type);
  //trying an overload function using precompilation
  //likely poor practice?
  #define make_type_simple(type_kind) make_type_desc(type_kind tk_kind, 1, 0, 1, null);
  id_info_ptr make_id_info(char* name, id_kind id, type_desc_ptr desc, id_info_ptr id_list, ...);

  //symbol_table.c
  void init_symtab(char* progname);
  void insert_id(id_info_ptr id);
  void new_scope();
  void destroy_scope();
  id_info_ptr find_id(char* name);
  void print_scope();
  
  //syntax_tree.c
  syntax_node_ptr make_syntax_node(node_type type, ...);

  //parser.c
  int yyparse(void);
  #define YYDEBUG 1

  //scanner.c
  #define YY_DECL int yylex_internal()
  int yylex_internal(void);
  int yylex(void);

  //util.c
  void debug_printf(char* line, ...); 
  void yyerror(char* err_msg, ...);

