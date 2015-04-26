#ifndef INTERACTIONEVENT_H_
#define INTERACTIONEVENT_H_

#include <GL/glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>

#include "Camera.h"

class InteractionEvent
{
private:
	sf::Window* window;
	Camera* currentCamera;
	bool running;
	bool keyPressed[sf::Keyboard::KeyCount];
	int mousePosX, mousePosY;
	int wheel;

public:
	InteractionEvent();

	void checkEvent();
	bool makeAction();

	void setWindow(sf::Window* window) {this->window = window;}
	void setCurrentCamera(Camera* camera) {this->currentCamera = camera;}

	~InteractionEvent();
};

#endif