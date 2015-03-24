#ifndef OPENGLWINDOW_H_
#define OPENGLWINDOW_H_

#include "World.h"
#include "EventStyle.h"
#include <SFML/OpenGL.hpp>
#include <chrono>

class OpenGLWindow
{
private:
	World world;
	EventStyle eventStyle;
	sf::Window* window;

public:
	OpenGLWindow();
	OpenGLWindow(int height, int width, std::string name);
	OpenGLWindow(int height, int width, std::string name, int antialiasingLevel, int depthBits, int majorVersion, int minorVersion, int stencilBits);

	void createWorld();
	void run();

	~OpenGLWindow();
};

#endif