#pragma once

#include "vec2.h"
#include "mat3.h"

struct Circle
{
	vec2 position;
	float radius;
};

// Axis Aligned Bounding Box
struct AABB
{
	vec2 position;
	vec2 extents;

	// Used to draw the bounding box
	vec2 minCorner;
	vec2 maxCorner;

	// Position width and height
	// Min and Max (Two Corners)
};

// Transform: position, rotation, scale
Circle operator*(const mat3 &M, const Circle &C);

AABB operator*(const mat3 &M, AABB &B);