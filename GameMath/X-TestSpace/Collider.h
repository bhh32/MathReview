#pragma once

#include "Shapes.h"
#include "Transform.h"
#include "Collision.h"

class Collider
{
public:
	AABB box;

	AABB GetGlobalBox(const Transform &t) const
	{
		return t.GetGlobalTransform() * box;
	}

	Collider(const AABB &a_box = { {0, 0}, {1, 1} }) : box(a_box)
	{

	}
};

Collision Collides(const Transform &At, const Collider &Ac, const Transform &Bt, const Collider &Bc);