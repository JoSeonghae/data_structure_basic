#include "mystack.h"

MyStack sortStackByTempStack(MyStack stack, int size){
  MyStack tempStack(size);
  while(!stack.isEmpty()){
    int value = stack.pop();
    if(tempStack.isEmpty()){
      tempStack.push(value);
    } else {
      while(!tempStack.isEmpty() && value < tempStack.getTop()){
        stack.push(tempStack.pop());
      }
      tempStack.push(value);
    }
  }
  while(!tempStack.isEmpty()){
    stack.push(tempStack.pop());
  }
  return stack;
}

void sortStackByRecursion(MyStack *stack){
  if(!stack->isEmpty()){
    int value = stack->pop();
    sortStackByRecursion(stack);
    insertForSortStackByRecursion(stack, value);
  }
}

void insertForSortStackByRecursion(MyStack *stack, int value){
  if(stack->isEmpty() || value < stack->getTop()){
    stack->push(value);
  } else {
    int temp = stack->pop();
    insertForSortStackByRecursion(stack, value);
    stack->push(temp);
  }
}