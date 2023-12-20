#include "Color.h"

Color colorMultiplyByScalar(Color this, double scalar)
{
    return (Color) {
        (uint8_t) this.r * scalar, 
        (uint8_t) this.g * scalar,
        (uint8_t) this.b * scalar,
        (uint8_t) this.a * scalar
    }
}

Vector4d ColorToVector4d(Color color)
{
    return (Vector4d) {
        color.r,
        color.g,
        color.b,
        color.a
    };
}

