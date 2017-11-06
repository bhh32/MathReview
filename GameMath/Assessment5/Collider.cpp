#include "Collider.h"

Collision Collides(const Transform &At, const Collider &Ac, const Transform &Bt, const Collider &Bc)
{
	return Intersect_AABB(Ac.GetGlobalBox(At), Bc.GetGlobalBox(Bt));
}