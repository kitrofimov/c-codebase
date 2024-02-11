#include <assert.h>
#include "BitArray/BitArray.h"

void test()
{
    BitArray* arr = newBitArray(16);

    BitArraySetBit(arr, 0);
    BitArraySetBit(arr, 1);
    BitArraySetBit(arr, 6);
    BitArraySetBit(arr, 9);
    BitArraySetBit(arr, 13);
    BitArraySetBit(arr, 14);

    assert(arr->data[0] == 0b01000011);
    assert(arr->data[1] == 0b01100010);

    BitArrayClearBit(arr, 0);
    BitArrayClearBit(arr, 1);

    assert(arr->data[0] == 0b01000000);
    assert(BitArrayGetBit(arr, 13) == true);
    assert(BitArrayGetBit(arr, 1) == false);

    freeBitArray(arr);
}

int main()
{
    test();
}

