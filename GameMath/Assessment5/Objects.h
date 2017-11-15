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

	class Platform *current = nullptr;
	float gravity = -9.8f;
	bool isGrounded;
	bool isOnPlatform;
	bool endGame = false;
};

class Goal
{
public:
	Transform transform;
	Collider collider;
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
	bool isMovingDown; // Only used for special case platforms
	bool isMovingRight;
	bool isMovingLeft; // Only used for special case platforms
	float minPosX;
	float maxPosX;
	float midPosX;     // Only used for special case platforms
	float minPosY;
	float maxPosY;
	float speed;

	void InitStaticPlatforms(Platform &platform);
	void InitHorizontalPlatforms(Platform &platform);
	void InitVerticalPlatforms(Platform &platform);
	void InitUpRightPlatforms(Platform &platform);
	void InitUpLeftPlatforms(Platform &platform);
	void InitMultiDirPlatforms(Platform &platform);
};

bool DoCollision(Player &player, const Wall &wall, float elasticity = 1.f);
bool DoCollision(Player &player, Goal &goal, float elasticity = 0.f);
bool DoCollision(Player &player, const Platform &platform, float elasticity = 1.f);
bool DoCollisionMoving(Player &player, Platform &platform, float elasticity = 1.f);
bool GravityTestCollision(Player &player, const Wall &wall, const Platform &platform);