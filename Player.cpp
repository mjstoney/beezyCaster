#include "Player.h"
#include "Mat2.h"
#include "Definitions.h"
#include <cmath>

#include <iostream>


void Player::update(double dt) 
{
	if (keyH->aPressed || keyH->dPressed || keyH->sPressed || keyH->wPressed) {
		if (keyH->wPressed) translate(PLAYER_SPEED * dt); 
		if (keyH->sPressed) translate(-PLAYER_SPEED * dt);
		if (keyH->aPressed) rotate(-dt);
		if (keyH->dPressed) rotate(dt);
	}
}

Vec2 Player::checkCollision(Vec2 nextPos) 
{
	Vec2 res = pos;
	int currMapX = int(pos.x);
	int currMapY = int(pos.y);
	int nextMapX = nextPos.x;
	int nextMapY = nextPos.y;

	if (MAP[currMapY][nextMapX] == 0) res.x = nextPos.x;
	if (MAP[nextMapY][currMapX] == 0) res.y = nextPos.y;
	return res;
}


void Player::translate(double dt) 
{
	Vec2 nextPos = Vec2();
	double rads = atan2(dir.y, dir.x);
	nextPos.x = pos.x + cos(rads) * dt * PLAYER_SPEED;
	nextPos.y = pos.y + sin(rads) * dt * PLAYER_SPEED;
	pos = checkCollision(nextPos);
}

void Player::rotate(double dt) 
{
	double c = cos(PLAYER_ROTATION * dt);
	double s = sin(PLAYER_ROTATION * dt);
	Mat2 rot(c, -s, s, c);
	dir = rot * dir;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::CircleShape p1(5);
	p1.setFillColor(sf::Color::White);
	p1.setOrigin(p1.getLocalBounds().width / 2, p1.getLocalBounds().height / 2);
	p1.setPosition(sf::Vector2f(pos.x * TILE_WIDTH, pos.y * TILE_HEIGHT));
	target.draw(p1, sf::RenderStates::Default);
}
