#pragma once
#ifndef VEC3_H
#define VEC3_H

#include "vec2.h"

union vec3
{
	// Access by Array
	float v[3];

	struct
	{
		float x, y, z;
	};

	// Returns the element of the vector; can be used for assignment
	float &operator[](const int index);

	// Returns the element of the vector
	const float operator[](const int index) const;

	vec2 xy;

	// Returns the magnitude of a vector
	float Magnitude();

	// Returns the normalized vector w/o modifying original vector
	vec3 Normal();

	// Returns the normalized vector (changes the vector to normalized vector)
	vec3 &Normalize();



};

// Adds two vectors to make a new vector
vec3 operator+(const vec3 &lhs, const vec3 &rhs);

// Adds the second vector to the first vector
vec3 &operator+=(vec3 &lhs, const vec3 &rhs);

// Subtracts two vectors to make a new vector
vec3 operator-(const vec3 &lhs, const vec3 &rhs);

// Subtracts second vector from first vector
vec3 operator-=(vec3 &lhs, const vec3 &rhs);

// Compare two vectors to determine if they are the same
bool operator==(const vec3 &lhs, const vec3 &rhs);

// multiplies x and y by scalar to make a new vector
vec3 operator*(vec3 &lhs, const float &rhs);

// multiplies scalar by x and y in vector to make a new vector
vec3 operator*(const float &lhs, vec3 &rhs);

// multiplies vector x and y by scalar
vec3 operator*=(vec3 &lhs, const float &rhs);

// divides the vector x and y by the scalar
vec3 operator/(const vec3 &lhs, const float &rhs);

// Divides the vector by the scalar
vec3 operator/=(vec3 &lhs, const float &rhs);

// Return the inverse x and y values
vec3 operator-(vec3 &rhs);

// Compares two vectors to determine if they aren't the same
bool operator!=(const vec3 &lhs, const vec3 &rhs);

bool operator<(const vec3 &lhs, const vec3 &rhs);

bool operator>(const vec3 &lhs, const vec3 &rhs);

bool operator<=(const vec3 &lhs, const vec3 &rhs);

bool operator>=(const vec3 &lhs, const vec3 &rhs);

float DistanceVec3(const vec3 &lhs, const vec3 &rhs);

float DotProductVec3(const vec3 &lhs, const vec3 &rhs);

vec3 CrossProduct(const vec3 &a, const vec3 &b);

vec3 LerpVec3(const vec3 &start, const vec3 &end, float time);

vec3 MinVec3(const vec3 &x, const vec3 &y);

vec3 MaxVec3(const vec3 &x, const vec3 &y);

vec3 Clamp(vec3 &vector, const vec3 min, const vec3 max);

#endif VEC3_H