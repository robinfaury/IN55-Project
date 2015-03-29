#include "Button.h"
#include <iostream>

Button::Button(int x, int y, string text, sf::Font& font, int length, int height, sf::Color color, sf::Color colorHovered, sf::Color colorActivated, sf::Color colorText, sf::Color colorTextHovered, sf::Color colorTextActivated) :
m_rect(sf::Vector2f(length, height)), m_color(color), m_color_hovered(colorHovered), m_color_activated(colorActivated), m_color_text(colorText), m_color_text_hovered(colorTextHovered), m_color_text_activated(colorTextActivated)
{
	m_text.setString(text);
	m_text.setFont(font);
	m_text.setCharacterSize(14);
	m_rect.setPosition(x, y);
	m_hovered = false;
	m_activated = false;
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

sf::Color Button::getColorHovered()
{
	return m_color_hovered;
}

sf::RectangleShape Button::getRect()
{
	return m_rect;
}

bool Button::isActivated()
{
	return m_activated;
}

void Button::setActivated(bool activated)
{
	m_activated = activated;
}

void Button::setHovered(bool hovered)
{
	m_hovered = hovered;
}

void Button::draw(sf::RenderWindow* window)
{
	if (m_activated)
	{
		
		m_rect.setFillColor(m_color_activated);
		m_text.setColor(m_color_text_activated);
	}
	else if (m_hovered)
	{
		m_rect.setFillColor(m_color_hovered);
		m_text.setColor(m_color_text_hovered);
	}
	else
	{
		m_rect.setFillColor(m_color);
		m_text.setColor(m_color_text);
	}
	window->draw(m_rect);
	window->draw(m_text);
}


// Private functions
void Button::updateTextPos()
{
	sf::FloatRect tempRect = m_rect.getGlobalBounds();
	sf::FloatRect tempText = m_text.getGlobalBounds();
	m_text.setPosition(m_rect.getPosition().x + tempRect.width / 2 - tempText.width / 2, m_rect.getPosition().y);
}