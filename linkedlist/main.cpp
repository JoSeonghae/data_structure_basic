#include "LinkedList.h"

int main(){
  // std::srand(time(NULL));
  /*
  time(time_t)
  You can pass in a pointer to a time_t object that time will fill up with the current time 
  (and the return value is the same one that you pointed to).
  If you pass in NULL, it just ignores it and merely returns a new time_t object that represents the current time.
  */
  int size1 = 5;
  int size2 = 6;
  int linkedlistValues1[] = {2,2,5,2,2};
  int linkedlistValues2[] = {1,5,4,3,2,4};
  LinkedList list1;
  LinkedList list2;
  for(int i = 0; i < size1; i++){
    list1.insertAtTail(linkedlistValues1[i]);
  }
  for(int i = 0; i < size2; i++){
    list2.insertAtTail(linkedlistValues2[i]);
  }
  list1.printList();
  list1.removeDuplicates();
  list1.printList();
  
  list2.printList();
  list2.removeDuplicates();
  list2.printList();
  return 0;
}