#pragma once
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

#pragma pack(push, 1)
typedef struct
{
	double x, y, z, w;
} Vector4d;
#pragma pack(pop)

#include "Color/Color.h"
#include "Vector3.h"

double	 Vector4dMagnitude(Vector4d a);
Vector4d Vector4dNormalize(Vector4d a);
Vector4d Vector4dAdd	  (Vector4d a, Vector4d b);
Vector4d Vector4dSubtract (Vector4d a, Vector4d b);
Vector4d Vector4dMultiplyD(Vector4d a, double b);
Vector4d Vector4dDivideD  (Vector4d a, double b);
Vector4d Vector4dNegate	  (Vector4d a);
double	 Vector4dDot	  (Vector4d a, Vector4d b);
Vector3d Vector4dHomogenousDivide(Vector4d a);

// [0.0, 1.0] => [0, 255]
Color Vector4dToColor(Vector4d a);

static inline double Vector4dIndex(Vector4d* a, size_t i)
{
	assert(i <= 3);
	return ((double*) a)[i];
}

bool Vector4dEqual(Vector4d a, Vector4d b);

