#include "Player.h"

bool DoCollision(Player & player, const Wall & wall, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, wall.transform, wall.collider);


	if (hit.penetrationDepth > 0)
	{
		Static_Resolution(player.transform.position, player.rigidbody.velocity, hit, elasticity);
		return true;
	}

	return false;
}

bool DoCollision(Ball & ball, const Wall & wall, float elasticity)
{
	auto hit = Collides(ball.transform, ball.collider, wall.transform, wall.collider);


	if (hit.penetrationDepth > 0)
	{
		Static_Resolution(ball.transform.position, ball.rigidbody.velocity, hit, elasticity);
		return true;
	}

	return false;
}

bool DoCollision(Player & player, Ball & ball, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, ball.transform, ball.collider);


	if (hit.penetrationDepth > 0)
	{
		Dynamic_Resolution(player.transform.position, player.rigidbody.velocity, player.rigidbody.mass, 
			               ball.transform.position, ball.rigidbody.velocity, ball.rigidbody.mass,
			               hit, elasticity);
		return true;
	}

	return false;
}
