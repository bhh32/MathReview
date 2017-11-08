#pragma once

#include "mathutils.h"
#include "Shapes.h"
#include <cmath>

struct Collision
{
	float penetrationDepth; // If penetration depth is negative, that's the distance
	float handedness;  // Does A need to move left or right along the axis
	vec2 axis;
	float elasticity = 1.0f;
};

Collision Intersect_1D(float Amin, float Amax, float Bmin, float Bmax);

Collision Intersect_AABB(const AABB &A, const AABB &B);

Collision Intersect_Circle(const Circle &A, const Circle &B);

Collision Intersect_AABB_Circle(const AABB &A, const Circle &B);

                            // InOut Variables
void Static_Resolution(vec2 &pos, vec2 &velocity, const Collision &hit, float elasticity = 0.0f);

void Dynamic_Resolution(vec2 &Apos, vec2 &Avelocity, float Amass, 
	                    vec2 &Bpos, vec2 &Bvelocity, float Bmass, 
	                    const Collision &hit, float elasticity = 1.0f);
