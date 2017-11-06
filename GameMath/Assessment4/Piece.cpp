#include <iostream>
#include "Piece.h"
#include <sstream>
#include "sfwdraw.h"

void Piece::InitPiece()
{	
	// Load the player texture and set the intial groundHeight value
	pieceBlock = sfw::loadTextureMap("res/blueBlock.png");
	groundHeight = 18.f;
	
	// Setup gravity anf flags for jumping
	gravity = vec2{ 0.f ,-9.8f };
	isJumping = false;
	isMaxHeight = false;
	jumpDelay = 10.f;

	// Setup player transform
	pieceTransform.position = vec2{ 400, 100 };
	pieceTransform.demension = vec2{ 18, 18 };
	pieceTransform.angle = 0;

	// Setup Forward, Up, and Speed vectors
	//forward = vec2.Normal();
	up = vec2{ 0.f, 75.f * forward.y };
	speed = vec2{ 5.f * forward.x, 0.f };
}

void Piece::Update()
{
	// Get the bottom of the player's cube
	pieceBottom = pieceTransform.position.y - (pieceTransform.demension.y / 2);

	// Set the jumpHeight value
	jumpHeight = groundHeight + 70;

	// Checks to ensursure the player hasn't "recently" reached the max jump height
	if (!isMaxHeight)
	{
		// If they haven't they can jump again
		if (sfw::getKey('W') && !isMaxHeight)
		{
			// Makes sure the player isn't currently jumping
			if (pieceTransform.position.y <= jumpHeight)
			{	
				// Player jumps and sets the flag that they are jumping
				pieceTransform.position += up;
				isJumping = true;
			}

			// Sets the flag that the player recently jumped and resets the jumpDelay
			if (pieceTransform.position.y >= jumpHeight)
			{
				isMaxHeight = true;
				jumpDelay = 10.f;
			}
		}
	}
	// If the player recently jumped
	else if(isMaxHeight)
	{
		// Check the jumpDelay and flag and set both flags to false
		if (jumpDelay <= 0 && isMaxHeight)
		{
			isMaxHeight = false;
			isJumping = false;
		}
	}

	// Countdown the jump delay
	if (isMaxHeight)
		jumpDelay -= 1.f;

	// Player move to the right
	if (sfw::getKey('D'))
		pieceTransform.position += speed;

	// Player move to the left
	if (sfw::getKey('A'))
		pieceTransform.position -= speed;

	// Checks to see if the player is in the air so gravity takes effect
	if (pieceTransform.position.y - 9 > groundHeight)
		pieceTransform.position += gravity;
	// Otherwise the player is on the ground
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


