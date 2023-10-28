#ifndef WORLDMAP_H
#define WORLDMAP_H
#include <SFML/Graphics.hpp>
#include "Definitions.h"

class WorldMap : sf::Drawable
{
public:
	WorldMap() {}
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // !WORLDMAP_H
