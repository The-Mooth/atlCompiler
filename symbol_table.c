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

  //add program name
  type_desc_ptr program_descriptor = make_type_desc(tk_SCALAR, 0, 0, 0, NULL);
  id_info_ptr program_symbol = make_id_info(progname, ik_TYPE, program_descriptor, NULL);
  insert_id(program_symbol);

  //initialize default types
  //int, string, bool, error?? maybe char...
  type_desc_ptr int_desc = make_type_desc(tk_SCALAR, 4, 0, 0, NULL);
  id_info_ptr  int_symbol = make_id_info("int", ik_TYPE, int_desc, NULL);

  type_desc_ptr bool_desc = make_type_desc(tk_SCALAR, 1, 0, 0, NULL);
  id_info_ptr bool_symbol = make_id_info("bool", ik_TYPE, bool_desc, NULL);

  type_desc_ptr string_desc = make_type_desc(tk_STRING, 0, 0, 0, NULL);
  id_info_ptr string_symbol = make_id_info("string", ik_TYPE, string_desc, NULL);

  type_desc_ptr err_desc = make_type_desc(tk_SCALAR, 0, 0, 0, NULL);
  id_info_ptr err_symbol = make_id_info("error", ik_TYPE, err_desc, NULL);

  insert_id(int_symbol);
  insert_id(bool_symbol);
  insert_id(string_symbol);
  insert_id(err_symbol);
  new_scope();

}

void insert_id(id_info_ptr id) {
  
  debug_printf("Inserting id %s into scope %d\n", id->name, cur_scope);

  if(kv_find(scope[cur_scope], id->name)) {
    yyerror("Identifier %s already exists in scope.", id->name);
    free(id);
    return;
  }
  
  if (kv_insert(&scope[cur_scope], id->name, id) == 0) {
    yyerror("Error inserting identifier %s into scope %d.", id->name, cur_scope);
    free(id);
  }

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

//returns scope of id, or -2 if not found
//remember, base scope is -1, so -2 is an error return
int find_scope(char* name) {
  for (int i = cur_scope; i >= -1; i--) {
    if (kv_find(scope[i], name)) {
      return i;
    }
  }
  return -2;
}

//returns id_info_ptr if found, otherwise null
id_info_ptr find_id(char* name) {
  id_info_ptr result = NULL;
  for(int i = cur_scope; i>= -1; i--) {
    result = kv_find(scope[i], name);
    if (result) {return result;}
  }
  return NULL;
}


void print_scope() {

}
/*needed functions:
print_scope
print_all?

*/
