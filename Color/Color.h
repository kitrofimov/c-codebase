#pragma once
#include <stdint.h>

typedef struct
{
	uint8_t r, g, b, a;
} Color;

static inline uint32_t ColorToUint32RGBA(Color* pColor)
{
	return (uint32_t) pColor->r << 24 | (uint32_t) pColor->g << 16 | \
		   (uint32_t) pColor->b <<	8 | (uint32_t) pColor->a;
}

