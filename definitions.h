#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#include "symbol_structs.h"
#include "symbol_table.h"
#include "syntax_tree.h"
#include "kv_tree.h"


//constants and prototypes. Doesn't require EXTERN, as they reference operations and not values

//constants
#define FALSE 0
#define TRUE 1

//structure prototypes will be in the .h files for now.
//TODO?: restructure header files to not use so many globals

//function prototypes

  //symbol_structs.c
  type_desc_ptr make_type_desc(type_kind tk_kind, int size, int low, int high, type_desc_ptr arr_type);
  #define make_type_simple(type_kind) make_type_desc(type_kind tk_kind, 1, 0, 1, null);
  //parser.c
  int yyparse(void);

  //util.c
  void debug_printf(char* line, ...); 

