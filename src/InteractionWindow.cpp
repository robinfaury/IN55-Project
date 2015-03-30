#include "InteractionWindow.h"
#include <iostream>

InteractionWindow::InteractionWindow(sf::VideoMode videoMode) : m_window(videoMode, "Interactions")
{
	m_running = true;

	// Fonts
	sf::Font walkway;
	if (!walkway.loadFromFile("res/fonts/Walkway Bold.ttf"))
	{
		std::cout << "error : font not loaded" << std::endl;
	}
	m_fonts.push_back(walkway);

	//TODO: load other fonts

	// Colors
	sf::Color black = sf::Color::Black;
	sf::Color cyan = sf::Color::Cyan;
	sf::Color blue = sf::Color::Blue;
	sf::Color white = sf::Color::White;

	// m_buttons
	Button* button1 = new Button(50, 50, "Bouton 1", m_fonts[WALKWAY], 100, 20, black, cyan, blue, white, black, black);
	Button* button2 = new Button(200, 70, "Bouton 2", m_fonts[WALKWAY]);
	m_buttons.push_back(button1);
	m_buttons.push_back(button2);
}	


InteractionWindow::~InteractionWindow()
{

}

bool InteractionWindow::isRunning()
{
	return m_running;
}

void InteractionWindow::processEvents()
{
	sf::Event event;
	int eventX, eventY;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::Closed:
				close();
				break;

			case sf::Event::MouseButtonPressed:

				eventX = event.mouseButton.x;
				eventY = event.mouseButton.y;

				for (int i = 0; i < m_buttons.size(); i++)
				{
					sf::Vector2f buttonPos = m_buttons[i]->getRect().getPosition();
					sf::FloatRect buttonBounds = m_buttons[i]->getRect().getGlobalBounds();

					if (eventX >= buttonPos.x && eventX <= buttonPos.x + buttonBounds.width &&
						eventY >= buttonPos.y && eventY <= buttonPos.y + buttonBounds.height)
					{
						m_buttons[i]->setActivated(true);
					}
				}

				break;

			case sf::Event::MouseButtonReleased:

				for (int i = 0; i < m_buttons.size(); i++)
				{
					if (m_buttons[i]->isActivated())
					{
						m_buttons[i]->setActivated(false);
					}
				}

				break;

			case sf::Event::MouseMoved:

				eventX = event.mouseMove.x;
				eventY = event.mouseMove.y;

				for (int i = 0; i < m_buttons.size(); i++)
				{
					sf::Vector2f buttonPos = m_buttons[i]->getRect().getPosition();
					sf::FloatRect buttonBounds = m_buttons[i]->getRect().getGlobalBounds();

					if (eventX >= buttonPos.x && eventX <= buttonPos.x + buttonBounds.width &&
						eventY >= buttonPos.y && eventY <= buttonPos.y + buttonBounds.height)
					{
						m_buttons[i]->setHovered(true);
					}
					else
					{
						m_buttons[i]->setHovered(false);
					}
				}

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

void InteractionWindow::draw()
{
	m_window.clear(sf::Color::White);
	
	// m_buttons
	for (int i = 0; i < m_buttons.size(); i++)
	{
		m_buttons[i]->draw(&this->m_window);
	}

	m_window.display();
}