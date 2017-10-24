#pragma once

#include "Transform.h"
#include "Platform.h"
#include "Piece.h"
#include <string>

class Level
{
public:
	Transform drawObject;
	Transform skyTrans;
	Transform coinTrans;
	Platform platforms[20];
	Piece player;

	std::string words;
	float groundHeight;
	float coinPos;
	int endAnimSpriteCount;
	float fireworkDelay;

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