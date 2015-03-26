#pragma once

#include "SFML\Graphics.hpp"
#include "Button.h"

class InteractionWindow
{
public:
	InteractionWindow(sf::VideoMode videoMode);
	~InteractionWindow();

	bool isRunning();

	// Closes the interaction window
	void close();

	// Goes through all events that occured since last frame, and resolves them
	void processEvents();

	void draw();

	//TODO: add buttons

protected:

	sf::RenderWindow m_window;
	bool running;
};

