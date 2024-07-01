#include "definitions.h"
#include "globals.h"

//symbol table will be an array of key-variable trees, each tree representing a scope.
//max of 16 scopes, because in the event that I need to write something that complex
//I'll use something industry standard
kv_tree symtab[17];
//use negative index to hide default type pointers (int, str, etc)
kv_tree* scope = &symtab[1];

void init_symtab(char* progname) {
  
  //create and populate negative index. 
  kv_init(&scope[cur_scope]);

  //initialize default types
  //int, string, bool, error?? maybe char...
  type_desc_ptr int_desc = make_type_desc(tk_SCALAR, 4, 0, 0, NULL);
  id_info_ptr  int_symbol = make_id_info("int", ik_TYPE, int_desc, NULL);

  

  type_desc_ptr bool_desc = make_type_desc(tk_SCALAR, 1, 0, 0, NULL);
  id_info_ptr bool_desc = make_id_info("bool", ik_TYPE, bool_desc, NULL);

  type_desc_ptr string_desc = make_type_desc(tk_STRING, 0, 0, 0, NULL);


}

void insert_id(char* name, id_kind kind, type_desc_ptr type) {
  
  return;
}

void new_scope() {
  cur_scope++;
  if (cur_scope > 16) {
    yyerror("Maximum scope depth exceeded.");
    cur_scope--;
    return;
  }
  kv_init(&scope[cur_scope]);
  return;
}

void destroy_scope() {
  cur_scope--;
  if (cur_scope < 0) {
    yyerror("Cannot destroy default scope.");
    cur_scope++;
    return;
  }
  kv_destroy(&scope[cur_scope], TRUE, TRUE);
  return;
}


/*needed functions:
new_scope
destroy_scope
insert_id
find_id
print_scope
print_all?

*/
