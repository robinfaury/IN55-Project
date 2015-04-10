#ifndef _ENGINE_H
#define _ENGINE_H

#include "fr.utbm.in55.graphic\GraphicEngine.h"
#include "fr.utbm.in55.physic\PhysicEngine.h"
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

class Engine
{
private:
	sf::Window* window;
	int antialiasingLevel;
	int depthBits;
	int majorVersion;
	int minorVersion;
	int stencilBits;
	int sizeWindow_x;
	int sizeWindow_y;
	std::string windowName;

	GraphicEngine graphic;
	PhysicEngine physic;

	void openWindow();


public:
	Engine();

	void setOpenGLParametters(int antialiasingLevel, int depthBits, int majorVersion, int minorVersion, int stencilBits);
	void init(int sizeWindow_x = 800, int sizeWindow_y = 600, std::string windowName = "Default Name");
	void run();

	~Engine();
};

#endif