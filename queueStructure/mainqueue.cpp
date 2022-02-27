#include "myqueue.h"
#include <string>

// std::string* findBin(int n) {
//     std::string *result = new std::string[n];
//     MyQueue currentQueue;
//     result[0] = std::to_string(currentQueue.enqueue(1)); 
//     int arrCount = 0;
//     int prevEnqueueCount = 1;
//     int currentEnqueueCount = 0;
//     int temp;
//     while(arrCount < n){
//         while(prevEnqueueCount > 0 && arrCount < n){
//             temp = currentQueue.dequeue();
//             result[arrCount++] = std::to_string(currentQueue.enqueue(temp*10));
//             if(arrCount >= n){
//                 break;
//             }
//             result[arrCount++] = std::to_string(currentQueue.enqueue(temp*10 + 1));
//             // prevEnqueueCount = currentDequeueCount
//             prevEnqueueCount--;
//             currentEnqueueCount += 2;
//         }
//         prevEnqueueCount = currentEnqueueCount;
//         currentEnqueueCount = 0;
//     }
//     return result;
// }

std::string* findBin(int n){
  std::string *result = new std::string[n];
  MyQueue queue;
  queue.enqueue(1);
  std::string s1, s2;
  for(int i = 0; i < n; i++){
    result[i] = std::to_string(queue.dequeue());
    s1 = result[i] + "0";
    s2 = result[i] + "1";
    queue.enqueue(std::stoi(s1));
    queue.enqueue(std::stoi(s2));
  }
  return result;
}

int main(){
  MyQueue q;
  for(int i = 1; i <= 5; i++){
    std::to_string(q.enqueue(i));
    q.showQueue();
  }
  std::cout << "Front: " << q.getFront() << "\n";
  std::cout << "Back: " << q.getBack() << "\n";
  std::cout << "Size: " << q.getSize() << "\n";
  // while(q.isEmpty() == false){
  //   q.dequeue();
  //   q.showQueue();
  // } 
  q.dequeue();
  q.showQueue();

  int decimal = 11;
  std::string* binaryArr = findBin(decimal);
  for(int i = 0; i < decimal; i++){
    std::cout << binaryArr[i] << "\n";
  }
  // delete binaryArr; // print: munmap_chunk(): invalid pointer. Aborted

  return 0;
}