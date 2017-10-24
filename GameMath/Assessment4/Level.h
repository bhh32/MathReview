#pragma once

#include "Transform.h"
#include "Piece.h"

class Level
{
public:
	Transform drawObject;
	vec2 camTarget;
	Transform skyTrans;
	Transform platform1;
	Transform platform2;
	Transform platform3;
	Transform platform4;
	Transform platform5;

	Transform platforms[20];
	Piece player;
	mat3 cam;

	Level();
	void InitLevel(Piece &player);
	void Update();
	void Draw();

private:

	unsigned int ground;
	unsigned int sky;
};