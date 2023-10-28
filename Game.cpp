#include "Game.h"
#include <iostream>
void Game::start()
{
	sf::Clock clock;
	double deltaTime = 0.0f;
	const double fixedTimeStep = 1.0 / FPS;

	while (window.isOpen()) {
		sf::Event e;
		while (window.pollEvent(e)) {
			if (e.type == e.Closed)
				window.close();
			if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
				window.close();
			if (e.type == sf::Event::KeyPressed)
				keyH->handleKeyPress(e.key);
			if (e.type == sf::Event::KeyReleased)
				keyH->handleKeyRelease(e.key);
		}	
		update(fixedTimeStep);
		
		window.clear();
		render();
		window.display();
	}

}

void Game::update(double dt) {
	player->update(dt);
	rayC->update(dt);
	rayC->castRays();
}

void Game::render() {
	worldMap.draw(window, sf::RenderStates::Default);
	player->draw(window, sf::RenderStates::Default);
	rayC->draw(window, sf::RenderStates::Default);

}
