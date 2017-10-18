#pragma once

#include "vec2.h"
#include "mat3.h"

class Transform
{
public:
	vec2 position;
	vec2 demension;
	float angle;

	Transform();

	mat3 GetLocalTransform();
};

// Used for debugging
void DrawMatrix(const mat3 &t, float drawing_scale);