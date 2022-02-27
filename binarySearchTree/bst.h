#include <cstdio>
#include <iostream>
#include <cassert>

class Node {
public:
  int value;
  Node* leftChild;
  Node* rightChild;
  Node();
  Node(int value);
};

class BinarySearchTree {
private:
  Node* root;
  int size;
public:
  BinarySearchTree();
  BinarySearchTree(int val);
  Node *getRoot();
  void inOrderPrint(Node* currentNode); 
  void inOrderPrintIteratively(Node *currentNode);
  // cout the values of the sub-tree in which root is currentNode in the ascending order
  void insertBST(int val);
  Node* insertRecursiveHelper(Node* currentNode, int val);
  void insertBSTRecursively(int val);
  int getSize();
  Node *searchBST(int val);
  Node *searchRecursiveHelper(Node *current, int val);
  Node *searchBSTRecursively(int val);
  bool deleteBST(Node* current, int val);

  void preOrderPrintIteratively(Node * current);
  void preOrderPrintRecursively(Node * current);

  void postOrderPrintIteratively(Node * current);
  void postOrderPrintRecursively(Node * current);
};

class MyStack {
private:
  int capacity;
  int numElements;
  Node** stackArr;
public:
  MyStack(int size);
  bool isEmpty();
  Node* getTop();
  bool push(Node* nodePtr);
  Node* pop();
  int getSize();
};