#include <iostream>
#include "Piece.h"
#include <sstream>
#include "sfwdraw.h"

void Piece::InitPiece()
{
	
	pieceTransform.demension = vec2{ 18, 18 };
	pieceTransform.angle = 0;
	pieceBlock = sfw::loadTextureMap("res/blueBlock.png");
	groundHeight = 18.f;
	

	
	gravity = vec2{ 0.f ,-9.8f };
	isJumping = false;
	isMaxHeight = false;
	
	
	pieceTransform.position = vec2{ 400, 100 };
	
	forward = pieceTransform.position.Normal();
	up = vec2{ 0.f, 75.f * forward.y };
	speed = vec2{ 5.f * forward.x, 0.f };
	jumpDelay = 10.f;
	
}

void Piece::Update()
{
	// Debug for player xy position
	std::cout << "(" << pieceTransform.position.x << ", " << pieceTransform.position.y << ")" << std::endl;
	pieceBottom = pieceTransform.position.y - (pieceTransform.demension.y / 2);
	jumpHeight = groundHeight + 70;

	if (!isMaxHeight)
	{
		if (sfw::getKey('W') && !isMaxHeight)
		{
			if (pieceTransform.position.y <= jumpHeight)
			{				
				pieceTransform.position += up;
				isJumping = true;
			}

			if (pieceTransform.position.y >= jumpHeight)
			{
				isMaxHeight = true;
				jumpDelay = 10.f;
			}

		}
	}
	else if(isMaxHeight)
	{
		if (jumpDelay <= 0 && isMaxHeight)
		{
			isMaxHeight = false;
			isJumping = false;
		}
	}

	if (isMaxHeight)
		jumpDelay -= 1.f;

	if (sfw::getKey('D'))
		pieceTransform.position += speed;

	if (sfw::getKey('A'))
		pieceTransform.position -= speed;

	if (pieceTransform.position.y - 9 > groundHeight)
		pieceTransform.position += gravity;
	else
		pieceTransform.position.y = groundHeight + 9.f;

}

void Piece::Draw()
{
	sfw::drawTexture(pieceBlock, pieceTransform.position.x, pieceTransform.position.y, 18, 18, pieceTransform.angle);
}

void Piece::SetGroundHeight(float groundHeight)
{
	this->groundHeight = groundHeight;
}

float Piece::GetGroundHeight()
{
	return groundHeight;
}


