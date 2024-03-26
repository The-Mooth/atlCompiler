/* kv_tree.h:  The record definition for the balanced tree. */

/* Basic balanced binary tree. */

typedef struct kv_rec {
	/* The balanced binary tree fields. */
	const char  *key;      /* The key. */
	short balance;   /* For the balanced tree. */
	struct kv_rec *left, *right; /* Tree pointers. */
  
	/* Other information fields. */
	void *value;
} kv_rec;


typedef struct kv_rec *kv_tree;

/* Functions */

/* Initializes a new kv_tree. */
void kv_init ( kv_tree *tree );

/* Insert a new Key/Value pair.  Pointers to the key
   and the value are stored.  Data pointed to by the key
   and the data are not copied or stored.

   Returns 1 if inserted, 0 if not inserted due to duplicate key. */
int kv_insert ( kv_tree *tree, const char *key, void *value );

/* Search for a Key/Value pair.  The key is a string that
   is compared to the key string in the key/value pair.

   Returns the value pointer if found,  NULL if not found. */
void * kv_find ( kv_tree tree, const char *key );

/*  Destroy the tree.  "free_key" and "free_value" should be 
    true (1) if a key pointer should be freed or a value pointer
    should be freed.  */
void kv_destroy ( kv_tree *tree, int free_key, int free_value);

/*  Visit the tree in key order. */
void kv_visit ( kv_tree tree, void (*visit)(const char *, void *));
