#pragma once
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    uint8_t* data;
    size_t size;  // in bits
} BitArray;

BitArray* newBitArray(size_t n_bits);
void BitArrayResize(BitArray* this, size_t new_n_bits);
void freeBitArray(BitArray* this);

size_t BitArraySizeInBytes(size_t n_bits);

bool BitArrayGetBit(BitArray* this, size_t i);
void BitArraySetBit(BitArray* this, size_t i);
void BitArrayClearBit(BitArray* this, size_t i);

void BitArrayAnd(BitArray* a, BitArray* b, BitArray* out);
void BitArrayOr(BitArray* a, BitArray* b, BitArray* out);
void BitArrayXor(BitArray* a, BitArray* b, BitArray* out);
void BitArrayNot(BitArray* a, BitArray* out);

