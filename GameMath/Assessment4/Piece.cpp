#include <iostream>
#include "Piece.h"
#include <sstream>
#include "sfwdraw.h"

void Piece::InitPiece()
{
	pieceTransform.position = vec2{ 400, 300 };
	pieceTransform.demension = vec2{ 18, 18 };
	pieceTransform.angle = 0;
	pieceBlock = sfw::loadTextureMap("res/blueBlock.png");

	isJumping = false;
	isMaxHeight = false;
	gravity = -9.8f;
	groundHeight = 18;
	jumpDelay = 10.f;
	jumpHeight = groundHeight + 72;
}

void Piece::Update()
{

	std::cout << pieceTransform.position.x << std::endl;
	if (!isMaxHeight)
	{
		if (sfw::getKey('W') && !isMaxHeight)
		{
			if (pieceTransform.position.y <= jumpHeight)
			{				
				pieceTransform.position.y += 20.f;
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
	{
		pieceTransform.position.x += 225.f * sfw::getDeltaTime();
	}

	if (sfw::getKey('A'))
		pieceTransform.position.x -= 225.f * sfw::getDeltaTime();

	if (pieceTransform.position.y > groundHeight)
	{
		pieceTransform.position.y += gravity;
	}
	else
		pieceTransform.position.y = groundHeight;


	if (pieceTransform.position.x < 246.f)
		groundHeight = 35.f;
	else if (pieceTransform.position.x >= 523.f && pieceTransform.position.x <= 536.f)
		groundHeight = 18.f;
	else if (pieceTransform.position.x > 536.f && pieceTransform.position.x < 563.f)
		groundHeight = -200.f;
	else if (pieceTransform.position.x >= 543.f)
		groundHeight = 25.f;

	
}

void Piece::Draw()
{
	sfw::drawTexture(pieceBlock, pieceTransform.position.x, pieceTransform.position.y, 18, 18, pieceTransform.angle);
}


