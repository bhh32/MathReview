#pragma once

#include "Transform.h"

class Piece
{
public:
	Transform pieceTransform;

	Piece() {};
	virtual void InitPiece();
	virtual void Update();
	virtual void Draw();

	int groundHeight;
	
protected:
	
	
	vec2 forward;
	vec2 up;
	vec2 speed;
	vec2 gravity;
	unsigned int pieceBlock;
	bool isJumping;
	
	float jumpDelay;
	int jumpHeight;
	bool isMaxHeight;
};