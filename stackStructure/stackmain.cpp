#include "mystack.h"

void checkStack(MyStack stack){
  std::cout << "\nEmpty?: " << stack.isEmpty();
  std::cout << "\tSize(number of elements): " << stack.getSize();
  std::cout << "\tTop: " << stack.getTop() << "\n";
  stack.showStack();
}

int main(){
  int stackSize = 10;
  int numElements = 6;
  MyStack stack1(stackSize);
  checkStack(stack1);
  for(int i = 0; i < numElements; i++){
    stack1.push(2*i);
  }
  checkStack(stack1);
  int savedPop = stack1.pop();
  std::cout << savedPop << "\n";
  stack1.pop();
  checkStack(stack1);

  MyStack stack2(stackSize);
  int randomArr[] = {23,43,61,22,76,5,19,88,55,22};
  for(int i = 0; i < stackSize; i++){
    stack2.push(randomArr[i]);
  }
  std::cout << "\nThe Result of sortStackByTempStack\n";
  stack2.showStack();
  sortStackByTempStack(stack2, stackSize);
  // stack2 is pass by value, but the stackArr in stack2 is the pointer, so it stores the changed array.
  /* However, if stackArr in stack2 is converted from dynamic array in heap memory to static array, 
    stackArr is not passed into sortStackByTempStack function */
  stack2.showStack();
  std::cout << '\n';

  MyStack stack3(stackSize);
  int randomArr2[] = {21,76,81,12,76,5,19,88,1,32};
  for(int i = 0; i < stackSize; i++){
    stack3.push(randomArr2[i]);
  }

  std::cout << "\nThe Result of sortStackByRecursion\n";
  stack3.showStack();
  sortStackByTempStack(stack3, stackSize);
  stack3.showStack();
  std::cout << '\n';

  return 0;
}