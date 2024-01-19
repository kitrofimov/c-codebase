#pragma once
#include <stddef.h>

#define indexVoidPointer(ptr, i, nBytesPerElement) ((char*) ptr + (i * nBytesPerElement))

// Wrapper functions for standard memory allocation functions,
// but with error handling (abort if NULL)

void* xmalloc(size_t n);
void* xrealloc(void* ptr, size_t new_n);
void* xcalloc(size_t n_elem, size_t n_bytes);
void xfree(void* ptr);

