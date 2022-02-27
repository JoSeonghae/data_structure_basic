#include "graph.h"
#include <cassert>

Node::Node(){
  nextElement = nullptr;
}

LinkedList::LinkedList() {
  head = nullptr;
}

bool LinkedList::isEmpty() {
  if (head == nullptr)
    return true;
  else
    return false;
}

Node * LinkedList::getHead() {
  return head;
}

bool LinkedList::printList() {
  if (isEmpty()) {
    cout << "List is Empty!";
    return false;
  }
  Node * temp = head;
  cout << "List : ";

  while (temp != nullptr) {
    cout << temp -> data << "->";
    temp = temp -> nextElement;
  }
  cout << "null " << endl;
  return true;
}

bool LinkedList::insertAtHead(int value) {
  Node * newNode = new Node();
  newNode -> data = value;
  newNode -> nextElement = head;
  head = newNode;
  return true; 
}

void LinkedList::insertAtTail(int value) {
  if (isEmpty()) {
    insertAtHead(value);
  } else {
    Node * newNode = new Node();
    Node * last = head;

    while (last -> nextElement != nullptr) {
      last = last -> nextElement;
    }

    newNode -> data = value;
    newNode -> nextElement = nullptr;
    last -> nextElement = newNode;
  }
}

bool LinkedList::search(int value) { 
  Node * temp = head;

  while (temp != nullptr) {
    if (temp -> data == value) {
      return true;
    }
    temp = temp -> nextElement;
  }
  return false;
}

bool LinkedList::deleteAtHead(int value) {

  bool deleted = false;
  if (isEmpty()) {
    return deleted;
  }
  
  Node * currentNode = head;
  Node * nextNode = head -> nextElement;

  if (currentNode -> data == value) {
    currentNode = nextNode;
    head = currentNode;
    deleted = true;
    return deleted;
  }
  return deleted;
}

bool LinkedList::Delete(int value) {
  bool deleted = false;

  if (isEmpty()) { 
    return deleted;
  }

  Node * currentNode = head;
  Node * previousNode = nullptr;

  if (currentNode -> data == value) {
    deleted = deleteAtHead(value);
    deleted = true;
    return deleted;
  }

  while (currentNode != nullptr) {

    if (value == currentNode -> data) {
      previousNode -> nextElement = currentNode -> nextElement;
      deleted = true;
      break;
    }
    previousNode = currentNode;
    currentNode = currentNode -> nextElement;
  }
  if (deleted == false) {
   cout << value << " does not exist!" << endl;
  } else {
   cout << value << " deleted!" << endl;
  }
  return deleted;
}


Graph::Graph(int vertices){
  this->vertices = vertices;
  array = new LinkedList[vertices];
}

void Graph::addEdge(int source, int target){
  if(source < vertices && target < vertices){
    array[source].insertAtHead(target);
  }
}

void Graph::printGraph(){
  cout << "Graph Adjacency List\n";
  for(int i = 0; i < vertices; i++){
    cout << "|" << array[i].getHead() << "| => ";
    array[i].printList();
  }
}

LinkedList *Graph::getArray(){
  return array;
}

int Graph::getVertices(){
  return vertices;
}

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

bool MyQueue::isEmpty(){
  return items.isEmpty();
}

int MyQueue::getSize(){
  return items.size;
}

int MyQueue::getFront(){
  return items.getHead();
}

int MyQueue::getBack(){
  return items.getTail();
}

int MyQueue::enqueue(int value){
  items.insertTail(value);
  return items.getTail();
}

int MyQueue::dequeue(){
  if(isEmpty()){
    return -1;
  }
  int dequeuedValue = items.getHead();
  items.deleteHead();
  return dequeuedValue;
}

bool MyQueue::showQueue(){
  return items.printList();
}


MyStack::MyStack(int size){
  stackArr = new int[size];
  capacity = size;
  assert(stackArr != NULL);
  numElements = 0;
}

bool MyStack::isEmpty(){
  return (numElements == 0);
}

int MyStack::getSize(){
  return numElements;
}

bool MyStack::push(int value){
  if(numElements < capacity){
    stackArr[numElements] = value;
    numElements++;
    return true;
  } else {
    std::cout << "Full Stack\n";
    return false;
  }
}

int MyStack::getTop(){
  return (numElements == 0 ? -1 : stackArr[numElements-1]);
}

int MyStack::pop(){
  if(isEmpty()){
    std::cout << "Empty Stack\n";
    return -1;
  } else {
    numElements--;
    return stackArr[numElements];
  }
}

void MyStack::showStack(){
  if(isEmpty()){
    std::cout << "Empty Stack: Nothing to show!";
  } else {
    std::cout << "<The Stack> From Top:\t";
    for(int i = numElements-1; i >= 0; i--){
      std::cout << stackArr[i] << "  ";
    }
    std::cout << ":To Bottom\n";
  }
}