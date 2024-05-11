#pragma once
#include <stddef.h>
#include <stdbool.h>
#include <assert.h>

#pragma pack(push, 1)
typedef struct
{
	double x, y, z;
} Vector3d;
#pragma pack(pop)

#include "Vector4.h"

double	 Vector3dMagnitude(Vector3d a);
Vector3d Vector3dNormalize(Vector3d a);
Vector3d Vector3dAdd	  (Vector3d a, Vector3d b);
Vector3d Vector3dSubtract (Vector3d a, Vector3d b);
Vector3d Vector3dMultiplyD(Vector3d a, double b);
Vector3d Vector3dDivideD  (Vector3d a, double b);
Vector3d Vector3dNegate	  (Vector3d a);
double	 Vector3dDot	  (Vector3d a, Vector3d b);
Vector3d Vector3dCross	  (Vector3d a, Vector3d b);

Vector4d Vector3dToVector4dHomogenous(Vector3d a);

static inline double Vector3dIndex(Vector3d* a, size_t i)
{
	assert(i <= 2);
	return ((double*) a)[i];
}

bool Vector3dEqual(Vector3d a, Vector3d b);

// Return (Vector3d) {a.x, a.y, 0}
Vector3d Vector3dZeroZ(Vector3d a);

