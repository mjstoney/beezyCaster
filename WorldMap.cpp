#include "WorldMap.h"

void WorldMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Vector2f tileSize({ TILE_WIDTH, TILE_HEIGHT });
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			
			sf::RectangleShape r(tileSize);
			r.setPosition(sf::Vector2f(TILE_WIDTH * x, TILE_HEIGHT * y));
			if (MAP[y][x] == 0) r.setFillColor(sf::Color::Black);
			else r.setFillColor(sf::Color::Blue);
			r.setOutlineColor(sf::Color::White);
			r.setOutlineThickness(1);
			target.draw(r);
		}
	}

}
