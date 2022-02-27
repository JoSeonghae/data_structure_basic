#include "LinkedList.h"

LinkedList::LinkedList () {
  head = nullptr;
}

Node *LinkedList::getHead() {
  return head;
}

bool LinkedList::isEmpty() {
  if(head == nullptr){
    return true;
  } else {
    return false;
  }
}

bool LinkedList::printList() {
  if(isEmpty()){
    std::cout << "List is Empty!";
    return false;
  }
  Node *temp = head;
  std::cout << "List: ";

  while (temp != nullptr){
    std::cout << temp->data << "->";
    temp = temp->nextElement;
  }
  std::cout << "NULL\n";
  return true;
}

void LinkedList::insertAtHead(int value){
  Node *newNode = new Node(); // head is assigned as the address of Node data in the heap.
  newNode->data = value;
  newNode->nextElement = head;
  head = newNode;
  std::cout << value << " Inserted!\n";
}

std::string LinkedList::elements() {
  std::string elementList = "";
  Node *currentNode = head;
  while(currentNode != nullptr){
    elementList += std::to_string(currentNode->data);
    elementList += "->";
    currentNode = currentNode->nextElement;
  }
  elementList += "NULL\n";
  return elementList;
}

bool LinkedList::search(int value){	
  if(isEmpty()){
    return false;
  } else {
    Node *currentNode = head;
    while(currentNode != nullptr){
      if(currentNode->data == value){
        return true;
      } else {
        currentNode = currentNode->nextElement;
      }
    }
    return false;
  }
}

void LinkedList::insertAtTail(int value){
  Node* newNode = new Node();
  newNode->data = value;
  if(head == nullptr){ // Smarter way: if(isEmpty()){ insertAtHead(value); }
    head = newNode;
  } else {
    Node* currentNode = head;
    while(currentNode->nextElement != nullptr){
      currentNode = currentNode->nextElement;
    }
    currentNode->nextElement = newNode;
  }  
  std::cout << newNode->data << ": Inserted in tail!\n"; 
}

bool LinkedList::deleteAtHead(){
  if(isEmpty()){
    return false;
  }
  Node* currentNode = head;
  head = currentNode->nextElement;
  delete currentNode;
  return true;
}

bool LinkedList::Delete(int value){
  if(isEmpty()){
    return false;
  }
  if(head->data == value){
    deleteAtHead();
    return true;
  }
  Node *currentNode = head->nextElement;
  Node *previousNode = head;
  while(currentNode != nullptr){
    if(currentNode->data == value){
      previousNode->nextElement = currentNode->nextElement;
      delete currentNode;
      return true;
    }
    previousNode = currentNode;
    currentNode = currentNode->nextElement;
  }
  return false;
}

std::string LinkedList::removeDuplicates() { // O(n^2)
  if(isEmpty()){
    return elements();
  }
  if(head->nextElement == nullptr){
    return elements();
  }
  Node *slow = head;
  int slowValue;
  Node *fast = head->nextElement;
  Node *fastPrev = head;
  Node *fastNext = fast->nextElement;
  while(slow->nextElement != nullptr){ // slow maximum: tail-1
    slowValue = slow->data;
    while(fast != nullptr){
      if(fast->data == slowValue){
        fastPrev->nextElement = fastNext;
        delete fast; // fast:tail -> fast = fastNext(nullptr), fastNext: Don't assign
        fast = fastNext;
        if(fast != nullptr){
          fastNext = fastNext->nextElement;
        }
      } else {
        fastPrev = fast;
        fast = fastNext; // fast:tail -> fast = fastNext(nullptr), fastNext: Don't assign
        if(fast != nullptr){
          fastNext = fastNext->nextElement;
        }
      }
    }
    slow = slow->nextElement; 
    /* At last, slow->nextElement can be nullptr before passing outer while
    Therefore, fast->nextElement can cause segfault(Invalid memory access) because file cannot find nullptr's pointer(nullptr->nextElement)
    */
    fastPrev = slow;
    fast = fastPrev->nextElement; // fast maximum: tail
    if(fast != nullptr){
      fastNext = fast->nextElement;  
    } else {
      std::cout << "slow: " << slow << "\tfast: " << fast << "\tfastNext: " << fastNext << "\n";
      printList();
    }
  }
  return elements();
}