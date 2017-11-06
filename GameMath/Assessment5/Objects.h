#pragma once

#include "Transform.h"
#include "Rigidbody.h"
#include "Collider.h"
#include "Controller.h"
#include "Sprite.h"

class Player
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	PlayerController controller;
	Sprite sprite;
};

class Wall
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

class Platform
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	PlatformController controller;
	Sprite sprite;
	bool isSoftPlatform;
	bool isMovingUp;
	bool isMovingRight;

	void InitStaticPlatforms(Platform &platform);
};


bool DoCollision(Player &player, const Wall &wall, float elasticity = 1.f);
bool DoCollision(Player &player, const Platform &wall, float elasticity = 1.f);
