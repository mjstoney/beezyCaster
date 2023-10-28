#ifndef RAYCASTER_H
#define RAYCASTER_H

#include "Definitions.h"
#include "Vec2.h"
#include "Player.h"

class RayCaster : sf::Drawable
{
	Vec2 pos, dir, plane;
	std::vector<sf::VertexArray> renderLines;
	std::shared_ptr<Player> player;
	std::shared_ptr<KeyHandler> keyH;
public:
	RayCaster() {
		plane = Vec2(0, -0.66);
		player = std::make_shared<Player>();
	}
	RayCaster(std::shared_ptr<Player> p, std::shared_ptr<KeyHandler> k) {
		plane = Vec2(0, -0.66);
		player = p;
		keyH = k;
	}
	void update(float dt);
	void rotate(double dt);
	void castRays();
	void castRay(Vec2 orig, Vec2 dir, int renderX, std::vector<sf::VertexArray>& renderLines);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;

};

#endif // !RAYCASTER_H
