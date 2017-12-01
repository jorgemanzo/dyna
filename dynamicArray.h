#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

/*
Definition of the dynamic array structure which will should a void double
pointer to an array of pointers, a size, and a capacity count.
*/
struct dynamicArray;

/*
Creates the dynamicArray structure on heap. No memory is allocated for the
array of pointers until the first element is pushed to the array.
*/
struct dynamicArray* dynamicCreate();

/*
Frees the contents of the dynamicArray structure including the array elements
but not what the elements point to.
*/
void dynamicFree(struct dynamicArray* array);

/*
Inserts a given value into a specific location within the dynamic dynamicArray
*/
void dynamicInsert(struct dynamicArray* array, int index, void* value);

/*
Removes a vlaue from a specified location within the dynamicArray. Leftover
values will collapse towards the left.
*/
void dynamicRemove(struct dynamicArray* array, int index);

/*
Returns a value from a specific location within the dynamicArray. Leftover
values will collapse towards the left.
*/
void* dynamicGet(struct dynamicArray* array, int index);

/*
Overwrites the specified location in the array with a given value
*/
void dynamicSet(struct dynamicArray* array, int index);

#endif
