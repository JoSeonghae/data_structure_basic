#include <iostream>
#include <string> 

class Node {
public:
  int data;
  Node *nextElement;

  Node(){
    nextElement = nullptr;
  }
};

class LinkedList {
private:
  Node *head;
public:
  LinkedList();
  Node *getHead();
  bool isEmpty();
  bool printList();
  void insertAtHead(int value);
  std::string elements();
  void insertAtTail(int value);
  bool search(int value);
  bool deleteAtHead();
  bool Delete(int value);
  std::string removeDuplicates();
};


