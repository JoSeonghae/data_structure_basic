#include "mystack.h"
#include <cassert>

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