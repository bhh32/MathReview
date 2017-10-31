#include "Collision.h"


Collision Intersect_1D(float Amin, float Amax, float Bmin, float Bmax)
{
	Collision ret;

	float lPenDepth = Bmax - Amin;
	float rPenDepth = Amax - Bmin;

	ret.penetrationDepth = Min(lPenDepth, rPenDepth);
	ret.handedness = copysign(1, rPenDepth - lPenDepth);
}
