#include <iostream>
//#include "vec2.h"
//#include "vec3.h"
//#include "mat3.h"
//#include "mathutils.h"
//#include <assert.h>
#include "sfwdraw.h"
//#include "Transform.h"
//#include "Rigidbody.h"
//#include "Shapes.h"
#include "DrawShape.h"
#include "Player.h"

using std::cout;
using std::endl;

int main()
{
	/*
	//cout << "Vector2 Tests" << endl;
	//cout << endl;

	//vec2 testA;
	//testA.x = 7;
	//testA.y = 1;

	//vec2 testB;
	//testB.x = 3;
	//testB.y = 2;

	//// Addition
	//vec2 vecSum = testA + testB;
	//cout << "(" << vecSum.x << ", " << vecSum.y << ")" << endl;

	//vecSum += testB;
	//cout << "(" << vecSum.x << ", " << vecSum.y << ")" << endl;

	//// Subtraction
	//vec2 vecDiff = testA - testB;
	//cout << "(" << vecDiff.x << ", " << vecDiff.y << ")" << endl;

	//vecDiff -= testA;
	//cout << "(" << vecDiff.x << ", " << vecDiff.y << ")" << endl;

	//// Scalar Multiplication
	//vec2 scalarMult = 3.0f * testA;
	//cout << "(" << scalarMult.x << ", " << scalarMult.y << ")" << endl;

	//scalarMult = testB * 3.0f;
	//cout << "(" << scalarMult.x << ", " << scalarMult.y << ")" << endl;

	//scalarMult *= 5.f;
	//cout << "(" << scalarMult.x << ", " << scalarMult.y << ")" << endl;

	//// Scalar Division
	//vec2 scalarDiv = testA / 5.0f;
	//cout << "(" << scalarDiv.x << ", " << scalarDiv.y << ")" << endl;

	//scalarDiv /= 10.f;
	//cout << "(" << scalarDiv.x << ", " << scalarDiv.y << ")" << endl;

	//// Logical Operators
	//bool check = scalarDiv == vecDiff ? true : false;

	//if (check)
	//	cout << "true" << endl;
	//else
	//	cout << "false" << endl;

	//check = scalarDiv != vecDiff ? true : false;

	//if (check)
	//	cout << "true" << endl;
	//else
	//	cout << "false" << endl;

	//testA.v[0] = 12.f;
	//testA.v[1] = 3.f;

	//// Subscript Operator
	//for (int i = 0; i < 2; ++i)
	//{
	//	cout << testA.v[i] << endl;
	//}

	//// Magnitude
	//vec2 mag1 = { 0, 1 };
	//vec2 mag2 = { 1, 1 };
	//vec2 mag3 = { -2, 3 };

	//cout << mag1.Magnitude() << endl;
	//cout << mag2.Magnitude() << endl;
	//cout << mag3.Magnitude() << endl;

	//// Normal
	//vec2 mag1Norm = mag1.Normal();
	//vec2 mag2Norm = mag2.Normal();
	//vec2 mag3Norm = mag3.Normal();
	//cout << "(" << mag1Norm.x << ", " << mag1Norm.y << ")" << endl;
	//cout << "(" << mag2Norm.x << ", " << mag2Norm.y << ")" << endl;
	//cout << "(" << mag3Norm.x << ", " << mag3Norm.y << ")" << endl;

	//// Normalize
	//mag1.Normalize();
	//mag2.Normalize();
	//mag3.Normalize();
	//cout << "(" << mag1.x << ", " << mag1.y << ")" << endl;
	//cout << "(" << mag2.x << ", " << mag2.y << ")" << endl;
	//cout << "(" << mag3.x << ", " << mag3.y << ")" << endl;

	//// Dot Product
	//cout << DotProduct({ 2, 3 }, { 7, 5 }) << endl;
	//cout << DotProduct({1, 0}, {1, 1}) << endl;
	//cout << DotProduct({4, 0}, {1, -3}) << endl;

	//// Distance
	//cout << Distance({ 4, 0 }, { 1, -3 }) << endl;
	//cout << Distance({ 8, 2 }, { 1, 4 }) << endl;
	//cout << Distance({ 5, 12 }, { 0, 0 }) << endl;

	//// Perpendicular Vector
	//cout << "(" << Perpendicular({ 4, 0 }).x << ", " << Perpendicular({ 4, 0 }).y << ")" << endl;
	//cout << "(" << Perpendicular({ 8, 2 }).x << ", " << Perpendicular({ 8, 2 }).y << ")" << endl;
	//cout << "(" << Perpendicular({ -5, -12 }).x << ", " << Perpendicular({ -5, -12 }).y << ")" << endl;

	//// Lerp
	//cout << "(" << Lerp({ 0, 0 }, { 0, 5 }, 0.5f).x << ", " << Lerp({ 0, 0 }, { 0, 5 }, 0.5f).y << ")" << endl;
	//cout << "(" << Lerp({ 0, 0 }, { 1, 1 }, 0.0f).x << ", " << Lerp({ 0, 0 }, { 1, 1 }, 0.0f).y << ")" << endl;
	//cout << "(" << Lerp({ 5, 12 }, { 7, 4 }, 1.0f).x << ", " << Lerp({ 5, 12 }, { 7, 4 }, 1.0f).y << ")" << endl;

	//// Min
	//cout << "Min " << "(" << Min({ 4, 0 }, { 1, -3 }).x << ", " << Min({ 4, 0 }, { 1, -3 }).y << ")" << endl;
	//cout << "(" << Min({ 8, 2 }, { 1, 4 }).x << ", " << Min({ 8, 2 }, { 1, 4 }).y << ")" << endl;
	//cout << "(" << Min({ 5, 12 }, { 0, 0 }).x << ", " << Min({ 5, 12 }, { 0, 0 }).y << ")" << endl;

	//// Max
	//cout << "Max " << "(" << Max({ 4, 0 }, { 1, -3 }).x << ", " << Max({ 4, 0 }, { 1, -3 }).y << ")" << endl;
	//cout << "(" << Max({ 8, 2 }, { 1, 4 }).x << ", " << Max({ 8, 2 }, { 1, 4 }).y << ")" << endl;
	//cout << "(" << Max({ 5, 12 }, { 0, 0 }).x << ", " << Max({ 5, 12 }, { 0, 0 }).y << ")" << endl;
	//std::cout << std::endl;

	//cout << "Vector3 Tests" << endl;
	//vec3 testA2;
	//testA2.x = 7;
	//testA2.y = 1;
	//testA2.z = 4;

	//vec3 testB2;
	//testB2.x = 3;
	//testB2.y = 2;
	//testB2.z = 1;

	//// Addition
	//cout << "Vec3 + Operator Test" << endl;
	//vec3 vecSum2 = testA2 + testB2;
	//cout << "(" << vecSum2.x << ", " << vecSum2.y << ", " << vecSum2.z << ")" << endl;
	//cout << endl;

	//cout << "Vec3 += Operator Test" << endl;
	//vecSum2 += testB2;
	//cout << "(" << vecSum2.x << ", " << vecSum2.y << ", " << vecSum2.z << ")" << endl;
	//cout << endl;

	//// Subtraction
	//cout << "Vec3 - Operator Test" << endl;
	//testA2 = { 2, 5, 0 };
	//testB2 = { 4, 8 , 6 };
	//vec3 vecDiff2 = testA2 - testB2;
	//cout << "(" << vecDiff2.x << ", " << vecDiff2.y << ", " << vecDiff2.z << ")" << endl;
	//cout << endl;

	//cout << "Vec3 -= Operator Test" << endl;
	//vecDiff2 -= testA2;
	//cout << "(" << vecDiff2.x << ", " << vecDiff2.y << ", " << vecDiff2.z << ")" << endl;
	//cout << endl;

	//// Scalar Multiplication
	//cout << "Vec3 Scalar * vec3 Operator Test" << endl;
	//testA2 = { 2, 2, 1 };
	//vec3 scalarMult2 = 3.0f * testA2;
	//cout << "(" << scalarMult2.x << ", " << scalarMult2.y << ", " << scalarMult2.z << ")" << endl;
	//cout << endl;

	//cout << "Vec3 vec3 * scalar Operator Test" << endl;
	//scalarMult2 = testA2 * 3.0f;
	//cout << "(" << scalarMult2.x << ", " << scalarMult2.y << ", " << scalarMult2.z << ")" << endl;

	//scalarMult2 *= 5.f;
	//cout << "(" << scalarMult2.x << ", " << scalarMult2.y << ", " << scalarMult2.z << ")" << endl;
	//cout << endl;

	//// Scalar Division
	//cout << "Vec3 / Operator Test" << endl;
	//testA2 = { 6, 6, 2 };
	//vec3 scalarDiv2 = testA2 / 2.0f;
	//cout << "(" << scalarDiv2.x << ", " << scalarDiv2.y << ", " << scalarDiv2.z << ")" << endl;
	//cout << endl;

	//cout << "Vec3 /= Operator Test" << endl;
	//scalarDiv2 /= 10.f;
	//cout << "(" << scalarDiv2.x << ", " << scalarDiv2.y << ", " << scalarDiv2.z << ")" << endl;
	//cout << endl;

	//// Logical Operators
	//cout << "Vec3 Logical Operators Test" << endl;
	//bool check2 = scalarDiv2 == vecDiff2 ? true : false;

	//if (check2)
	//	cout << "true" << endl;
	//else
	//	cout << "false" << endl;

	//check2 = scalarDiv2 != vecDiff2 ? true : false;

	//if (check2)
	//	cout << "true" << endl;
	//else
	//	cout << "false" << endl;

	//testA2.v[0] = 12.6f;
	//testA2.v[1] = 3.12f;
	//testA2.v[2] = 8.9f;
	//cout << endl;

	//// Subscript Operator
	//cout << "Vec3 Subscript Operator Test" << endl;
	//testA2 = { 7, 4, 9 };
	//for (int i = 0; i < 3; ++i)
	//{
	//	cout << "testA index " << i << ": " << testA2.v[i] << endl;
	//}
	//cout << endl;
	//// Magnitude
	//cout << "Vec3 Magnitude Function Test" << endl;

	//vec3 mag4 = { 0, 1, 0 };
	//vec3 mag5 = { 1, 1, 1 };
	//vec3 mag6 = { -2, 3, 2 };

	//cout << mag4.Magnitude() << endl;
	//cout << mag5.Magnitude() << endl;
	//cout << mag6.Magnitude() << endl;
	//cout << endl;

	//// Normal
	//cout << "Vec3 Normal Function Test" << endl;
	//mag4 = { 0, 1, 0 };
	//mag5 = { 1, 1, 1 };
	//mag6 = { -2, 3, 7 };

	//vec3 mag4Norm = mag4.Normal();
	//vec3 mag5Norm = mag5.Normal();
	//vec3 mag6Norm = mag6.Normal();
	//cout << "(" << mag4Norm.x << ", " << mag4Norm.y << ", " << mag4Norm.z << ")" << endl;
	//cout << "(" << mag5Norm.x << ", " << mag5Norm.y << ", " << mag5Norm.z << ")" << endl;
	//cout << "(" << mag6Norm.x << ", " << mag6Norm.y << ", " << mag6Norm.z << ")" << endl;
	//cout << endl;

	//// Normalize
	//cout << "Vec3 Normalize Function Test\n";
	//mag4.Normalize();
	//mag5.Normalize();
	//mag6.Normalize();
	//cout << "(" << mag4.x << ", " << mag4.y << ")" << endl;
	//cout << "(" << mag5.x << ", " << mag5.y << ")" << endl;
	//cout << "(" << mag6.x << ", " << mag6.y << ")" << endl;
	//cout << endl;

	//// Dot Product
	//cout << "Vec3 Dot Product Function Test" << endl;
	//vec3 dotA = { 7, 2, 4 };
	//vec3 dotB = { 9, 4, 7 };
	//cout << "Dot Product: " << DotProductVec3(dotA, dotB) << endl;
	//dotA = { 1, 1, 0 };
	//dotB = { 1, 0, 0 };
	//cout << "Dot Product: " << DotProductVec3(dotA, dotB) << endl;
	//dotA = { 4, 7, 4 };
	//dotB = { 8, 2, 3 };
	//cout << "Dot Product: " << DotProductVec3(dotA, dotB) << endl;
	//cout << endl;

	//// Cross Product
	//cout << "Vec3 Cross Product Function Test" << endl;
	//dotA = { 7, 2, 4 };
	//dotB = { 9, 4, 7 };
	//cout << "(" << CrossProduct(dotA, dotB).x << ", " << CrossProduct(dotA, dotB).y << ", " << CrossProduct(dotA, dotB).z << ")" << endl;
	//dotA = { 1, 1, 0 };
	//dotB = { 1, 0, 0 };
	//cout << "(" << CrossProduct(dotA, dotB).x << ", " << CrossProduct(dotA, dotB).y << ", " << CrossProduct(dotA, dotB).z << ")" << endl;
	//dotA = { 4, 7, 4 };
	//dotB = { 8, 2, 3 };
	//cout << "(" << CrossProduct(dotA, dotB).x << ", " << CrossProduct(dotA, dotB).y << ", " << CrossProduct(dotA, dotB).z << ")" << endl;

	//cout << endl;

	//// Distance
	//cout << "Vec3 Distance Function Test" << endl;
	//dotA = { 7, 2, 4 };
	//dotB = { 9, 4, 7 };
	//cout << "Dist Vec3: " << DistanceVec3(dotA, dotB) << endl;
	//dotA = { 1, 1, 0 };
	//dotB = { 1, 0, 0 };
	//cout << "Dist Vec3: " << DistanceVec3(dotA, dotB) << endl;
	//dotA = { 4, 7, 4 };
	//dotB = { 8, 2, 3 };
	//cout << "Dist Vec3: " << DistanceVec3(dotA, dotB) << endl;
	//cout << endl;

	//// Lerp
	//cout << "Vec3 Lerp Function Test" << endl;
	//vec3 lerpA = { 0, 0, 12 };
	//vec3 lerpB = { 0, 5, 6 };
	//float time = .5f;
	//cout << "(" << LerpVec3(lerpA, lerpB, time).x << ", " << LerpVec3(lerpA, lerpB, time).y << ", " << LerpVec3(lerpA, lerpB, time).z << ")" << endl;
	//lerpA = { 0, 0, 1 };
	//lerpB = { 1, 1, 12 };
	//time = .25f;
	//cout << "(" << LerpVec3(lerpA, lerpB, time).x << ", " << LerpVec3(lerpA, lerpB, time).y << ", " << LerpVec3(lerpA, lerpB, time).z << ")" << endl;
	//lerpA = { 5, 12, 8 };
	//lerpB = { 7, 4, 13 };
	//time = 1.f;
	//cout << "(" << LerpVec3(lerpA, lerpB, time).x << ", " << LerpVec3(lerpA, lerpB, time).y << ", " << LerpVec3(lerpA, lerpB, time).z << ")" << endl;
	//cout << endl;

	//// Min
	//cout << "Vec3 Min Function Test" << endl;
	//vec3 checkVecA = { 7, 2, 4 };
	//vec3 checkVecB = { 9, 4, 7 };
	//cout << "(" << MinVec3(checkVecA, checkVecB).x << ", " << MinVec3(checkVecA, checkVecB).y << ", " << MinVec3(checkVecA, checkVecB).z << ")" << endl;
	//checkVecA = { 1, 1, 0 };
	//checkVecB = { 1, 0, 0 };
	//cout << "(" << MinVec3(checkVecA, checkVecB).x << ", " << MinVec3(checkVecA, checkVecB).y << ", " <<  MinVec3(checkVecA, checkVecB).z << ")" << endl;
	//checkVecA = { 4, 7, 4 };
	//checkVecB = { 8, 2, 3 };
	//cout << "(" << MinVec3(checkVecA, checkVecB).x << ", " << MinVec3(checkVecA, checkVecB).y << ", " << MinVec3(checkVecA, checkVecB).z << ")" << endl;
	//cout << endl;

	//// Max
	//cout << "Vec3 Max Function Test" << endl;
	//cout << "(" << MaxVec3({ 7, 2, 4 }, { 9, 4, 7 }).x << ", " << MaxVec3({ 7, 2, 4 }, { 9, 4, 7 }).y << ", " << MaxVec3({ 7, 2, 4 }, { 9, 4, 7 }).z << ")" << endl;
	//cout << "(" << MaxVec3({ 1, 1, 0 }, { 1, 0, 0 }).x << ", " << MaxVec3({ 1, 1, 0 }, { 1, 0, 0 }).y << ", " << MaxVec3({ 1, 1, 0 }, { 1, 0, 0 }).z << ")" << endl;
	//cout << "(" << MaxVec3({ 4, 7, 4 }, { 8, 2, 3 }).x << ", " << MaxVec3({ 4, 7, 4 }, { 8, 2, 3 }).y << ", " << MaxVec3({ 4, 7, 4 }, { 8, 2, 3 }).z << ")" << endl;
	//cout << endl;

	//// Clamp
	//cout << "Vec3 Clamp Function Test" << endl;
	//vec3 vector = { 9, 3, 1 };
	//vec3 min = { 7, 2, 4 };
	//vec3 max = { 9, 4, 7 };
	//cout << "(" << Clamp(vector, min, max).x << ", " << Clamp(vector, min, max).y << ", " << Clamp(vector, min, max).z << ")" << endl;

	//vector = { 8,2,8 };
	//min = { 1,1,0 };
	//max = { 1,2,0 };
	//cout << "(" << Clamp(vector, min, max).x << ", " << Clamp(vector, min, max).y << ", " << Clamp(vector, min, max).z << ")" << endl;

	//vector = { 4,5,6 };
	//min = { 4,7,4 };
	//max = { 8,9,7 };
	//cout << "(" << Clamp(vector, min, max).x << ", " << Clamp(vector, min, max).y << ", " << Clamp(vector, min, max).z << ")" << endl;
	//cout << endl; */

	/*	mat3 A = { 3, 0, 2,
				   2, 0, -2,
				   0, 1, 1 };

		mat3 check = A * Inverse(A);

		cout << "A * Inverse(A): \n";
		cout << "                " << check.m[0] << " " << check.m[1] << " " << check.m[2] << endl;
		cout << "                " << check.m[3] << " " << check.m[4] << " " << check.m[5] << endl;
		cout << "                " << check.m[6] << " " << check.m[7] << " " << check.m[8] << endl;

		cout << endl;

	mat3 inverse = Inverse(A);

	cout << "The Inverse of matrix A is: " << inverse.m[0] << " " << inverse.m[1] << " " << inverse.m[2] << endl;
	cout << "                            " << inverse.m[3] << " " << inverse.m[4] << " " << inverse.m[5] << endl;
	cout << "                            " << inverse.m[6] << " " << inverse.m[7] << " " << inverse.m[8] << endl;

	*/

	/*mat3 T = Scale(vec2{ 1,2 }) * 
		     Rotation(90) * 
		     Translate(vec2{ 3, 0 });

	assert((T[2].xy == vec2{ 0, 6 }));*/

	sfw::initContext();

	/** Transform Tests **/

	/*Transform myTransform;
	myTransform.position = vec2{ 300, 400 };
	myTransform.demension = vec2{ 1, 1 };

	Transform myBaby;
	myBaby.position = vec2{ 10, 10 };
	myBaby.demension = vec2{ 1, 1 };
	myBaby.e_parent = &myTransform;*/

	/** Rigidbody tests **/

	Player player;

	player.sprite = sfw::loadTextureMap("../resources/classic_ship.png");
	player.transform.demension = vec2{ 48, 48 };
	player.transform.position = vec2{ 400, 300 };
	player.collider.box.extents = { .5, .5 };

	Wall walls[2];

	walls[0].sprite = sfw::loadTextureMap("../resources/wall.png");
	walls[0].transform.demension = vec2{ 24, 600 };
	walls[0].transform.position = vec2{ 15, 300 };
	walls[0].collider.box.extents = { .5, .5 };

	walls[1].sprite = sfw::loadTextureMap("../resources/wall.png");
	walls[1].transform.demension = vec2{ 24, 600 };
	walls[1].transform.position = vec2{ 785, 300 };
	walls[1].collider.box.extents = { .5, .5 };

	Ball ball;
	ball.sprite = sfw::loadTextureMap("../resources/kirby_ball.png");
	ball.transform.demension = vec2{ 37, 37 };
	ball.transform.position = vec2{ 350, 400 };
	ball.collider.box.extents = { .5, .5 };
	ball.rigidbody.velocity = { 200, 0 };
	ball.rigidbody.drag = 0;
	

	while (sfw::stepContext()) 
	{
		/**  Transforms Tests **/
		//float time = sfw::getTime();
		//// Rotate you object around clockwise
		//myTransform.angle += -200 * sfw::getDeltaTime();
		//if (sfw::getKey('A'))
		//{
		//	myBaby.position.x -= 50.f * sfw::getDeltaTime();
		//}

		//if (sfw::getKey('D'))
		//{
		//	myBaby.position.x += 50.f * sfw::getDeltaTime();
		//}

		//if (sfw::getKey('W'))
		//	myBaby.position.y += 50.f * sfw::getDeltaTime();

		//if (sfw::getKey('S'))
		//	myBaby.position.y -= 50.f * sfw::getDeltaTime();
		//
		//// Scale the object
		////myTransform.demension = vec2{ sinf(time) + 2, sinf(time) + 2 };
		//myBaby.demension = vec2{ 5, 5 };

		//DrawMatrix(myTransform.GetGlobalTransform(), 40);
		//DrawMatrix(myBaby.GetGlobalTransform(), 30);

		/**Rigidbody tests **/
		
		float dt = sfw::getDeltaTime();

		// Update Controller
		player.controller.Poll(player.rigidbody, player.transform);

		// Update rigidbodies
		player.rigidbody.Integrate(player.transform, dt);
		ball.rigidbody.Integrate(ball.transform, dt);

		// Draw stuff
		player.sprite.Draw(player.transform);
		DrawAABB(player.collider.GetGlobalBox(player.transform), MAGENTA);
		
		ball.sprite.Draw(ball.transform);
		DrawAABB(ball.collider.GetGlobalBox(ball.transform), RED);

		for (int i = 0; i < 2; ++i)
		{
			walls[i].sprite.Draw(walls[i].transform);
			
			DrawAABB(walls[i].collider.GetGlobalBox(walls[i].transform), BLUE);
		}
		
		// Collision Resolution
		for (int i = 0; i < 2; ++i)
		{
			DoCollision(player, walls[i], .25f);
			DoCollision(ball, walls[i]);
		}
			
	};

	return 0;
}