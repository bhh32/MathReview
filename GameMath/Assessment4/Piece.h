#pragma once

#include "Transform.h"

class Piece
{
public:

	Piece() {};
	virtual void InitPiece();
	virtual void Update();
	virtual void Draw();

	int groundHeight;
	
protected:
	
	Transform pieceTransform;
	unsigned int pieceBlock;
	bool isJumping;
	float gravity;
	float jumpDelay;
	int jumpHeight;
	bool isMaxHeight;
};