#include <assert.h>
#include "memoryUtils/memoryUtils.h"
#include "BitArray.h"

BitArray* newBitArray(size_t n_bits)
{
	BitArray* this = xmalloc(sizeof(BitArray));
	this->data = xmalloc(BitArraySizeInBytes(n_bits));
	this->size = n_bits;
	return this;
}

void BitArrayResize(BitArray* this, size_t new_n_bits)
{
	this->data = xrealloc(this->data, BitArraySizeInBytes(new_n_bits));
}

void freeBitArray(BitArray* this)
{
	xfree(this->data);
	xfree(this);
}

size_t BitArraySizeInBytes(size_t n_bits)
{
	if (n_bits % 8 == 0)
		return n_bits / 8;
	return n_bits / 8 + 1;
}

bool BitArrayGetBit(BitArray* this, size_t i)
{
	assert(this->size > i);
	return (this->data[i / 8] & (1 << (i % 8))) != 0;
}

void BitArraySetBit(BitArray* this, size_t i)
{
	assert(this->size > i);
	this->data[i / 8] |= (1 << (i % 8));
}

void BitArrayClearBit(BitArray* this, size_t i)
{
	assert(this->size > i);
	this->data[i / 8] &= ~(1 << (i % 8));
}

void BitArrayAnd(BitArray* a, BitArray* b, BitArray* out)
{
	assert(a->size == b->size);
	assert(a->size == out->size);

	for (size_t bytei = 0, nbytes = BitArraySizeInBytes(a->size); bytei < nbytes; bytei++)
		out->data[bytei] = a->data[bytei] & b->data[bytei];
}

void BitArrayOr(BitArray* a, BitArray* b, BitArray* out)
{
	assert(a->size == b->size);
	assert(a->size == out->size);

	for (size_t bytei = 0, nbytes = BitArraySizeInBytes(a->size); bytei < nbytes; bytei++)
		out->data[bytei] = a->data[bytei] | b->data[bytei];
}

void BitArrayXor(BitArray* a, BitArray* b, BitArray* out)
{
	assert(a->size == b->size);
	assert(a->size == out->size);

	for (size_t bytei = 0, nbytes = BitArraySizeInBytes(a->size); bytei < nbytes; bytei++)
		out->data[bytei] = a->data[bytei] ^ b->data[bytei];
}

void BitArrayNot(BitArray* a, BitArray* out)
{
	assert(a->size == out->size);

	for (size_t bytei = 0, nbytes = BitArraySizeInBytes(a->size); bytei < nbytes; bytei++)
		out->data[bytei] = ~a->data[bytei];
}

