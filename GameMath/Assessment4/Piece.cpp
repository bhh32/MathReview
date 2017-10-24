#include <iostream>
#include "Piece.h"
#include <sstream>
#include "sfwdraw.h"

void Piece::InitPiece()
{
	pieceTransform.position = vec2{ 400, -275 };
	pieceTransform.demension = vec2{ 18, 18 };
	pieceTransform.angle = 0;
	pieceBlock = sfw::loadTextureMap("res/blueBlock.png");

	forward = pieceTransform.position.Normal();
	up = vec2{ 0.f, 50.f * forward.y };
	speed = vec2{ 5.f * forward.x, 0.f };
	gravity = vec2{ 0.f ,-9.8f };
	isJumping = false;
	isMaxHeight = false;
	
	groundHeight = 18;
	jumpDelay = 10.f;
	
}

void Piece::Update()
{
	// Debug for player x position
	std::cout << "(" << pieceTransform.position.x << ", " << pieceTransform.position.y << ")" << std::endl;

	jumpHeight = groundHeight + 80;

	if (!isMaxHeight)
	{
		if (sfw::getKey('W') && !isMaxHeight)
		{
			if (pieceTransform.position.y <= jumpHeight)
			{				
				pieceTransform.position -= up;
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

	if (pieceTransform.position.y > groundHeight)
		pieceTransform.position += gravity;
	else
		pieceTransform.position.y = groundHeight;

}

void Piece::Draw()
{
	sfw::drawTexture(pieceBlock, pieceTransform.position.x, pieceTransform.position.y, 18, 18, pieceTransform.angle);
}


