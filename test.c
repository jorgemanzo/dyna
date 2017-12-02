
#include "dynamicArray.h"

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

struct testNums{
  int* numbers;
};

int main(){
  struct dynamicArray* myArray;
  struct testNums test;
  test.numbers = (int*) malloc(sizeof(int) * 10);

  for(int i = 0; i < 10; i++){
    test.numbers[i] = i;
  }

  myArray = dynamicCreate();
  for(int i = 0; i < 10; i++){
    dynamicInsert(myArray, i, test.numbers[i]);
  }

  for(int i = 0; i < 10; i++){
    printf("At myArray[%d] : %d\n", i, *(int*)dynamicGet(myArray,i));
  }

  dynamicFree(myArray);
  free(test.numbers);
  return 0;
}
