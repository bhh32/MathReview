#pragma once

#include "vec2.h"
#include "Transform.h"

class Rigidbody
{
public:
	float mass;

	// Linear Motion
	vec2 velocity,      // speed * direction
		acceleration,
		force,
		impulse; 

	float drag;
	// Acceleration is the sum of all forces applied to an object

	// F = MA
	// A = Force/Mass 

	// Angular Motion
	float angularVelocity,
		angularAcceleration,
		torque;

	float angularDrag;


	Rigidbody() : velocity{ 0, 0 },
		acceleration{ 0, 0 },
		force{ 0, 0 },
		impulse{ 0, 0 },
		mass(1),
		drag(.25f),
		angularVelocity(0),
		angularAcceleration(0),
		torque(0),
		angularDrag(.25f)
	{

	}

	
	void Integrate(Transform &T, float deltaTime)
	{
		// Linear Motion
		acceleration = force / mass;
		velocity += acceleration * deltaTime + impulse / mass;
		T.position += velocity * deltaTime;

		impulse = { 0, 0 };

		force = -velocity * drag;

		// Angular Motion
		angularAcceleration = torque / mass;
		angularVelocity += angularAcceleration * deltaTime;
		T.angle += angularVelocity * deltaTime;


		torque = -angularVelocity * angularDrag;
	}



};