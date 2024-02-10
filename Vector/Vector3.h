#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef struct
{
    double x, y, z;
} Vector3d;

#include "Vector4.h"
#define LOG_VECTOR3D(v, LOG_FN) LOG_FN("%lf %lf %lf\n", (v).x, (v).y, (v).z)

double   Vector3dMagnitude(Vector3d a);
Vector3d Vector3dNormalize(Vector3d a);
Vector3d Vector3dAdd      (Vector3d a, Vector3d b);
Vector3d Vector3dSubtract (Vector3d a, Vector3d b);
Vector3d Vector3dMultiplyD(Vector3d a, double b);
Vector3d Vector3dDivideD  (Vector3d a, double b);
Vector3d Vector3dNegate   (Vector3d a);
double   Vector3dDot      (Vector3d a, Vector3d b);
Vector3d Vector3dCross    (Vector3d a, Vector3d b);

Vector4d Vector3dToVector4dHomogenous(Vector3d a);

double Vector3dIndex(Vector3d a, size_t i);
bool Vector3dEqual(Vector3d a, Vector3d b);

// Return (Vector3d) {a.x, a.y, 0}
Vector3d Vector3dZeroZ(Vector3d a);

