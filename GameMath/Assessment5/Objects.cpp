#include "Objects.h"

void Platform::InitStaticPlatforms(Platform &platform)
{
	platform.sprite = sfw::loadTextureMap("../resources/paddle.png");
	platform.isMovingRight = false;
	platform.isMovingUp = false;
	platform.isSoftPlatform = false;
	platform.rigidbody = Rigidbody();
}

bool DoCollision(Player & player, const Wall & wall, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, wall.transform, wall.collider);


	if (hit.penetrationDepth > 0)
	{
		Static_Resolution(player.transform.position, player.rigidbody.velocity, hit, elasticity);
		return true;
	}
}

bool DoCollision(Player &player, const Platform &platform, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, platform.transform, platform.collider);

	if (!platform.isSoftPlatform)
	{
		if(hit.penetrationDepth > 0)
		{
			Static_Resolution(player.transform.position, player.rigidbody.velocity, hit, elasticity);
			return true;
		}
	}

	return false;
}