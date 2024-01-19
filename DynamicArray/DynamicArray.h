#pragma once
#include <stddef.h>

/**
 * NOTE: It is absolutely safe to `addToDynamicArray` values allocated on the stack. What this function (and every other function manipulating the array) does is it copies the data pointed by a pointer passed to a function. So the following code is safe:
 * int a = 6;
 * addToDynamicArray(arr, &a);
 */

typedef void (*freeCallbackFunctionType)(void*);

typedef struct
{
    void* data;
    size_t size;
    size_t allocated;
    size_t nBytesPerElement;
    // callback function called by `freeDynamicArray` on every element of the array. Argument type is a pointer to the stored type
    freeCallbackFunctionType freeCallback;
} DynamicArray;

// The buffer is zeroed
DynamicArray* newDynamicArray(
    size_t nElements, size_t nBytesPerElement, 
    freeCallbackFunctionType freeCallback
);
void freeDynamicArray(DynamicArray* this);
void reallocateDynamicArray(DynamicArray* this, size_t n);

// Copy the value pointed to by `p_element` as the new value of the array
void addToDynamicArray(DynamicArray* this, void* p_element);
void deleteLastInDynamicArray(DynamicArray* this);
void deleteAllFromDynamicArray(DynamicArray* this);
// Copy the value pointed to by `p_element` as the `i`th value of the array
void setInDynamicArray(DynamicArray* this, void* p_element, size_t i);
void* indexDynamicArray(DynamicArray* this, size_t i);

DynamicArray* copyDynamicArray(DynamicArray* this);

// Concatenate two dynamic arrays. All the elements of the second array are added to the first one. The second array is unchanged.
// ARRAYS SHOULD STORE THE SAME TYPES AND HAVE SAME FREE CALLBACKS
void concatDynamicArray(DynamicArray* this, DynamicArray* other);

