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

	vec2 getGlobalPosition() const;
	void setGlobalPosition(const vec2 &pos);

	vec2 getGlobalScale() const;
	void setGlobalScale(const vec2 &dim);


	void setParent(Transform *p = nullptr);

	// Draws Texture from GlobalTransform()
	void DrawTexture(unsigned sprite, const mat3 &t);
};

// Used for debugging
void DrawMatrix(const mat3 &t, float drawing_scale);



// On grounding:
	// parent our transform to the ground but keep the global position the same
		// which means we have to convert from our current local space to the
		// platform's local space

// player.Local -> global -> platform.local