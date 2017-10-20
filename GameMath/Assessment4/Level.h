#pragma once

#include "Transform.h"
#include "Piece.h"

class Level
{
public:
	Transform levelT;
	Piece player;

	Level();
	void InitLevel(Piece &player);
	void Update();
	void Draw();

private:

	unsigned int ground;
	unsigned int sky;
};