#pragma once

#include "vec3.h"

#define PI 3.14159265359

union mat3
{
	// 3 ways of representing the same thing
	vec3 c[3];
	float m[9];
	float mm[3][3];
	

	vec3 &operator[](unsigned idx); // Column accessor
	const vec3 &operator[](unsigned idx) const;

	static mat3 Identity(); // Creates and returns the identiy matrix
};

mat3 operator+(const mat3 &A, const mat3 &B); // Not really used
mat3 operator-(const mat3 &A, const mat3 &B); // Not really used

mat3 operator*(const mat3 &A, const mat3 &B); // Combine Transformations
vec3 operator*(const mat3 &A, const vec3 &V); // Apply a Transformation
mat3 operator*(const float &x, const mat3 &A); // Multiply a scalar by the matrix

bool operator==(const mat3 &A, const mat3 &B);

mat3 Transpose(const mat3 &A); // Flip the rows and columns

float Determinant(const mat3 &A);
mat3 Inverse(const mat3 &A);

/*
// Translation Matrix
[1 0 0]
[0 1 0]
[x y 1]
*/
mat3 Translate(const vec2 &t);
mat3 Translate(float x, float y);
/*
// Scale Matrix
[x 0 0]
[0 y 0]
[0 0 1]
*/
mat3 Scale(const vec2 &s);
mat3 Scale(float x, float y);

/*

A[0].xy is the x-axis
A[1].xy is the y-axis

 Rotation Matrix
 [ cos(a)   sin(a)   0] x-axis
 [-sin(a)   cos(a)   0] y-axis
 [  0        0       1]
*/
mat3 Rotation(float deg);


/*
// The visual of the 3 representations
[0 3 6]
[1 4 7]
[2 5 8]

[(0, 0) (0, 1) (0, 2)]
[(1, 0) (1, 1) (1, 2)]
[(2, 0) (2, 1) (2, 2)]

[c1 c2 c3]

*/