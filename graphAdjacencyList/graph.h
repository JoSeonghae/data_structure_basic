#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *nextElement;
  Node();
};

class LinkedList {
private:
  Node *head;
public:
  LinkedList();
  bool isEmpty();
  bool insertAtHead(int value);
  void insertAtTail(int value);
  Node *getHead();
  bool printList();
  bool search(int value);
  bool deleteAtHead(int value);
  bool Delete(int value);
};

class Graph {
private:
  int vertices;
  LinkedList *array;
public:
  Graph(int vertices);
  void addEdge(int source, int target);
  void printGraph();
  LinkedList *getArray();
  int getVertices();
};

class Node2 {
public:
  int data;
  Node2 *nextElement;
  Node2 *prevElement;

  Node2(int data){
    this->data = data;
    nextElement = nullptr;
    prevElement = nullptr;
  }
};

/*
Doubly Linked List for elements of MyQueue.
Therefore, it needs insertTail(back of queue: enqueue), and deleteHead(front of queue: dequeue)
*/
class DoublyLinkedList {
private:
  Node2* head;
  Node2* tail;
public:
  int size;
  DoublyLinkedList();
  ~DoublyLinkedList();
  bool isEmpty();
  int getHead();
  int getTail();
  int printList();
  int insertTail(int value);
  bool deleteHead();
};


class MyQueue {
private:
  // doubly linked list can have dynamic size!
  DoublyLinkedList items;
public:
  bool isEmpty();
  int getSize();
  int getBack();
  int getFront();
  int enqueue(int value); // return tail->data
  int dequeue();
  bool showQueue();
};

class MyStack {
private:
  int capacity;
  int numElements;
  int *stackArr;
public:
  MyStack(int size);
  bool isEmpty();
  int getTop();
  bool push(int value);
  int pop();
  int getSize();
  void showStack();
};