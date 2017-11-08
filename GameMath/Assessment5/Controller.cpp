#include "Controller.h"
#include "Objects.h"

// Poll for input and apply changes to the rigidbody

void PlayerController::Poll(Player &player)
	{
		float gravity = 120.f;

		if (sfw::getKey('D'))
		{
				player.rigidbody.velocity.x = player.transform.GetGlobalTransform()[0].x * 5.f;
		}
		if (sfw::getKey('A'))
		{
				player.rigidbody.velocity.x = -player.transform.GetGlobalTransform()[0].x * 5.f;
		}

		if (sfw::getKey(' ') && player.isGrounded)
			player.rigidbody.impulse.y += (gravity * -1) * 25.f;

		if (player.isGrounded)
		{
			player.rigidbody.velocity.y = gravity +  12;
		}
		else
			player.rigidbody.force.y += -gravity;
	}

void PlatformController::PollHorizontalPlatform(Platform *platform, float minPosX, float maxPosX, float speed, int idx)
	{
		Platform *p = &platform[idx];
		if (p->isMovingRight)
		{
			p->rigidbody.velocity.x = p->transform.GetGlobalTransform()[0].x * speed;

			if (p->transform.position.x > maxPosX)
			{
				p->isMovingRight = false;
			}
		}
		else if (!p->isMovingRight)
		{
			p->rigidbody.velocity.x = -p->transform.GetGlobalTransform()[0].x * speed;

			if (p->transform.position.x < minPosX)
				p->isMovingRight = true;
		}
	}

void PlatformController::PollVerticalPlatform(Platform *platform, float minPosY, float maxPosY, float speed, int idx)
	{
		Platform *p = &platform[idx];

		if (p->isMovingUp)
		{
			p->rigidbody.velocity.y = platform->transform.GetGlobalTransform()[1].y * speed;

			if (p->transform.position.y > maxPosY)
			{
				p->isMovingUp = false;
			}
		}

		else if (!p->isMovingUp)
		{
			p->rigidbody.velocity.y = -p->transform.GetGlobalTransform()[1].y * speed;

			if (p->transform.position.y <= minPosY)
				p->isMovingUp = true;
		}
	}

void PlatformController::PollDiagonalUpRightPlatform(Platform *platform, float minPosX, float maxPosX, float speed, int idx)
	{
		Platform *p = &platform[idx];
		if (p->isMovingRight)
		{
			p->rigidbody.velocity.x = p->transform.GetGlobalTransform()[0].x * speed;

			if (p->transform.position.x > maxPosX)
			{
				p->isMovingRight = false;
				p->isMovingUp = false;
			}
		}

		if (p->isMovingUp)
			p->rigidbody.velocity.y = platform->transform.GetGlobalTransform()[1].y * speed;
		else
			p->rigidbody.velocity.y = -platform->transform.GetGlobalTransform()[1].y * speed;


		if (!p->isMovingRight)
		{
			p->rigidbody.velocity.x = -platform->transform.GetGlobalTransform()[0].x * speed;

			if (p->transform.position.x < minPosX)
			{
				p->isMovingRight = true;
				p->isMovingUp = true;
			}
		}
	}

void PlatformController::PollDiagonalUpLeftPlatform(Platform *platform, float minPosX, float maxPosX, float speed, int idx)
	{
		Platform *p = &platform[idx];
		if (p->isMovingRight)
		{
			p->rigidbody.velocity.x = platform->transform.GetGlobalTransform()[0].x * speed;

			if (p->transform.position.x > maxPosX)
			{
				p->isMovingRight = false;
				p->isMovingUp = true;
			}
		}

		if (p->isMovingUp)
			p->rigidbody.velocity.y = platform->transform.GetGlobalTransform()[1].y * speed;
		else
			p->rigidbody.velocity.y = platform->transform.GetGlobalTransform()[1].y * speed;


		if (!p->isMovingRight)
		{
			p->rigidbody.velocity.x = -p->transform.GetGlobalTransform()[0].x * speed;

			if (p->transform.position.x < minPosX)
			{
				p->isMovingRight = true;
				p->isMovingUp = false;
			}
		}
	}