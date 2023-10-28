#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include <memory>
#include "Player.h"
#include "WorldMap.h"
#include "KeyHandler.h"
#include "RayCaster.h"
class Game
{
public:
	sf::RenderWindow window;
	std::shared_ptr<KeyHandler> keyH;
	std::shared_ptr<Player> player;
	std::unique_ptr<RayCaster> rayC;
	WorldMap worldMap;

	Game() {
		window.create(sf::VideoMode(SCREEN_WIDTH + RENDER_FRAME_WIDTH, SCREEN_HEIGHT), TITLE, sf::Style::None);
		window.setFramerateLimit(60);
		keyH = std::make_shared<KeyHandler>();
		player = std::make_shared<Player>(Vec2(3, 5), keyH);
		rayC = std::make_unique<RayCaster>(player, keyH);
		worldMap = WorldMap();
	}
	

	void start();
	void update(double dt);
	void render();
	
};

#endif // !GAME_H
