#ifndef KEYHANDLER_H
#define KEYHANDLER_H

#include <SFML/Window/Event.hpp>

class KeyHandler
{
public:
	bool wPressed, sPressed, dPressed, aPressed;
	KeyHandler() {
		wPressed = false;
		sPressed = false;
		dPressed = false;
		aPressed = false;
	}

	void handleKeyPress(sf::Event::KeyEvent key);
	void handleKeyRelease(sf::Event::KeyEvent key);
};

#endif // !KEYHANDLER_H
