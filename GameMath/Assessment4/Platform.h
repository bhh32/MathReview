#pragma once

#include "Transform.h"
class Platform
{
public:
	Platform();
	Transform transform;

	float GetGroundHeight();
	void SetGroundHeight(float groundHeight);

	vec2 GetBounds();
	void SetBounds(float leftBound, float rightBound);
private:
	float groundHeight;
	float leftBound;
	float rightBound;
};