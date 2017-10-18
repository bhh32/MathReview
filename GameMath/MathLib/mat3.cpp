#include "mat3.h"
#include <cmath>

vec3 & mat3::operator[](unsigned idx)
{
	return c[idx];
}

const vec3 & mat3::operator[](unsigned idx) const
{
	return c[idx];
}

mat3 mat3::Identity()
{
	mat3 identity = { 1, 0, 0,
					  0, 1, 0,
					  0, 0, 1 };

	return identity;
}

mat3 operator+(const mat3 &A, const mat3 &B)
{
	return{ (A.m[0] + B.m[0]), (A.m[1] + B.m[1]), (A.m[2] + B.m[2]),
			(A.m[3] + B.m[3]), (A.m[4] + B.m[4]), (A.m[5] + B.m[5]) };
}

mat3 operator-(const mat3 &A, const mat3 &B)
{
	return{ (A.m[0] - B.m[0]), (A.m[1] - B.m[1]), (A.m[2] - B.m[2]),
		(A.m[3] - B.m[3]), (A.m[4] - B.m[4]), (A.m[5] - B.m[5]) };
}

// rows of the first by columns of the second
// 0 3 6
// 1 4 7 
// 2 5 8
mat3 operator*(const mat3 &A, const mat3 &B)
{
	mat3 temp = { (B.m[0] * A.m[0] + B.m[1] * A.m[3] + B.m[2] * A.m[6]), (B.m[0] * A.m[1] + B.m[1] * A.m[4] + B.m[2] * A.m[7]), (B.m[0] * A.m[2] + B.m[1] * B.m[5] + B.m[2] * A.m[8]), // x-axis
		          (B.m[3] * A.m[0] + B.m[4] * A.m[3] + B.m[5] * A.m[6]), (B.m[3] * A.m[1] + B.m[4] * A.m[4] + B.m[5] * A.m[7]), (B.m[3] * A.m[2] + B.m[4] * B.m[5] + B.m[5] * A.m[8]), // y-axis
		          (B.m[6] * A.m[0] + B.m[7] * A.m[3] + B.m[8] * A.m[6]), (B.m[6] * A.m[1] + B.m[7] * A.m[4] + B.m[8] * A.m[7]), (B.m[6] * A.m[2] + B.m[7] * B.m[5] + B.m[8] * A.m[8]) }; // position
	
	return temp;
}

vec3 operator*(const mat3 &A, const vec3 &V)
{
	mat3 At = Transpose(A);

	return vec3{ (DotProductVec3(At[0], V),
				DotProductVec3(At[2], V),
				DotProductVec3(At[3], V)) };
}

mat3 operator*(const float &x, const mat3 &A)
{
	mat3 temp = { x * A.m[0], x * A.m[1], x * A.m[2],
				  x * A.m[3], x * A.m[4], x * A.m[5],
				  x * A.m[6], x * A.m[7], x * A.m[7] };

	return temp;
}

bool operator==(const mat3 &A, const mat3 &B)
{
	int counter = 0;

	for (int i = 0; i < 9; ++i)
	{
		if (A.m[i] == B.m[i])
			counter++;
	}

	if (counter == 8)
		return true;

	return false;
}

mat3 Transpose(const mat3 &A)
{
	mat3 temp = {A.m[0], A.m[3], A.m[6],
	             A.m[1], A.m[4], A.m[7],
	             A.m[2], A.m[5], A.m[8]};
	
	return temp;
}

float Determinant(const mat3 &A)
{
	float temp = DotProductVec3(A[0], CrossProduct(A[1], A[2]));

	return temp;
}

mat3 Inverse(const mat3 &A)
{
	float di = 1 / Determinant(A);

	mat3 inverse = Transpose(mat3{
		CrossProduct(A[1], A[2]) * di,
		CrossProduct(A[2], A[0]) * di,
		CrossProduct(A[0], A[1]) * di });

	// Make any -0 an actual 0
	for (int i = 0; i < 9; ++i)
	{
		if (inverse.m[i] == -0)
			inverse.m[i] = 0;
	}

	return inverse;

}

mat3 Translate(const vec2 &t)
{
	mat3 retval = mat3::Identity();

	retval[2].xy = t;

	return retval;
}

mat3 Translate(float x, float y)
{
	return mat3{1, 0, 0,    // x-axis
	            0, 1, 0,    // y-axis
	            x, y, 1 };
}

mat3 Scale(const vec2 & s)
{
	return mat3{ s.x, 0, 0, // x-axis
				  0, s.y, 0, // y-axis
				  0,   0, 1 };
}

mat3 Scale(float x, float y)
{
	return mat3{ x, 0, 0, // x-axis
				 0, y, 0, // y-axis
				 0, 0, 1 };
}

mat3 Rotation(float deg)
{

	float rads = deg * (PI / 180);

	return mat3{  cosf(rads),  sinf(rads), 0, // X-axis
	             -sinf(rads),  cosf(rads), 0, // Y-axis
	                0,          0,      1 };
}
