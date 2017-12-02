
#include "dynamicArray.h"

struct testNums{
  int* numbers;
};

int main(){
  struct dynamicArray* myArray;
  struct testNums test;
  test.numbers = (int) malloc(sizeof(int) * 10);

  for(int i = 0; i < 10; i++){
    test.numbers[i] = i;
  }

  myArray = dynamicCreate();

  dynamicFree(myArray);
  return 0;
}
