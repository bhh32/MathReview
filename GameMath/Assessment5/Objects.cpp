#include "Objects.h"

void Platform::InitStaticPlatforms(Platform &platform)
{
	platform.sprite = sfw::loadTextureMap("../resources/paddle.png");
	platform.collider.box.extents = { .5, .5 };
	platform.isMovingRight = false;
	platform.isMovingUp = false;
	platform.isSoftPlatform = false;
}

void Platform::InitHorizontalPlatforms(Platform &platform)
{
	platform.sprite = sfw::loadTextureMap("../resources/paddle.png");
	platform.collider.box.extents = { .5, .5 };
	platform.rigidbody.mass = 100.f;
	platform.speed = 1.5f;
	platform.isMovingRight = true;
	platform.isMovingUp = false;
	platform.isSoftPlatform = false;
}

void Platform::InitVerticalPlatforms(Platform &platform)
{
	platform.sprite = sfw::loadTextureMap("../resources/paddle.png");
	platform.collider.box.extents = { .5, .5 };
	platform.rigidbody.mass = 100.f;
	platform.speed = 1.5f;
	platform.isMovingRight = false;
	platform.isMovingUp = true;
	platform.isSoftPlatform = false;
}

void Platform::InitUpRightPlatforms(Platform &platform)
{
	platform.sprite = sfw::loadTextureMap("../resources/paddle.png");
	platform.collider.box.extents = { .5, .5 };
	platform.rigidbody.mass = 100.f;
	platform.speed = 1.5f;
	platform.isMovingRight = true;
	platform.isMovingUp = true;
	platform.isSoftPlatform = false;
}

void Platform::InitUpLeftPlatforms(Platform &platform)
{
	platform.sprite = sfw::loadTextureMap("../resources/paddle.png");
	platform.collider.box.extents = { .5, .5 };
	platform.rigidbody.mass = 100.f;
	platform.speed = 1.5f;
	platform.isMovingRight = false;
	platform.isMovingUp = true;
	platform.isSoftPlatform = false;
}


bool DoCollision(Player &player, const Wall &wall, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, wall.transform, wall.collider);


	if (hit.penetrationDepth > 0)
	{
		Static_Resolution(player.transform.position, player.rigidbody.velocity, hit, elasticity);
		player.gravity = 0.f;
		return true;
	}
	else 
		return false;
}

bool GravityTestCollision(Player &player, const Wall &wall, const Platform &platform)
{
	auto hit = Collides(player.transform, player.collider, platform.transform, platform.collider);
	auto hitWall = Collides(player.transform, player.collider, platform.transform, platform.collider);

	if (hit.penetrationDepth > 0 || hitWall.penetrationDepth > 0)
	{
		if (hit.axis.y == -1)
		{
			player.isGrounded = true;
			player.gravity = 0.f;
			return true;
		}
	}
	player.gravity = -9.8f;
	return false;
}

//pos += hit.axis * hit.handedness * hit.penetrationDepth;
bool DoCollision(Player &player, const Platform &platform, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, platform.transform, platform.collider);

	if (!platform.isSoftPlatform)
	{
		if(hit.penetrationDepth >= 0)
		{			
			//Correct and parent if applicable (parent if above the platform)
			player.transform.position += hit.axis * hit.handedness * hit.penetrationDepth;

			if (hit.axis.x <= -1)
				player.transform.e_parent = nullptr;

			
			//Static_Resolution(player.transform.position, player.rigidbody.velocity, hit, elasticity);
			return true;
		}
	}

	return false;
}

bool DoCollisionMoving(Player &player, Platform &platform, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, platform.transform, platform.collider);

	if (!platform.isSoftPlatform)
	{
		if (hit.penetrationDepth > 0)
		{
			Dynamic_Resolution(player.transform.position, player.rigidbody.velocity, player.rigidbody.mass, platform.transform.position, platform.rigidbody.velocity, platform.rigidbody.mass, hit, elasticity);
			return true;
		}
	}

	return false;
}