#pragma once

#include "Transform.h"

class Player
{
public:
	Player();

	Transform playerTransform;
	unsigned int playerSprite;

	void Draw();
	void DebugDraw(const mat3 &t, float drawing_scale);
	
};