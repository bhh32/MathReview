#pragma once

#include "vec3.h"

union mat3
{
	// 3 ways of representing the same thing
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 &operator[](unsigned idx); // Column accessor
	const vec3 &operator[](unsigned idx) const;

	static mat3 Identity(); // Creates and returns the identiy matrix
};

mat3 operator+(const mat3 &A, const mat3 &B); // Not really used
mat3 operator-(const mat3 &A, const mat3 &B); // Not really used

mat3 operator*(const mat3 &A, const mat3 &B); // Combine Transformations
mat3 operator*(const mat3 &A, const vec3 &V); // Apply a Transformation

mat3 Transpose(const mat3 &A); // Flip the rows and columns

// Challenge Functions
float Determinant(const mat3 &A);
mat3 Inverse(const mat3 &A);

/*

// Translation Matrix
[1 0 x]
[0 1 y]
[0 0 1]


// The visual of the 3 representations
[0 3 6]
[1 4 7]
[2 5 8]

[(0, 0) (0, 1) (0, 2)]
[(1, 0) (1, 1) (1, 2)]
[(2, 0) (2, 1) (2, 2)]

[c1 c2 c3]

*/