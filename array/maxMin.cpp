#include <iostream>
using namespace std;

void maxMin(int arr[], int size) {
  int newArr[size];
  int maxcount = size-1;
  int mincount = 0;
  for(int i = 0; i < size; i++){
    if(i % 2 == 0){
      newArr[i] = arr[maxcount];
      maxcount--;
    } else if(i % 2 == 1) {
      newArr[i] = arr[mincount];
      mincount++;
    }
  }
  for(int i = 0; i < size; i++){
    arr[i] = newArr[i];
  }
}

int main(){
  int size1 = 7;
  int arr1[] = {12,23,34,45,56,67,78};

  int size2 = 7;
  int arr2[] = {-22, -11,1,22, 33, 43,55};

  maxMin(arr1, size1);
  for(int i = 0; i < size1; i++){
    cout << arr1[i] << endl;
  }
  return 0;
}