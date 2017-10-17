#include "mat3.h"

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
	//m = identity;

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

mat3 operator*(const mat3 &A, const mat3 &B)
{
	mat3 temp = { (A.m[0] * B.m[0] + A.m[1] * B.m[3] + A.m[2] * B.m[6]), (A.m[0] * B.m[1] + A.m[1] * B.m[4] + A.m[2] * B.m[7]), (A.m[0] * B.m[2] + A.m[1] * B.m[5] + A.m[2] * B.m[8]),
		          (A.m[3] * B.m[0] + A.m[4] * B.m[3] + A.m[5] * B.m[6]), (A.m[3] * B.m[1] + A.m[4] * B.m[4] + A.m[5] * B.m[7]), (A.m[3] * B.m[2] + A.m[4] * B.m[5] + A.m[5] * B.m[8]),
		          (A.m[6] * B.m[0] + A.m[7] * B.m[3] + A.m[8] * B.m[6]), (A.m[6] * B.m[1] + A.m[7] * B.m[4] + A.m[8] * B.m[7]), (A.m[6] * B.m[2] + A.m[7] * B.m[5] + A.m[8] * B.m[8]) };
	
	return temp;
}

mat3 operator*(const mat3 &A, const vec3 &V)
{
	mat3 temp = { (A.m[0] * V.x + A.m[1] * V.y + A.m[2] * V.z), (A.m[0] * V.x + A.m[1] * V.y + A.m[2] * V.z), (A.m[0] * V.x + A.m[1] * V.y + A.m[2] * V.z),
		(A.m[3] * V.x + A.m[4] * V.y + A.m[5] * V.z), (A.m[3] * V.x + A.m[4] * V.y + A.m[5] * V.z), (A.m[3] * V.x + A.m[4] * V.y + A.m[5] * V.z),
		(A.m[6] * V.x + A.m[7] * V.y + A.m[8] * V.z), (A.m[6] * V.x + A.m[7] * V.y + A.m[8] * V.z), (A.m[6] * V.x + A.m[7] * V.y + A.m[8] * V.z) };
	
	return temp;
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
	return 0.0f;
}

mat3 Inverse(const mat3 &A)
{
	return mat3();
}
