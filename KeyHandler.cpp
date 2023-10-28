#include "KeyHandler.h"
#include <iostream>
void KeyHandler::handleKeyPress(sf::Event::KeyEvent key)
{
	if (key.code == sf::Keyboard::S) sPressed = true;
	if (key.code == sf::Keyboard::A) aPressed = true;
	if (key.code == sf::Keyboard::D) dPressed = true;
	if (key.code == sf::Keyboard::W) wPressed = true;
	//std::cout << aPressed << " " << sPressed << " " << wPressed << " " << dPressed << "\n";
}

void KeyHandler::handleKeyRelease(sf::Event::KeyEvent key)
{
	if (key.code == sf::Keyboard::S) sPressed = false;
	if (key.code == sf::Keyboard::A) aPressed = false;
	if (key.code == sf::Keyboard::D) dPressed = false;
	if (key.code == sf::Keyboard::W) wPressed = false;
}
