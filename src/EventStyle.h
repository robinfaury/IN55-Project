#ifndef EVENTSTYLE_H_
#define EVENTSTYLE_H_

#include <SFML/Graphics.hpp>

#include "World.h"

class EventStyle
{
private:
	World* world;
	sf::Window* window;

public:
	EventStyle();

	void interpretEvent(sf::Event e);

	// Setter
	void setWindow(sf::Window* window) {this->window = window;}

	~EventStyle();
};

#endif