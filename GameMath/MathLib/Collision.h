#pragma once

#include "mathutils.h"
#include <cmath>

struct Collision
{
	float penetrationDepth;
	float handedness;
};

Collision Intersect_1D(float Amin, float Amax, float Bmin, float Bmax);
