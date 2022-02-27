#include "myqueue.h"

DoublyLinkedList::DoublyLinkedList(){
  head = nullptr;
  tail = nullptr;
  size = 0;
}

bool DoublyLinkedList::isEmpty(){
  return (head == nullptr);
}

int DoublyLinkedList::insertTail(int value){
  if(isEmpty()){
    head = new Node2(value);
    tail = head;
    size++;
    return tail->data;
  }
  Node2 *newNode = new Node2(value);
  newNode->prevElement = tail;
  tail->nextElement = newNode;
  tail = newNode;
  size++;
  return tail->data;
}

// DoublyLinkedList::~DoublyLinkedList(){
//   if(isEmpty()){
//     return;
//   } else {
//     Node *currentNode = head;
//     while(currentNode->nextElement != nullptr){
//       currentNode = currentNode->nextElement;
//       delete currentNode->prevElement;
//     }
//     delete currentNode;
//     size = 0;
//   }
// }

DoublyLinkedList::~DoublyLinkedList(){
  Node2* currentNode = head;
  Node2* nextNode = nullptr;
  while(currentNode){
    nextNode = currentNode->nextElement;
    delete currentNode;
    currentNode = nextNode;
  }
}

bool DoublyLinkedList::deleteHead(){
  if(isEmpty()){
    return false;
  }
  if(head == tail){
    delete head;
    head = nullptr;
    tail = nullptr;
    return true;
  }
  head = head->nextElement;
  delete head->prevElement;
  head->prevElement = nullptr;
  return true;
}

int DoublyLinkedList::getHead(){
  return (isEmpty() ? -1 : head->data);
}

int DoublyLinkedList::getTail(){
  return (isEmpty() ? -1 : tail->data);
}

int DoublyLinkedList::printList(){
  if(isEmpty()){
    std::cout << "List is Empty!\n";
    return false;
  }
  Node2* currentNode = head;
  std::cout << "Head:\t";
  while(currentNode != nullptr){
    std::cout << currentNode->data << "\t";
    currentNode = currentNode->nextElement;
  }
  std::cout << ":Tail\n";
  return true;
}

