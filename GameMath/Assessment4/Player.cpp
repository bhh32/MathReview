#include "Player.h"
#include "sfwdraw.h"

Player::Player()
{
	playerSprite = sfw::loadTextureMap("res/blueCar.png");
}

void Player::Draw()
{
	sfw::drawTexture(playerSprite, playerTransform.position.x, playerTransform.position.y, 75, 110);
}

void Player::DebugDraw(const mat3 &t, float drawing_scale)
{
	// Origin Position
	vec2 pos = t[2].xy;

	vec2 rightEP = pos + t[0].xy * drawing_scale;
	vec2 upEP = pos + t[1].xy * drawing_scale;

	sfw::drawLine(pos.x, pos.y, rightEP.x, rightEP.y, RED);
	sfw::drawLine(pos.x, pos.y, upEP.x, upEP.y, GREEN);

	sfw::drawCircle(pos.x, pos.y, drawing_scale / 4);
}