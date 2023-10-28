#ifndef PLAYER_H
#define PLAYER_H
#include "Vec2.h"
#include <SFML/Graphics.hpp>
#include "KeyHandler.h"

class Player : sf::Drawable
{
public:
	Vec2 pos, dir;
	std::shared_ptr<KeyHandler> keyH;

	Player() : pos{ 5, 5 }, dir{ -1, 0 } {
		keyH = std::make_shared<KeyHandler>();
	}
	Player(Vec2 pos, std::shared_ptr<KeyHandler> k) : pos(pos), dir(Vec2(-1, 0).normalized()), keyH(k) {}

	void translate(double dt);
	void rotate(double dt);
	void update(double dt);
	Vec2 checkCollision(Vec2 nextPos);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif // !PLAYER_H
