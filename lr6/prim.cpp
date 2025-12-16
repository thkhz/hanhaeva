#include "prim.h"
#include <cmath>
#include <algorithm> 

float prim(float x, float y) {
	float r = sqrtf(x * x + y * y) / expf(logf(x));
	float s = powf(cosf(3.14f / 4.0f * x), 2.0f);
	float c = std::max(r, s);
	return c;
}