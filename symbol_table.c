#include "definitions.h"
#include "globals.h"

//symbol table will be an array of key-variable trees, each tree representing a scope.
//max of 16 scopes, because in the event that I need to write something that complex
//I'll use a real language like js /s

kv_tree* init_symtab(char* progname) {
  //create kv tree array, with negative index for reserved typing
  kv_tree true_scope[max_scope];
  kv_tree* scope = &true_scope[1];

//create and populate negative index. 
  kv_init(scope[cur_scope]);

  //initialize default types
  

}


/*needed functions:
new_scope
destroy_scope
insert_id
find_id
print_scope
print_all?

*/
