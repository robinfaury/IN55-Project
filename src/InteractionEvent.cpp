#include "InteractionEvent.h"

InteractionEvent::InteractionEvent()
{
	for(int i=0; i<sf::Keyboard::KeyCount; ++i)
		this->keyPressed[i] = false;
	this->wheel = 0;
}

void InteractionEvent::checkEvent()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			this->running = false;
		}
		if (event.type == sf::Event::Resized)
		{
			glViewport(0, 0, event.size.width, event.size.height);
		}
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code >= 0)
				this->keyPressed[event.key.code] = true;
		}
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code >= 0)
				this->keyPressed[event.key.code] = false;
		}
		if (event.type == sf::Event::MouseMoved)
		{
			this->mousePosX = event.mouseMove.x;
			this->mousePosY = event.mouseMove.y;
		}
		if (event.type == sf::Event::MouseWheelMoved)
		{
			this->wheel = event.mouseWheel.delta;
		}

	}
}

bool InteractionEvent::makeAction()
{
	if (this->keyPressed[sf::Keyboard::Z])
		this->currentCamera->move(0.1f);
	if (this->keyPressed[sf::Keyboard::S])
		this->currentCamera->move(-0.1f);
	if (this->keyPressed[sf::Keyboard::Q])
		this->currentCamera->straf(0.1f);
	if (this->keyPressed[sf::Keyboard::D])
		this->currentCamera->straf(-0.1f);
	if (this->keyPressed[sf::Keyboard::Escape])
		this->running = false;

	if (this->wheel != 0)
		this->currentCamera->climb(this->wheel*0.1f);
	this->wheel = 0;
	
	this->currentCamera->oriente(this->mousePosX - window->getSize().x/2, this->mousePosY - window->getSize().y/2);
	sf::Mouse::setPosition(sf::Vector2i(static_cast<unsigned int>(this->window->getSize().x/2), static_cast<unsigned int>(this->window->getSize().y/2)), *this->window);

	return running;
}

InteractionEvent::~InteractionEvent()
{

}
