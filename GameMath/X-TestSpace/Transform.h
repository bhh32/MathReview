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


	Transform();
	Transform(vec2 position, vec2 demension, float angle);

	mat3 GetLocalTransform() const;
	mat3 GetGlobalTransform() const;

	

	// Draws Texture from GlobalTransform()
	void DrawTexture(unsigned sprite, const mat3 &t);
};

// Used for debugging
void DrawMatrix(const mat3 &t, float drawing_scale);

