#pragma once
#include <stdint.h>

#define INDEX_VOID_PTR(ptr, i, bytesPerElem) \
	((uint8_t*) (ptr) + (i) * (bytesPerElem))
#define VOID_PTR_ADD(ptr, increment) \
	((uint8_t*) (ptr) + (increment))

