#include "bst.h" 

int main(){

  BinarySearchTree bst(14);
  for(int i = 0; i < 8; i++){
    bst.insertBST(3*i);
  }
  bst.insertBST(22);
  bst.insertBST(7);
  bst.insertBST(30);
  bst.insertBST(2);
  bst.insertBST(19);
  printf("\n%d\n", bst.getRoot()->value);
  bst.postOrderPrintRecursively(bst.getRoot());
  printf("\n%d\n", bst.getRoot()->value);

  bst.deleteBST(bst.getRoot(), 14);
  bst.postOrderPrintRecursively(bst.getRoot());
  printf("\n%d\n", bst.getRoot()->value);
  bst.deleteBST(bst.getRoot(), 30);
  bst.postOrderPrintRecursively(bst.getRoot());
  printf("\n%d\n", bst.getRoot()->value);
  bst.deleteBST(bst.getRoot(), 15);
  bst.postOrderPrintRecursively(bst.getRoot());
  printf("\n%d\n", bst.getRoot()->value);
  bst.deleteBST(bst.getRoot(), 3);
  bst.postOrderPrintRecursively(bst.getRoot());
  printf("\n%d\n", bst.getRoot()->value);
  bst.deleteBST(bst.getRoot(), 21);
  bst.postOrderPrintRecursively(bst.getRoot());
  printf("\n%d\n", bst.getRoot()->value);
}