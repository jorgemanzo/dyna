#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "dynamicArray.h"
#endif

int main(){
  struct dynamicArray* myArray;
  myArray = dynamicCreate();

  dynamicFree(myArray);
  return 0;
}
