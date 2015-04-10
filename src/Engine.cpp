#include "Engine.h"


Engine::Engine()
{
	this->window = NULL;
	this->antialiasingLevel = 4;
	this->depthBits = 24;
	this->majorVersion = 3;
	this->minorVersion = 3;
	this->stencilBits = 8;
}

void Engine::setOpenGLParametters(int antialiasingLevel, int depthBits, int majorVersion, int minorVersion, int stencilBits)
{
	this->window = NULL;
	this->antialiasingLevel = antialiasingLevel;
	this->depthBits = depthBits;
	this->majorVersion = majorVersion;
	this->minorVersion = minorVersion;
	this->stencilBits = stencilBits;
}

void Engine::openWindow()
{
	sf::ContextSettings setting;
	setting.antialiasingLevel = this->antialiasingLevel;
	setting.depthBits = this->depthBits;
	setting.majorVersion = this->majorVersion;
	setting.minorVersion = this->minorVersion;
	setting.stencilBits = this->stencilBits;

	this->window = new sf::Window(sf::VideoMode(this->sizeWindow_x, this->sizeWindow_y), this->windowName, sf::Style::Default, setting);
	this->window->setFramerateLimit(30);

	setting = this->window->getSettings();
	std::cout<<"Antialiasing Level : "<<setting.antialiasingLevel<<std::endl;
	std::cout<<"Depth Bits : "<<setting.depthBits<<std::endl;
	std::cout<<"Stencil Bits : "<<setting.stencilBits<<std::endl;
	std::cout<<"OpenGL Version : "<<setting.majorVersion<<"."<<setting.minorVersion<<std::endl;

	glewExperimental = true;
	if (glewInit() != GLEW_OK) 
	{
		std::cout<<"ERROR : Failed to initialize GLEW"<<std::endl;
		return;
	}
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_COORD_ARRAY);
	glEnable(GL_TEXTURE);
}

void Engine::init(int sizeWindow_x, int sizeWindow_y, std::string windowName)
{
	this->sizeWindow_x = sizeWindow_x;
	this->sizeWindow_y = sizeWindow_y;
	this->windowName = windowName;
  	openWindow();
	this->graphic.init();
}

void Engine::run()
{
	std::chrono::system_clock::time_point start_time, end_time;

	sf::Event event;
	while (this->window->isOpen()) 
	{
		start_time = std::chrono::high_resolution_clock::now();

		glClearColor(0.2f, 0.0f, 0.0f, 0.0f);

		//Event
		while (this->window->pollEvent(event)) 
		{
			switch(event.type)
			{
			case sf::Event::Closed:
				this->window->close();
				break;
			}
		}

		//Drawing
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		this->graphic.update(0.0, 0.0, std::chrono::high_resolution_clock::now());
		this->physic.compute(this->graphic.getStaticObject(), this->graphic.getDynamicObject());
		this->window->display();

		end_time = std::chrono::high_resolution_clock::now();
		if (std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() >= 60)
			std::cout <<"frame rate : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;
	}

	
}

Engine::~Engine()
{
	if (this->window != NULL)
		delete this->window;
}