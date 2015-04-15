#ifndef _ENGINE_H
#define _ENGINE_H

#include <SFML/Window.hpp>

#include "GraphicEngine.h"

class Engine
{
private:
	sf::Window* renderWindow;
	GraphicEngine graphic;
	
public:
	Engine();

	void InitializeWindow(std::string windowName = "Default name", int height = 800, int width = 600, int OpenGLMajorVersion = 3, int OpenGLMinorVersion = 3, int antialiasingLevel = 4, int depthBits = 24, int stencilBits = 8);
	void init();
	void run();

	~Engine();
};

#endif