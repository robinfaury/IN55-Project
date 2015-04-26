#include "Engine.h"


Engine::Engine()
{
	this->renderWindow = NULL;
}

void Engine::InitializeWindow(std::string windowName, int height, int width, int OpenGLMajorVersion, int OpenGLMinorVersion, int antialiasingLevel, int depthBits, int stencilBits)
{
	sf::ContextSettings settings;
	settings.depthBits = depthBits;
	settings.stencilBits = stencilBits;
	settings.antialiasingLevel = antialiasingLevel;
	settings.majorVersion = OpenGLMajorVersion;
	settings.minorVersion = OpenGLMinorVersion;

	this->renderWindow = new sf::Window(sf::VideoMode(height, width), windowName, sf::Style::Default, settings);
	this->renderWindow->setVerticalSyncEnabled(true);
	this->renderWindow->setFramerateLimit(30);

	settings = this->renderWindow->getSettings();
	std::cout << "depth bits:" << settings.depthBits << std::endl;
	std::cout << "stencil bits:" << settings.stencilBits << std::endl;
	std::cout << "antialiasing level:" << settings.antialiasingLevel << std::endl;
	std::cout << "version:" << settings.majorVersion << "." << settings.minorVersion << std::endl;

	glewExperimental = true;
	if (glewInit() != GLEW_OK) 
	{
		std::cout<<"ERROR : Failed to initialize GLEW"<<std::endl;
		return;
	}

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	sf::Mouse::setPosition(sf::Vector2i(static_cast<unsigned int>(this->renderWindow->getSize().x/2), static_cast<unsigned int>(this->renderWindow->getSize().y/2)), *this->renderWindow);
	this->renderWindow->setMouseCursorVisible(false);
}

void Engine::init()
{
	this->graphic.loadLevel();
	this->currentCamera = this->graphic.getCurrentCamera();
	this->interactionEvent.setWindow(this->renderWindow);
	this->interactionEvent.setCurrentCamera(this->currentCamera);
}

void Engine::run()
{
	bool running = true;
	while (running)
	{
		this->interactionEvent.checkEvent();
		running = this->interactionEvent.makeAction();
		
		glClearColor(0.2f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->graphic.draw();

		this->renderWindow->display();
	}
}

Engine::~Engine()
{
	delete this->renderWindow;
}