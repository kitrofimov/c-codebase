#pragma once
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

#pragma pack(push, 1)
typedef struct
{
    int x, y;
} Vector2i;

typedef struct
{
    double x, y;
} Vector2d;
#pragma pack(pop)

double   Vector2dMagnitude(Vector2d a);
Vector2d Vector2dNormalize(Vector2d a);
Vector2d Vector2dAdd      (Vector2d a, Vector2d b);
Vector2d Vector2dSubtract (Vector2d a, Vector2d b);
Vector2d Vector2dMultiplyD(Vector2d a, double b);
Vector2d Vector2dDivideD  (Vector2d a, double b);
Vector2d Vector2dNegate   (Vector2d a);
double   Vector2dDot      (Vector2d a, Vector2d b);
Vector2i Vector2dRound    (Vector2d a);
Vector2i Vector2dFloor    (Vector2d a);

static inline double Vector2dIndex(Vector2d* a, size_t i)
{
    assert(i <= 1);
    return ((double*) a)[i];
}

bool Vector2dEqual(Vector2d a, Vector2d b);

Vector2i Vector2iAdd(Vector2i a, Vector2i b);

