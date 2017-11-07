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

	bool isGrounded;
	bool isOnPlatform;
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
	float minPosX;
	float maxPosX;
	float minPosY;
	float maxPosY;
	float speed;

	void InitStaticPlatforms(Platform &platform);
	void InitHorizontalPlatforms(Platform &platform);
	void InitVerticalPlatforms(Platform &platform);
	void InitUpRightPlatforms(Platform &platform);
	void InitUpLeftPlatforms(Platform &platform);
};

bool DoCollision(Player &player, const Wall &wall, float elasticity = 1.f);
bool DoCollision(Player &player, const Platform &wall, float elasticity = 1.f);
