#include "myqueue.h"

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
