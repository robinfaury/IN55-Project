#include "InteractionWindow.h"

InteractionWindow::InteractionWindow(sf::VideoMode videoMode) : m_window(videoMode, "Interactions")
{
	running = true;
}	


InteractionWindow::~InteractionWindow()
{
	
}

bool InteractionWindow::isRunning()
{
	return running;
}

void InteractionWindow::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				close();
				break;

			case sf::Event::MouseButtonPressed:
				break;

			default:
				break;
		}
	}
}

void InteractionWindow::close()
{
	m_window.close();
}
