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

bool DoCollision(Player &player, const Wall &wall);