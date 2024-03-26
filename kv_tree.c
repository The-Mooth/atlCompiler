/* kv_tree.c: Balanced Binary Tree routines */

#include "kv_tree.h"
#include <string.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE  1

/*  find_key returns a pointer to node in TREE that has the correct
    KEY.  If there is no node in TREE with KEY, NULL is returned. */

static kv_rec *
find_key (kv_rec *tree, const char *key)
{
  int cmp_result;
  
  /* Check for an empty tree. */
  if (tree == NULL)
    return NULL;
  
  /* Recursively search the tree. */
  cmp_result = strcmp (key, tree->key);
  if (cmp_result == 0)
    return tree;  /* This is the item. */
  else if (cmp_result < 0)
    return find_key (tree->left, key);
  else
    return find_key (tree->right, key);  
}


/* insert_key inserts a NEW_KEY rec into the tree whose ROOT is
   provided.  insert_key returns TRUE if the tree height from
   ROOT down is increased otherwise it returns FALSE.  This is a
   recursive balanced binary tree insertion algorithm. */

static int insert_key (kv_rec **root, kv_rec *new_key)
{
  kv_rec *A, *B;
  
  /* If root is NULL, this where it is to be inserted. */
  if (*root == NULL)
    {
      *root = new_key;
      new_key->left = NULL;
      new_key->right = NULL;
      new_key->balance = 0;
      return (TRUE);
    }
  
  /* We need to search for a leaf. */
  if (strcmp (new_key->key, (*root)->key) < 0)
    {
      /* Insert it on the left. */
      if (insert_key (&((*root)->left), new_key))
	{
	  /* The height increased. */
	  (*root)->balance --;
	  
	  switch ((*root)->balance)
	    {
	    case  0:  /* no height increase. */
	      return (FALSE);
	    case -1:  /* height increase. */
	      return (TRUE);
	    case -2:  /* we need to do a rebalancing act. */
	      A = *root;
	      B = (*root)->left;
	      if (B->balance <= 0)
		{
		  /* Single Rotate. */
		  A->left = B->right;
		  B->right = A;
		  *root = B;
		  A->balance = 0;
		  B->balance = 0;
		}
	      else
		{
		  /* Double Rotate. */
		  *root = B->right;
		  B->right = (*root)->left;
		  A->left = (*root)->right;
		  (*root)->left = B;
		  (*root)->right = A;
		  switch ((*root)->balance)
		    {
		    case -1:
		      A->balance = 1;
		      B->balance = 0;
		      break;
		    case  0:
		      A->balance = 0;
		      B->balance = 0;
		      break;
		    case  1:
		      A->balance = 0;
		      B->balance = -1;
		      break;
		    }
		  (*root)->balance = 0;
		}
	    }     
	} 
    }
  else
    {
      /* Insert it on the right. */
      if (insert_key (&((*root)->right), new_key))
	{
	  /* The height increased. */
	  (*root)->balance ++;
	  switch ((*root)->balance)
	    {
	    case 0:  /* no height increase. */
	      return (FALSE);
	    case 1:  /* height increase. */
	      return (TRUE);
	    case 2:  /* we need to do a rebalancing act. */
	      A = *root;
	      B = (*root)->right;
	      if (B->balance >= 0)
		{
		  /* Single Rotate. */
		  A->right = B->left;
		  B->left = A;
		  *root = B;
		  A->balance = 0;
		  B->balance = 0;
		}
	      else
		{
		  /* Double Rotate. */
		  *root = B->left;
		  B->left = (*root)->right;
		  A->right = (*root)->left;
		  (*root)->left = A;
		  (*root)->right = B;
		  switch ((*root)->balance)
		    {
		    case -1:
		      A->balance = 0;
		      B->balance = 1;
		      break;
		    case  0:
		      A->balance = 0;
		      B->balance = 0;
		      break;
		    case  1:
		      A->balance = -1;
		      B->balance = 0;
		      break;
		    }
		  (*root)->balance = 0;
		}
	    }     
	} 
    }
  
  /* If we fall through to here, the tree did not grow in height. */
  return (FALSE);
}

static void post_free (kv_rec *rec, int free_key, int free_value)
{
  if (rec != NULL) {
    post_free (rec->left, free_key, free_value);
    post_free (rec->right, free_key, free_value);
    if (free_key) free((void *)rec->key);
    if (free_value) free(rec->value);
    free(rec);
  }
}

/* Visible routines */

void kv_init ( kv_tree *tree )
{
  *tree = NULL;
}

/* Returns 1 if inserted, 0 if not inserted */
int kv_insert ( kv_tree *tree, const char *key, void *value ) {
  void *ret;
  ret = find_key (*tree, key);
  if (ret != NULL) return 0;

  /* Not found, insert it */
  kv_rec *new_rec = malloc(sizeof(kv_rec));
  if (new_rec == NULL)
    return 0;
  new_rec->key = key;
  new_rec->value = value;
  (void) insert_key (tree, new_rec);
  return 1;
}

/* Returns the value pointer if found,  NULL if not found. */
void * kv_find ( kv_tree tree, const char *key )
{
  kv_rec *ret = find_key(tree,key);
  if (ret)
    return ret->value;
  return NULL;
}

void kv_destroy ( kv_tree *tree, int free_key, int free_value )
{
  post_free (*tree, free_key, free_value);
  *tree = NULL;
}

void kv_visit ( kv_tree tree, void (*visit)(const char *, void *)) {
  if (tree != NULL) {
	
    kv_visit (tree->left, visit);
    visit(tree->key, tree->value);
    kv_visit (tree->right, visit);
  }
}
