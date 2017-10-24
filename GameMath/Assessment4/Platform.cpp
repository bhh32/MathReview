#include "Platform.h"

Platform::Platform()
{
	transform.position = vec2{ 400, 0 };
	transform.demension = vec2{ 256, 18 };
}

float Platform::GetGroundHeight()
{
	return groundHeight;
}

void Platform::SetGroundHeight(float groundHeight)
{
	this->groundHeight = groundHeight;
}

vec2 Platform::GetBounds()
{
	return vec2{ leftBound, rightBound };
}

void Platform::SetBounds(float leftBound, float rightBound)
{
	this->leftBound = leftBound;
	this->rightBound = rightBound;
}
