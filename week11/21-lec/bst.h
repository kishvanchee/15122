#include "../21-code/lib/contracts.h"

#ifndef _BST_H_
#define _BST_H_

typedef void *elem;
//typedef void *key;

typedef int elem_compare_fn(elem e1, elem e2);

struct tree_node {
  elem data;
  int height;
  struct tree_node* left;
  struct tree_node* right;

};
typedef struct tree_node tree;

struct bst_header {
  tree* root;
  elem_compare_fn* elem_compare;
};
typedef struct bst_header* bst;

bst bst_new();
void bst_insert(bst B, elem x);
elem bst_lookup(bst B, elem x);



#endif
