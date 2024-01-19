#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "DynamicArray.h"
#include "memoryUtils/memoryUtils.h"

DynamicArray* newDynamicArray(size_t nElements, size_t nBytesPerElement, freeCallbackFunctionType freeCallback)
{
    DynamicArray* this = xmalloc(sizeof(DynamicArray));
    this->data = xcalloc(nElements, nBytesPerElement);
    this->size = 0;
    this->allocated = nElements;
    this->nBytesPerElement = nBytesPerElement;
    this->freeCallback = freeCallback;
    return this;
}

static void reallocateDynamicArray(DynamicArray* this)
{
    this->data = xrealloc(this->data, (this->allocated * 2) * this->nBytesPerElement);
    this->allocated = this->allocated * 2;
}

void addToDynamicArray(DynamicArray* this, void* p_element)
{
    if (this->size+1 > this->allocated)
        reallocateDynamicArray(this);

    memcpy(indexVoidPointer(this->data, this->size, this->nBytesPerElement), p_element, this->nBytesPerElement);
    this->size += 1;
}

void deleteLastInDynamicArray(DynamicArray* this)
{
    this->size -= 1;
}

void deleteAllFromDynamicArray(DynamicArray* this)
{
    this->size = 0;
}

void setInDynamicArray(DynamicArray* this, void* p_element, size_t i)
{
    assert(i < this->size);
    memcpy(indexVoidPointer(this->data, i, this->nBytesPerElement), p_element, this->nBytesPerElement);
}

void* indexDynamicArray(DynamicArray* this, size_t i)
{
    assert(i < this->size);
    return indexVoidPointer(this->data, i, this->nBytesPerElement);
}

void freeDynamicArray(DynamicArray* this)
{
    if (this->freeCallback != NULL)
    {
        for (size_t i = 0; i < this->size; i++)
            this->freeCallback(indexDynamicArray(this, i));
    }
    xfree(this->data);
    xfree(this);
}

DynamicArray* copyDynamicArray(DynamicArray* this)
{
    DynamicArray* arr = newDynamicArray(this->allocated, this->nBytesPerElement, this->freeCallback);
    memcpy(arr->data, this->data, this->nBytesPerElement * this->size);
    arr->size = this->size;
    return arr;
}

void concatDynamicArray(DynamicArray* this, DynamicArray* other)
{
    assert(this->nBytesPerElement == other->nBytesPerElement);
    assert(this->freeCallback == other->freeCallback);
    for (size_t i = 0; i < other->size; i++)
        addToDynamicArray(this, indexDynamicArray(other, i));
}

