#pragma once
#include <stdint.h>

typedef struct
{
    uint8_t r, g, b, a;
} Color;

static inline uint32_t ColorToUint32RGBA(Color color)
{
    return (uint32_t) color.r << 24 | (uint32_t) color.g << 16 |\
           (uint32_t) color.b << 8 | (uint32_t) color.a;
}

