/* ternary_search_trie */

#ifndef _TST_H
#define _TST_H

#include <stdbool.h>

typedef void * elem;
typedef int elem_compare_fn(elem e1, elem e2);

struct tree_node {
  elem data;
  int height;
  bool is_end_of_word;

  // number of occurences of this word if is_end_of_word == true,
  // if not exists set to 0
  int count;
  struct tree_node* left;
  struct tree_node* middle; // next level
  struct tree_node* right;
};

typedef struct tree_node tree;

// struct bst_header {
  //  tree* root;
  //  elem_compare_fn* elem_compare;
  //};


struct tst_header {
  tree* root;
  elem_compare_fn* cmp;
};

typedef struct tst_header * tst;

tst tst_new();

// RETURNS: the number of occurences of e, if not exists return 0;
int tst_lookup(tst t, elem e);
void tst_insert(tst t, elem e);
void tst_free(tst t);

#endif
