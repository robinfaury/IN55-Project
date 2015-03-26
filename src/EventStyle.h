#ifndef EVENTSTYLE_H_
#define EVENTSTYLE_H_

#include <SFML/Graphics.hpp>

#include "World.h"
#include "InteractionWindow.h"

class EventStyle
{
private:
	World* world;
	sf::Window* window;
	InteractionWindow* interactWindow;

public:
	EventStyle();

	void interpretEvent(sf::Event e);

	// Setter
	void setWindow(sf::Window* window, InteractionWindow* interactWindow) { this->window = window; this->interactWindow = interactWindow; }

	~EventStyle();
};

#endif