#pragma once

#include "Transform.h"
class Platform
{
public:
	Platform();
	Transform transform;

	float GetGroundHeight();

private:
	float groundHeight;
};