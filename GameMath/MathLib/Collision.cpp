#include "Collision.h"


Collision Intersect_1D(float Amin, float Amax, float Bmin, float Bmax)
{
	Collision ret;

	float lPenDepth = Bmax - Amin;
	float rPenDepth = Amax - Bmin;

	ret.penetrationDepth = Min(lPenDepth, rPenDepth);
	ret.handedness = copysign(1, rPenDepth - lPenDepth);

	return ret;
}

Collision Intersect_AABB(const AABB &A, const AABB &B)
{
	Collision xRes = Intersect_1D(A.Min().x, A.Max().x, B.Min().x, B.Max().x);
	Collision yRes = Intersect_1D(A.Min().y, A.Max().y, B.Min().y, B.Max().y);

	xRes.axis = vec2{ 1, 0 };
	yRes.axis = vec2{ 0, 1 };

	return xRes.penetrationDepth < yRes.penetrationDepth ? xRes : yRes;
}

Collision Intersect_Circle(const Circle & A, const Circle & B)
{
	Collision ret;

	ret.axis = Normal(B.position - A.position);
	ret.handedness = -1;

	float Ap = DotProduct(ret.axis, A.position);
	float Bp = DotProduct(ret.axis, B.position);

	float Amin = Ap - A.radius;
	float Amax = Ap + A.radius;

	float Bmin = Bp - B.radius;
	float Bmax = Bp + B.radius;

	// How we calculate the pen depth
	ret.penetrationDepth = Intersect_1D(Amin, Amax, Bmin, Bmax).penetrationDepth;

	return ret;
}

Collision Intersect_AABB_Circle(const AABB &A, const Circle &B)
{
	// Hint:
	         /* First find the axis (closest point on AABB to circle)
			    then project the points of each onto the axis.
				Find min and max of those points for each.
				Perform 1D Intersection.
			*/

	return Collision();
}

void Static_Resolution(vec2 &pos, vec2 &velocity, const Collision &hit, float elasticity)
{
	// Correct the position
	pos += hit.axis * hit.handedness * hit.penetrationDepth;

	// Reflect the velocity
	velocity = -Reflect(velocity, hit.axis * hit.handedness) * elasticity;
}

void Dynamic_Resolution(vec2 &Apos, vec2 &Avelocity, float Amass, vec2 &Bpos, vec2 &Bvelocity, float Bmass, const Collision &hit, float elasticity)
{
	// Law of Conservation
	/*
	mass * velocity = momentum (P)

	AP + BP = `AP + `BP *Conservation of Momentum (Energy)
	: Avel * Amass + Bvel * Bmass = `Avel * Amass + `Bvel * Bmass

	Avel - Bvel = -(`Avel - `Bvel) *Relative Velocity*
	: `Avel - `Bvel = -(`Bvel - `Avel)

	*/
	vec2 normal = hit.axis * hit.handedness;
	vec2 Rvel = Avelocity - Bvelocity;

	// impulse magnitude : balanced change in magnitude
	float j = -(1 + elasticity) * DotProduct(Rvel, normal) / DotProduct(normal, normal*(1 / Amass + 1 / Bmass));
	
	Avelocity += (j / Amass) * normal;
	Bvelocity -= (j / Bmass) * normal;

	Apos += normal * hit.penetrationDepth * Amass / (Amass + Bmass);
	Bpos -= normal * hit.penetrationDepth * Bmass / (Bmass + Amass);
}


