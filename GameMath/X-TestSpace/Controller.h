#pragma once

#include "Transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"

// Poll for input and apply changes to the rigidbody
class Controller
{
public:
	void Poll(Rigidbody &rb, const Transform &t)
	{
		//if (sfw::getKey('W')) rb.force += t.GetGlobalTransform()[1].xy * 10;
		//if (sfw::getKey('A')) rb.torque += 360;
		//if (sfw::getKey('D')) rb.torque += -360;
		//if (sfw::getKey('Q')) rb.impulse += -t.GetGlobalTransform()[1].xy * 10;
		//if (sfw::getKey(' ')) // breaking force
		//{
		//	rb.force += -rb.velocity * 20;
		//	rb.torque += -rb.angularVelocity * 20;
		//}

		if (sfw::getKey('D'))
		{
			rb.velocity.x = t.GetGlobalTransform()[0].x * 500.f * sfw::getDeltaTime();
			
		}
		else
		{
			rb.velocity.x = 0;
		}
		if (sfw::getKey('A'))
		{
			rb.velocity.x = -t.GetGlobalTransform()[0].x * 500.f * sfw::getDeltaTime();
		}
		
		if (!sfw::getKey('D') && !sfw::getKey('A'))
			rb.velocity.x = 0;
	}
};
