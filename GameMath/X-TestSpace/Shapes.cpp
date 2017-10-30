#include "Shapes.h"
#include <cmath>

Circle operator*(const mat3 & M, const Circle & C)
{
	Circle ret = C;

	ret.position = (M * vec3{ C.position.x, C.position.y, 1.f }).xy;
	
	vec2 scale;
	scale.x = Magnitude(M[0].xy);
	scale.y = Magnitude(M[1].xy);

	ret.radius *= fmaxf(scale.x, scale.y);

	return ret;
}

AABB operator*(const mat3 &M, const AABB &B)
{
	// Try to independantly research a solution to this
	return AABB();
}
