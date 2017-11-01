#include "Player.h"

bool DoCollision(Player & player, const Wall & wall, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, wall.transform, wall.collider);


	if (hit.penetrationDepth > 0)
	{
		Static_Resolution(player.transform.position, player.rigidbody.velocity, hit, elasticity);
		return true;
	}
}

bool DoCollision(Ball & ball, const Wall & wall, float elasticity)
{
	auto hit = Collides(ball.transform, ball.collider, wall.transform, wall.collider);


	if (hit.penetrationDepth > 0)
	{
		Static_Resolution(ball.transform.position, ball.rigidbody.velocity, hit, elasticity);
		return true;
	}
}

bool DoCollision(Player & player, const Ball & ball, float elasticity)
{
	auto hit = Collides(player.transform, player.collider, ball.transform, ball.collider);


	if (hit.penetrationDepth > 0)
	{
		Static_Resolution(player.transform.position, player.rigidbody.velocity, hit, elasticity);
		return true;
	}
}
