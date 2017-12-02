
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
  int* temp;
  test.numbers = (int*) malloc(sizeof(int) * 10);

  for(int i = 0; i < 10; i++){
    test.numbers[i] = i;
  }

  myArray = dynamicCreate();
  //Inserting numbers 1 to 9 into the array
  for(int i = 0; i < 10; i++){
    temp = &(test.numbers[i]);
    dynamicInsert(myArray, i, temp);
    printf("Inserting At myArray[%d] : %d\n", i, *(int*)dynamicGet(myArray,i));
  }

  //Removing values from index 0 to 4
  for(int i = 0; i < 5; i++){
    printf("Removing At myArray[%d] : %d\n", 0, *(int*)dynamicGet(myArray,0));
    dynamicRemove(myArray, 0);
  }

  //Inserting different values in index 0 to 4
  for(int i = 0; i < 5; i++){
    temp = &(test.numbers[5 - i]);
    dynamicInsert(myArray, 0, temp);
    printf("Inserting At myArray[%d] : %d\n", 0, *(int*)dynamicGet(myArray,0));
  }

  //Removing the contents of the array
  for(int i = 0; i < 10; i++){
    printf("Removing At myArray[%d] : %d\n", 0, *(int*)dynamicGet(myArray,i));
    dynamicRemove(myArray, 0);
  }

  dynamicFree(myArray);
  free(test.numbers);
  return 0;
}
