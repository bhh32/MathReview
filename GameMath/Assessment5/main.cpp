#include "GameManager.h"

int main()
{
	Transform A;
	Transform B;

	A.position  = { 40,40 };
	A.demension = { 2,2 };
	B.position  = { 20,20 };
	B.demension = { 2,2 };

	A.setParent(&B);
	A.setParent();



	GameLoop();

	return 0;	
}