#include "bst.h"

MyStack::MyStack(int size){
  capacity = size;
  numElements = 0;
  stackArr = new Node*[size];
  assert(stackArr != NULL);
}

bool MyStack::isEmpty(){
  return (numElements == 0);
}

int MyStack::getSize(){
  return capacity;
}

bool MyStack::push(Node* nodePtr){
  if(numElements < capacity){
    numElements++;
    stackArr[numElements - 1] = nodePtr;
    return true;
  } else {
    return false;
  }
}

Node* MyStack::pop(){
  if(isEmpty()){
    return nullptr;
  } else {
    numElements--;
    Node* temp = stackArr[numElements];
    stackArr[numElements] = nullptr;
    return temp;
  }
}

Node* MyStack::getTop(){
  return stackArr[numElements];
}


Node::Node(){
  value = 0;
  leftChild = nullptr;
  rightChild = nullptr;
}

Node::Node(int value){
  this->value = value;
  leftChild = nullptr;
  rightChild = nullptr;
}

BinarySearchTree::BinarySearchTree(){
  size = 0;
  root = nullptr;
}

BinarySearchTree::BinarySearchTree(int val){
  size = 1;
  root = new Node(val);
}

Node* BinarySearchTree::getRoot(){
  return root;
}

void BinarySearchTree::inOrderPrint(Node* currentNode){
  if(currentNode != nullptr){
    inOrderPrint(currentNode->leftChild);
    printf("%d\t", currentNode->value);
    inOrderPrint(currentNode->rightChild);
  }
}

void BinarySearchTree::insertBST(int val){
  size++;
  if(getRoot() == nullptr){
    root = new Node(val);
    return;
  }
  Node *current = getRoot();
  Node *parent;
  while(current != nullptr){
    parent = current;
    if(val < current->value){
      current = current->leftChild;
    } else {
      current = current->rightChild;
    }
  }
  if(val < parent->value){
    parent->leftChild = new Node(val);
  } else {
    parent->rightChild = new Node(val);
  }
}

Node *BinarySearchTree::insertRecursiveHelper(Node * currentNode, int val){
  if(currentNode == nullptr){
    return new Node(val);
  } else if(val < currentNode->value){
    currentNode->leftChild = insertRecursiveHelper(currentNode->leftChild, val);
  } else {
    currentNode->rightChild = insertRecursiveHelper(currentNode->rightChild, val);
  }
  return currentNode;
  /*
  Recursive function이 주요 인자(currentNode)와 동일한 타입(Node* )을 리턴할 때의 패턴
  currentNode->leftChild = currentNode->leftChild<nullptr에 도달하지 않았을 때, 아무 영향도 없다> 또는 new Node(val)<nullptr에 도달했을 때>
  */
}

void BinarySearchTree::insertBSTRecursively(int val){
  size++;
  if(getRoot() == nullptr){
    root = new Node(val);
    return;
  } else {
    insertRecursiveHelper(root, val);
  }
}

Node* BinarySearchTree::searchBST(int val){
  Node* current = root;
  while(current != nullptr){
    if(val < current->value){
      current = current->leftChild;
    } else if(val > current->value) {
      current = current->rightChild;
    } else {
      return current;
    }
  }
  return current; // nullptr if the value was not found
}

Node* BinarySearchTree::searchRecursiveHelper(Node* current, int val){
  if(current == nullptr){
    return current;
  } else if (val < current->value){
    return searchRecursiveHelper(current->leftChild, val);
  } else if (val > current->value){
    return searchRecursiveHelper(current->rightChild, val);
  } else { // Found
    return current;
  }
}

Node* BinarySearchTree::searchBSTRecursively(int val){
  return searchRecursiveHelper(root, val);
}

