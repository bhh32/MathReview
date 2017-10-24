#pragma once

#include "Transform.h"
#include "Platform.h"
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

	Platform platforms[20];
	Piece player;
	mat3 cam;
	float groundHeight;
	Level();
	void InitLevel();
	void Update();
	void Draw();

private:

	unsigned int ground;
	unsigned int sky;
};