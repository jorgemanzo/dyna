
#include "dynamicArray.h"


int main(){
  struct dynamicArray* myArray;
  myArray = dynamicCreate();

  dynamicFree(myArray);
  return 0;
}
