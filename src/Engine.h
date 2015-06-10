#ifndef _ENGINE_H
#define _ENGINE_H

#include "GraphicEngine.h"
#include "InteractionEvent.h"

#include <chrono>

class Engine
{
private:
	sf::Window* renderWindow;
	GraphicEngine* graphic;
	Camera* currentCamera;
	InteractionEvent interactionEvent;
	
public:
	Engine();

	void InitializeWindow(std::string windowName = "Default name", int height = 800, int width = 600, int OpenGLMajorVersion = 3, int OpenGLMinorVersion = 3, int antialiasingLevel = 4, int depthBits = 24, int stencilBits = 8);
	void init();
	void run();

	~Engine();
};

#endif