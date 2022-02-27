#include <iostream>

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

MyStack sortStackByTempStack(MyStack stack, int size);
void sortStackByRecursion(MyStack *stack);
void insertForSortStackByRecursion(MyStack *stack, int value);