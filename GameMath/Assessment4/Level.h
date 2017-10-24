#pragma once

#include "Transform.h"
#include "Platform.h"
#include "Piece.h"

class Level
{
public:
	Transform drawObject;
	Transform skyTrans;
	Transform coinTrans;
	Platform platforms[20];
	Piece player;

	float groundHeight;
	float coinPos;

	Level();
	void InitLevel();
	void Update();
	void Draw();

private:
	unsigned int ground;
	unsigned int sky;
	unsigned int coin;
	unsigned int string;
	unsigned int firework[8];

	bool isCollected;
};