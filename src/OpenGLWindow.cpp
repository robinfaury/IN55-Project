#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow() : interactWindow(sf::VideoMode(400, 100))
{
	this->window = new sf::Window(sf::VideoMode(800, 600), "test");
}

OpenGLWindow::OpenGLWindow(int height, int width, std::string name) : interactWindow(sf::VideoMode(400, 100))
{
	this->window = new sf::Window(sf::VideoMode(height, width), name);
}

OpenGLWindow::OpenGLWindow(int height, int width, std::string name, int antialiasingLevel, int depthBits, int majorVersion, int minorVersion, int stencilBits) : interactWindow(sf::VideoMode(400, 100))
{
	sf::ContextSettings setting;
	setting.antialiasingLevel = antialiasingLevel;
	setting.depthBits = depthBits;
	setting.majorVersion = majorVersion;
	setting.minorVersion = minorVersion;
	setting.stencilBits = stencilBits;

	this->window = new sf::Window(sf::VideoMode(height, width), name, sf::Style::Default, setting);
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
	//glDepthFunc(GL_LESS);
	//glDisable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
}

void OpenGLWindow::createWorld()
{
	this->world.createScene();
}

void OpenGLWindow::run()
{
	this->eventStyle.setWindow(this->window, &this->interactWindow);
	glm::mat4 modelView;
	glm::mat4 projection;
	sf::Event Event;

	/******************* SFML Loop *******************/
	double alpha = 0.0;
	double radius = 2.0;
	std::chrono::system_clock::time_point start_time, end_time;
	while (this->window->isOpen()) 
	{
		start_time = std::chrono::high_resolution_clock::now();
		glClearColor(0.2f, 0.0f, 0.0f, 0.0f);
		
		while (this->window->pollEvent(Event)) 
			this->eventStyle.interpretEvent(Event);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::vec3 posCam = glm::vec3(radius*cos(alpha)+radius*sin(alpha), 2 ,-radius*sin(alpha)+radius*cos(alpha));
		glm::mat4 Projection = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
		glm::mat4 View       = glm::lookAt(
									posCam,
									glm::vec3(0,0,0),
									glm::vec3(0,1,0)
							   );
		glm::mat4 Model      = glm::mat4(1.0f);
		glm::mat4 MVP        = Projection * View * Model;

		std::vector<Shader*>* listOfShader = this->world.GetListOfShader();
		std::vector<Object3D*>* listOfMesh = this->world.GetListOfMesh();
		std::vector<Lamp*>* listOfLamp = this->world.GetListOfLamp();
		Shader* shader = (*listOfShader)[0];

		glUseProgram(shader->getProgramID());
			glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "Model"), 1, GL_FALSE, &Model[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "View"), 1, GL_FALSE, &View[0][0]);
			glUniformMatrix4fv(glGetUniformLocation(shader->getProgramID(), "Projection"), 1, GL_FALSE, &Projection[0][0]);

			glm::vec3 pos = (*listOfLamp)[0]->getPosition();
			glUniform3f(glGetUniformLocation(shader->getProgramID(), "PosCamera"), posCam.x, posCam.y, posCam.z);
			glUniform3f(glGetUniformLocation(shader->getProgramID(), "PosLamp01"), pos.x, pos.y, pos.z);
			for (std::vector<Object3D*>::iterator worldObject = listOfMesh->begin(); worldObject != listOfMesh->end(); ++worldObject)
			{
				(*worldObject)->draw(shader->getProgramID());
			}
		glUseProgram(0);

		// Interaction window stuff
		if (interactWindow.isRunning())
		{
			interactWindow.processEvents();
			interactWindow.draw();
		}

		this->window->display();

		alpha += 0.01;

		end_time = std::chrono::high_resolution_clock::now();
		std::cout <<"frame time : "<< std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() << std::endl;

	}
}


OpenGLWindow::~OpenGLWindow()
{
	if (this->window != NULL)
		delete this->window;
}