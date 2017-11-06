#include "Controller.h"
#include "Objects.h"

//#include "Transform.h"


// Poll for input and apply changes to the rigidbody

void PlayerController::Poll(Rigidbody *rb, const Transform *t)
	{
		//if (sfw::getKey('W')) rb.force += t.GetGlobalTransform()[1].xy * 10;
		//if (sfw::getKey('A')) rb.torque += 360;
		//if (sfw::getKey('D')) rb.torque += -360;
		//if (sfw::getKey('Q')) rb.impulse += -t.GetGlobalTransform()[1].xy * 10;
		//if (sfw::getKey(' ')) // breaking force
		//{
		//	rb.force += -rb.velocity * 20;
		//	rb.torque += -rb.angularVelocity * 20;
		//}

		if (sfw::getKey('D'))
		{
			rb->velocity.x = t->GetGlobalTransform()[0].x * 500.f * sfw::getDeltaTime();

		}
		else
		{
			rb->velocity.x = 0;
		}
		if (sfw::getKey('A'))
		{
			rb->velocity.x = -t->GetGlobalTransform()[0].x * 500.f * sfw::getDeltaTime();
		}

		if (!sfw::getKey('D') && !sfw::getKey('A'))
			rb->velocity.x = 0;
	}

void PlatformController::PollHorizontalPlatform(Platform *platform, float minPosX, float maxPosX, float speed)
	{
		if (platform->isMovingRight)
		{
			platform->rigidbody.velocity.x = platform->transform.GetGlobalTransform()[0].x * speed * sfw::getDeltaTime();

			if (platform->transform.position.x > maxPosX)
			{
				platform->isMovingRight = false;
			}
		}

		else if (!platform->isMovingRight)
		{
			platform->rigidbody.velocity.x = -platform->transform.GetGlobalTransform()[0].x * speed * sfw::getDeltaTime();

			if (platform->transform.position.x < minPosX)
				platform->isMovingRight = true;
		}
	}

void PlatformController::PollVerticalPlatform(Platform *platform, float minPosY, float maxPosY, float speed)
	{
		if (platform->isMovingUp)
		{
			platform->rigidbody.velocity.y = platform->transform.GetGlobalTransform()[1].y * speed * sfw::getDeltaTime();

			if (platform->transform.position.y > maxPosY)
			{
				platform->isMovingUp = false;
			}
		}

		else if (!platform->isMovingUp)
		{
			platform->rigidbody.velocity.y = -platform->transform.GetGlobalTransform()[1].y * speed * sfw::getDeltaTime();

			if (platform->transform.position.x < minPosY)
				platform->isMovingUp = true;
		}
	}

void PlatformController::PollDiagonalUpRightPlatform(Platform *platform, float minPosX, float maxPosX, float speed)
	{
		if (platform->isMovingRight)
		{
			platform->rigidbody.velocity.x = platform->transform.GetGlobalTransform()[0].x * speed * sfw::getDeltaTime();

			if (platform->transform.position.x > maxPosX)
			{
				platform->isMovingRight = false;
				platform->isMovingUp = false;
			}
		}

		if (platform->isMovingUp)
			platform->rigidbody.velocity.y = platform->transform.GetGlobalTransform()[1].y * speed * sfw::getDeltaTime();
		else
			platform->rigidbody.velocity.y = -platform->transform.GetGlobalTransform()[1].y * speed * sfw::getDeltaTime();


		if (!platform->isMovingRight)
		{
			platform->rigidbody.velocity.x = -platform->transform.GetGlobalTransform()[0].x * speed * sfw::getDeltaTime();

			if (platform->transform.position.x < minPosX)
			{
				platform->isMovingRight = true;
				platform->isMovingUp = true;
			}
		}
	}

void PlatformController::PollDiagonalUpLeftPlatform(Platform *platform, float minPosX, float maxPosX, float speed)
	{
		if (platform->isMovingRight)
		{
			platform->rigidbody.velocity.x = platform->transform.GetGlobalTransform()[0].x * speed * sfw::getDeltaTime();

			if (platform->transform.position.x > maxPosX)
			{
				platform->isMovingRight = false;
				platform->isMovingUp = true;
			}
		}

		if (platform->isMovingUp)
			platform->rigidbody.velocity.y = platform->transform.GetGlobalTransform()[1].y * speed * sfw::getDeltaTime();
		else
			platform->rigidbody.velocity.y = platform->transform.GetGlobalTransform()[1].y * speed * sfw::getDeltaTime();


		if (!platform->isMovingRight)
		{
			platform->rigidbody.velocity.x = -platform->transform.GetGlobalTransform()[0].x * speed * sfw::getDeltaTime();

			if (platform->transform.position.x < minPosX)
			{
				platform->isMovingRight = true;
				platform->isMovingUp = false;
			}
		}
	}