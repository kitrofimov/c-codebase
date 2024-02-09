#pragma once
#include <stdint.h>

typedef struct
{
    uint8_t r, g, b, a;
} Color;

uint32_t ColorToUint32RGBA(Color color);

