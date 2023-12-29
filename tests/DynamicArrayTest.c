#include <assert.h>
#include <string.h>
#include <strings.h>
#include "DynamicArray/DynamicArray.h"
#include "memoryUtils/memoryUtils.h"

typedef struct __attribute__((packed))
{
    int a;
    double b;
} TestStruct;

// Test basic functions for integers
void testBasicInt()
{
    DynamicArray* arr = newDynamicArray(3, sizeof(int), NULL);
    assert(arr->size == 0);
    assert(arr->allocated == 3);
    assert(arr->nBytesPerElement == sizeof(int));

    addToDynamicArray(arr, &(int) {4});
    addToDynamicArray(arr, &(int) {6});
    addToDynamicArray(arr, &(int) {2});
    assert(arr->size == 3);
    assert(arr->allocated == 3);

    addToDynamicArray(arr, &(int) {1});
    addToDynamicArray(arr, &(int) {9});
    assert(arr->size == 5);
    assert(arr->allocated == 6);

    int expected[5] = {4, 6, 2, 1, 9};
    assert(memcmp(arr->data, (void*) expected, sizeof(expected)) == 0);

    deleteLastInDynamicArray(arr);
    assert(arr->size == 4);
    assert(*(int*) indexDynamicArray(arr, 0) == 4);
    assert(*(int*) indexDynamicArray(arr, 1) == 6);
    assert(*(int*) indexDynamicArray(arr, 3) == 1);

    setInDynamicArray(arr, &(int) {727}, 1);
    assert(*(int*) indexDynamicArray(arr, 1) == 727);

    freeDynamicArray(arr);
}

// Test basic functions for a structure
void testBasicStruct()
{
    DynamicArray* arr = newDynamicArray(3, sizeof(TestStruct), NULL);
    assert(arr->size == 0);
    assert(arr->allocated == 3);
    assert(arr->nBytesPerElement == sizeof(TestStruct));

    addToDynamicArray(arr, &(TestStruct) {1, 4.3});
    addToDynamicArray(arr, &(TestStruct) {4, 6.2});
    addToDynamicArray(arr, &(TestStruct) {9, 2.3});
    assert(arr->size == 3);
    assert(arr->allocated == 3);

    addToDynamicArray(arr, &(TestStruct) {5, 1.7});
    addToDynamicArray(arr, &(TestStruct) {16, 9.1});
    assert(arr->size == 5);
    assert(arr->allocated == 6);

    TestStruct expected[5] = {
        {1, 4.3}, {4, 6.2}, {9, 2.3}, {5, 1.7}, {16, 9.1}
    };
    assert(memcmp(arr->data, (void*) expected, sizeof(expected)) == 0);

    deleteLastInDynamicArray(arr);
    assert(arr->size == 4);
    TestStruct a = *(TestStruct*) indexDynamicArray(arr, 0);
    assert(a.a == 1);
    assert(a.b == 4.3);
    a = *(TestStruct*) indexDynamicArray(arr, 1);
    assert(a.a == 4);
    assert(a.b == 6.2);
    a = *(TestStruct*) indexDynamicArray(arr, 3);
    assert(a.a == 5);
    assert(a.b == 1.7);

    setInDynamicArray(arr, &(TestStruct) {727, 727.2}, 1);
    a = *(TestStruct*) indexDynamicArray(arr, 1);
    assert(a.a == 727);
    assert(a.b == 727.2);

    freeDynamicArray(arr);
}

static void freeCallback(void* p_p_int)
{
    xfree(*(int**) p_p_int);
}

// Test the free callback functionality
void testFreeCallback()
{
    DynamicArray* arr = newDynamicArray(3, sizeof(int*), freeCallback);

    for (size_t i = 0; i < 10; i++)
    {
        int* elem = xmalloc(sizeof(int));
        *elem = 5;
        addToDynamicArray(arr, &elem);
    }

    freeDynamicArray(arr);
}

// Test `copyDynamicArray`
void testCopy()
{
    const int N = 4;
    DynamicArray* arr = newDynamicArray(N, sizeof(int), NULL);
    
    addToDynamicArray(arr, &(int) {1});
    addToDynamicArray(arr, &(int) {2});
    addToDynamicArray(arr, &(int) {3});
    addToDynamicArray(arr, &(int) {4});

    DynamicArray* copyArr = copyDynamicArray(arr);

    assert(copyArr->nBytesPerElement == arr->nBytesPerElement);
    assert(copyArr->size == arr->size);
    assert(copyArr->allocated == arr->allocated);
    assert(copyArr->freeCallback == arr->freeCallback);

    for (size_t i = 0; i < N; i++)
        assert(*(int*) indexDynamicArray(arr, i) == *(int*) indexDynamicArray(copyArr, i));
}

// Test `concatDynamicArray`
void testConcat()
{
    DynamicArray* arr1 = newDynamicArray(3, sizeof(int), NULL);
    DynamicArray* arr2 = newDynamicArray(4, sizeof(int), NULL);
    
    for (int i = 0; i < 4; i++)
    {
        if (i < 3)
            addToDynamicArray(arr1, &i);
        addToDynamicArray(arr2, &i);
    }

    concatDynamicArray(arr1, arr2);

    assert(arr1->size == 7);
    assert(arr1->nBytesPerElement == arr2->nBytesPerElement && arr1->nBytesPerElement == sizeof(int));
    assert(arr1->freeCallback == arr2->freeCallback && arr1->freeCallback == NULL);

    assert(arr2->size == 4);
    assert(arr2->allocated == 4);
    assert(arr2->nBytesPerElement == sizeof(int));
    assert(arr2->freeCallback == NULL);
}

int main()
{
    testBasicInt();
    testBasicStruct();
    testFreeCallback();
    testCopy();
    testConcat();
}
