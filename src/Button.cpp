#include "Button.h"


Button::Button(int x, int y, string text, sf::Font font, sf::Color color, sf::Color colorActivated, int length, int height) :
m_color(color), m_color_activated(colorActivated), m_text(text, font), m_rect(sf::Vector2f(length, height))
{
	m_rect.setPosition(x, y);
	updateTextPos();
}


Button::~Button()
{

}

sf::Text* Button::getText()
{
	return &m_text;
}

void Button::setText(string text)
{
	m_text.setString(text);
	updateTextPos();
}

sf::Color Button::getColor()
{
	return m_color;
}

sf::Color Button::getColorActivated()
{
	return m_color_activated;
}

void Button::activated()
{
	m_activated = true;
}

void Button::draw(sf::RenderWindow* window)
{
	if (m_activated)
	{
		m_rect.setFillColor(m_color_activated);
		window->draw(m_rect);
		m_rect.setFillColor(m_color);
		m_activated = false;
	}
	else
		window->draw(m_rect);
		
	window->draw(m_text);
}


// Private functions
void Button::updateTextPos()
{
	sf::FloatRect tempRect = m_rect.getGlobalBounds();
	sf::FloatRect tempText = m_text.getGlobalBounds();
	m_text.setPosition(tempRect.left + tempRect.width / 2 - tempText.width / 2,
		tempRect.top + tempRect.height / 2 - tempText.height / 2);
}