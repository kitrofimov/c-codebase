#pragma once

#define _USE_MATH_DEFINES
#include <math.h>

#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif

#define MIN(a, b) ( (a) < (b) ? (a) : (b) )
#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

#define CLAMP_MIN(min, val) ( ((val) < (min)) ? (min) : (val) )
#define CLAMP_MAX(max, val) ( ((val) > (max)) ? (max) : (val) )
#define CLAMP(min, max, val) \
	(\
		((val) < (min)) ? (min) : (\
			((val) > (max)) ? (max) : (val)\
		)\
	)

#define RAD(x) ((M_PI / 180) * (x))
#define DEG(x) ((180 / M_PI) * (x))

#define TOLERANCE 10e-6
#define ROUGHLY_EQUAL(a, b) (fabs((a) - (b)) < TOLERANCE)

