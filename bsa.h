#ifndef BSA_H
#define BSA_H

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include dynamicArray.h
#endif

/*
Inserts a pointer to an int into a dyna array. Insertion is performed by finding Inserts
its proper location compared to it's neighbors using a binary search (log n). If
a value of an equal quantity is found, it will be inserted before it.
*/
void bsa_insert(int* value, struct dynamicArray* myArray);

/*
Searches for a provided value in a specified dyna array. If found, its value will be
returned but not removed. The value returned will be an int. If not found, the value
returned will be -1.
*/
int bsa_search(int* value, struct dynamicArray* myArray);

/*
Searches for a provided value in a specified dyna array to be removed. If found,
its value will be returned and removed from the array. The value returned will be
an int. If not found, the value returned will be -1.
*/
int bsa_searchAndDestroy(int* value,  struct dynamicArray* myArray);

#endif
