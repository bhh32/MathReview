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
	Controller controller;
	Sprite sprite;
};

class Wall
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

class Ball
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
};

bool DoCollision(Player &player, const Wall &wall, float elasticity =  1.f);
bool DoCollision(Ball &ball, const Wall &wall, float elasticity = 1.f);
bool DoCollision(Player &player, Ball &ball, float elasticity = 1.f);