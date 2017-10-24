#pragma once

#include "vec2.h"
#include "mat3.h"

class Transform
{
public:
	vec2 position;
	vec2 demension;
	float angle;
	Transform *e_parent;


	Transform() {};
	Transform(vec2 position, vec2 demension, float angle);

	mat3 GetLocalTransform() const;
	mat3 GetGlobalTransform() const;

	// Used for debugging
	virtual void DrawMatrix(const mat3 &t, float drawing_scale);
	void DrawTexture(unsigned sprite, const mat3 &t);
};