bool BinarySearchTree::deleteBST(Node* current, int val){ // 트리에 중복값은 없다고 가정
  // Empty Tree
  if(getRoot() == nullptr){
    return false;
  }
  else {
    Node* parent;
    current = root;
    while(current != nullptr && current->value != val){ // Search the node to delete and its parent node.
      parent = current;
      if(val < current->value){
        current = current->leftChild;
      } else {
        current = current->rightChild;
      }
    }

    if(current == nullptr){ // Not Found
      return false;
    } 
    else {

      if(current->leftChild == nullptr && current->rightChild == nullptr){ // Delete Leaf node
        if(current == root){ // The tree which has only one node(root and also leaf). Delete root.
          delete root;
          root = nullptr;
          return true;
        } else {
          delete current;
          if(parent->value > val){
            parent->leftChild = nullptr;
          } else {
            parent->rightChild = nullptr;
          }
          return true;
        }
      } else if(current->rightChild == nullptr){ // the node to delete only has left sub tree.
        if(current == root){
          delete root;
          root = current->leftChild;
          return true;
        } else {
          if(val < parent->value){
            parent->leftChild = current->leftChild;
          } else {
            parent->rightChild = current->leftChild;
          }
          delete current;
          return true;
        }
      } else if(current->leftChild == nullptr){ // the node to delete only has right sub tree.
        if(current == root){
          delete root;
          root = current->rightChild;
          return true;
        } else {
          if(val < parent->value){
            parent->leftChild = current->rightChild;
          } else {
            parent->rightChild = current->rightChild;
          }
          delete current;
          return true;
        }
      } else { // the node to delete has both the left sub tree and right sub tree.
        Node* leftMostInRightSubTree = current->rightChild;
        while(leftMostInRightSubTree->leftChild != nullptr){
          leftMostInRightSubTree = leftMostInRightSubTree->leftChild;
        }
        int temp = leftMostInRightSubTree->value;
        deleteBST(root, temp);
        current->value = temp;
        return true;
      }

    }
  }
}


void BinarySearchTree::inOrderPrintIteratively(Node *currentNode){ // left-root-right
  MyStack stack(size);
  Node* tempCurrent = currentNode;
  while(tempCurrent != nullptr || !stack.isEmpty()){
    while(tempCurrent != nullptr){
      stack.push(tempCurrent);
      tempCurrent = tempCurrent->leftChild;
    }
    tempCurrent = stack.pop();
    printf("%d\t", tempCurrent->value);
    tempCurrent = tempCurrent->rightChild;
  }
}

// The root cannot be printed before its left sub tree nodes are printed.
// The right child cannot be printed before its root is printed.
void BinarySearchTree::preOrderPrintIteratively(Node* current){ // root-left-right
  MyStack stack(size);
  if(current == nullptr){
    return;
  }
  Node* tempCurrent = current;
  stack.push(current);
  while(!stack.isEmpty()){
    tempCurrent = stack.pop();
    printf("%d\t", tempCurrent->value);
    if(tempCurrent->rightChild != nullptr)
      stack.push(tempCurrent->rightChild);
    if(tempCurrent->leftChild != nullptr)
      stack.push(tempCurrent->leftChild);
  } 
}

void BinarySearchTree::preOrderPrintRecursively(Node * current){
  if(current != nullptr){
    printf("%d\t", current->value);
    preOrderPrintRecursively(current->leftChild);
    preOrderPrintRecursively(current->rightChild);
  }
}

// The right child cannot be printed before its parent's left sub tree nodes are printed.
// The root cannot be printed before its right sub tree nodes are printed.

// Post order traversal has the nature of non-tail recursion(The unit start is a root, and the tail is also the root.)
// By the way, the reverse(root-right-left) of post order has the property of tail recursion(the previous left becomes the new root)
// Therefore, by using two stacks, we can use the reverse of post order traverse. 

// Pre order traversal(root-left-right) has the tail "right", so the previous right can be the new root.
// In order traversal(left-root-right) has the tail "right", so the previous right can be the new root.
void BinarySearchTree::postOrderPrintIteratively(Node * current){ // left-right-root
  if(current == nullptr) return;
  MyStack postOrderStack(size); 
  MyStack reversedStack(size); // root-right-left
  Node * tempCurrent;
  reversedStack.push(current);
  while(!reversedStack.isEmpty()){
    tempCurrent = reversedStack.pop();
    postOrderStack.push(tempCurrent);
    if(tempCurrent->leftChild != nullptr)
      reversedStack.push(tempCurrent->leftChild);
    if(tempCurrent->rightChild != nullptr)
      reversedStack.push(tempCurrent->rightChild);
  }
  while(!postOrderStack.isEmpty()){
    printf("%d\t", postOrderStack.pop()->value);
  }
}

void BinarySearchTree::postOrderPrintRecursively(Node * current){
  if(current != nullptr){
    postOrderPrintRecursively(current->leftChild);
    postOrderPrintRecursively(current->rightChild);
    printf("%d\t", current->value);
  }
}