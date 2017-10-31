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

AABB operator*(const mat3 &M,  AABB &B)
{
	// Try to independantly research a solution to this
	AABB retval = B;
	vec2 matrixMax = (vec2{ M[0].x, M[1].y});
	vec2 matrixMin = (vec2{ M[1].x, M[0].y});

	if (matrixMax.x > M[1].x)
		retval.max.x = matrixMax.x;
	if (matrixMax.y > M[0].y)
		retval.max.y = matrixMax.y;

	if (matrixMin.x < M[0].x)
		retval.min.x = matrixMin.x;
	if (matrixMin.y < M[1].y)
		retval.min.y = matrixMin.y;

	//retval.position = (retval.max + retval.min) / 2;
	//retval.extents = (retval.max - retval.min);
	
	return retval;
}
