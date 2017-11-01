#include "Player.h"

bool DoCollision(Player & player, const Wall & wall)
{
	auto hit = Collides(player.transform, player.collider, wall.transform, wall.collider);


	if (hit.penetrationDepth > 0)
	{
		Static_Resolution(player.transform.position, player.rigidbody.velocity, hit, .25f);
		return true;
	}
}
