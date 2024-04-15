#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_structs.h"
#include "symbol_table.h"
#include "syntax_tree.h"
#include "kv_tree.h"


//constants and prototypes. Doesn't require EXTERN, as they reference operations and not values

//constants
#define FALSE 0
#define TRUE 1

//structure prototypes will be in the respective .h files for now.
//TODO?: restructure header files to not use so many globals?

//function prototypes

  //symbol_structs.c
  type_desc_ptr make_type_desc(type_kind tk_kind, int size, int low, int high, type_desc_ptr arr_type);
  //trying an overload function using precompilation
  //likely poor practice?
  #define make_type_simple(type_kind) make_type_desc(type_kind tk_kind, 1, 0, 1, null);
  id_info_ptr make_id_info(char* name, id_kind id, type_desc_ptr desc, id_info_ptr id_list, ...);

  //parser.c
  int yyparse(void);
  int yyerror(char* s);

  //scanner.c
  int yylex(void);

  //util.c
  void debug_printf(char* line, ...); 
  void gen_error(char* err_msg);

