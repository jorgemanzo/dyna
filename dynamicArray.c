#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include "dynamicArray.h"
#endif

#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif

/*
Structure definition of the Dynamic array
*/
struct dynamicArray{
  void** contents;
  int size;
  int capacity;
};

/*
Function to place the dynamicArray type on the heap
*/
struct dynamicArray* dynamicCreate(){
  //Allocate the struct on the heap
  struct dynamicArray* temp = (struct dynamicArray*) malloc(sizeof(struct dynamicArray));

  //set its contens to default values
  temp->contents = NULL;
  temp->size = 0;
  temp->capacity = 0;

  return temp;
}

/*
Frees the contents of the dynamicArray structure including whatever array
points to but not what the contents of the array may point to.
*/
void dynamicFree(struct dynamicArray* array){
  free(array->contents);
  free(array);
}



/*
Returns a value from a specified index in the array without removing it from
the array itself. -1 for an index will return the value at the end of the array
*/
void* dynamicGet(struct dynamicArray* array, int index){
  //if the requested index is beyond the capacity, exit the program
  if(index > array->capacity){
    printf("EXIT AT 53\n")
    exit(1);
  }
  //if the requested index is the end of the array
  if(index == -1){
    return array->contents[-1];
  }
  //return the requested index's contents
  return array->contents[index];
}


/*
Helper function. This will grow the size of the array by 2x the capacity,
copying values over from the old array to the new array.
*/
void dynamicResize(struct dynamicArray* array){
  int newCapacity;
  if(array->capacity == 0){
    //if the capacity is at 0 grow it to 1;
    newCapacity = 1;
    array->capacity = 1;
  }
  else{
    //Define newCapcity as twice that of the original Capacity
    newCapacity = array->capacity * 2;
  }

  //Allocate a new void pointer to point to an array of void pointers
  void** temp;
  temp = (void*) malloc(sizeof(void*) * newCapacity);

  //if the array capacity is 1, this means that the old array had
  //no contents at all that need to be copied
  if(array->capacity != 1){
  //Copy the elements from the original array to the new array
    for(int i = 0; i < array->capacity; i++){
      temp[i] = dynamicGet(array,i);
    }
  }
  //For the remaining empty spaces, fill them with NULLs
  for(int i = array->capacity; i < newCapacity; i++){
    temp[i] = NULL;
  }
  //Free what contents points to in the array.
  free(array->contents);
  //Point the contents pointer to what temp points to.
  array->contents = temp;

  temp = NULL;
}


/*
Helper function: overwrites the array at a given index with a specified
value
*/
void dynamicSet(struct dynamicArray* array, int index, void* value){
  //if index is bounded by the capcity of the array
  if(index < array->capacity){
    array->contents[index] = value;
  }
  //else the index was not bounded, so exit
  else{
    printf("EXIT AT 116\n")
    exit(1);
  }
}

/*
Helper function: shifts values at index and greater to the right
by one array index
*/
void dynamicShift(struct dynamicArray* array, int index){
  for(int i = array->capacity - 1; i >= index; i--){
    //overwrite the contents at i with the contents of i - 1
    dynamicSet(array, i, dynamicGet(array, i - 1));
  }
}

/*
Inserts a specified value into an index of the array's contents, pushing
all latter values forward. -1 for an index will isnert to the end of an
array.
*/
void dynamicInsert(struct dynamicArray* array, int index, void* value){
  //if the array's size is at capacity, resize the array
  if(array->size == array->capacity){
    dynamicResize(array);
  }
  //if the array at index is already occupied, we need to shift all elements
  //greater than index to the right by one space.
  if(dynamicGet(array,index) != NULL){
    dynamicShift(array, index);
  }

  //set the index to a specific value
  dynamicSet(array, index, value);
}
