#include <stdio.h>

#include "./lib/contracts.h"
#include "TST.h"

void test() {
  printf("Entering tests\n");

  // tests for tst_new()
  tst T = tst_new();
  printf("tst_new() passes tests\n");

  // tests for tst_insert()
  tst_insert(T, "ab");
  tst_insert(T, "abc");

  printf("height is %d\n", T->root->height);

  tst_insert(T, "de");
  tst_insert(T, "ghi");
  printf("The root node is %s\n", (char*)((tree*)T->root)->data);

  ASSERT(*(char*)T->root->data == 'd');
  printf("tst_insert() passes tests\n");

  // tests for tst_lookup()
  ASSERT(tst_lookup(T, "ab") == 1);
  ASSERT(tst_lookup(T, "a") == 0);
  ASSERT(tst_lookup(T, "abc") == 1);
  ASSERT(tst_lookup(T, "abcd") == 0);
  printf("tst_lookup() passes tests\n");


  tst_free(T);
  printf("tst_free() passes tests\n");
  return;
}

int main() {
  test();
  return 0;
}
