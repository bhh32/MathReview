#pragma once
#ifndef VEC2_H
#define VEC2_H

union vec2
{
	// Access by Array
	float v[2];

	struct
	{
		float x, y;
	};

	// Returns the element of the vector; can be used for assignment
	float &operator[](const int index);

	// Returns the element of the vector
	const float operator[](const int index) const;

	// Returns the magnitude of a vector
	float Magnitude();

	// Returns the normalized vector w/o modifying original vector
	vec2 Normal();

	// Returns the normalized vector (changes the vector to normalized vector)
	vec2 &Normalize();

	
	
};

// Adds two vectors to make a new vector
vec2 operator+(const vec2 &lhs, const vec2 &rhs);

// Adds the second vector to the first vector
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);

// Subtracts two vectors to make a new vector
vec2 operator-(const vec2 &lhs, const vec2 &rhs);

// Subtracts second vector from first vector
vec2 operator-=(vec2 &lhs, const vec2 &rhs);

// Compare two vectors to determine if they are the same
bool operator==(const vec2 &lhs, const vec2 &rhs);

// multiplies x and y by scalar to make a new vector
vec2 operator*(const vec2 &lhs, float &rhs);

// multiplies scalar by x and y in vector to make a new vector
vec2 operator*(float &lhs, const vec2 &rhs);

// multiplies vector x and y by scalar
vec2 operator*=(vec2 &lhs, const float &rhs);

// divides the vector x and y by the scalar
vec2 operator/(const vec2 &lhs, const float &rhs);

// Divides the vector by the scalar
vec2 operator/=(vec2 &lhs, const float &rhs);

// Return the inverse x and y values
vec2 operator-(vec2 &rhs);

// Compares two vectors to determine if they aren't the same
bool operator!=(const vec2 &lhs, const vec2 &rhs);

bool operator<(const vec2 &lhs, const vec2 &rhs);

bool operator>(const vec2 &lhs, const vec2 &rhs);

bool operator<=(const vec2 &lhs, const vec2 &rhs);

bool operator>=(const vec2 &lhs, const vec2 &rhs);

float DotProduct(const vec2 &lhs, const vec2 &rhs);

float Distance(const vec2 &lhs, const vec2 &rhs);

vec2 Perpendicular(const vec2 &vec);

vec2 Lerp(const vec2 &start, const vec2 &end, float time);

vec2 Min(const vec2 &x, const vec2 &y);

vec2 Max(const vec2 &x, const vec2 &y);

#endif VEC2_H