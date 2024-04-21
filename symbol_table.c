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
  

}


/*needed functions:
new_scope
destroy_scope
insert_id
find_id
print_scope
print_all?

*/
