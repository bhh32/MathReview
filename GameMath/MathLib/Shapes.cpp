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

AABB operator*(const mat3 &M,  const AABB &B)
{
	// Try to independantly research a solution to this
	AABB returnVal = B;
	
	vec2 topLeft = { B.position.x - B.extents.x, B.position.y + B.extents.y };
	vec2 topRight = B.position + B.extents;
	vec2 bottomLeft = B.position - B.extents;
	vec2 bottomRight = { topRight.x, bottomLeft.y };


	topRight = (M * vec3{ topRight.x, topRight.y, 1 }).xy;
	bottomLeft = (M * vec3{ bottomLeft.x, bottomLeft.y, 1 }).xy;
	topLeft = (M * vec3{ topLeft.x, topLeft.y, 1 }).xy;
	bottomRight = (M * vec3{ bottomRight.x, bottomRight.y, 1 }).xy;

	returnVal.minCorner = Min(topRight, Min(bottomLeft, Min(topLeft, bottomRight)));
	returnVal.maxCorner = Max(topRight, Max(bottomLeft, Max(topLeft, bottomRight)));

	returnVal.position = (returnVal.maxCorner + returnVal.minCorner) / 2;
	returnVal.extents = (returnVal.maxCorner - returnVal.minCorner) / 2;

	return returnVal;
}
