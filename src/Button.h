#pragma once

#include <string>
#include "SFML\Graphics.hpp"


using namespace std;

class Button
{
public:
	Button(int x, int y, string text, sf::Font& font, int length = 100, int height = 20, 
		   sf::Color color = sf::Color::Black, sf::Color colorHovered = sf::Color::Cyan, sf::Color colorActivated = sf::Color::Blue, 
		   sf::Color colorText = sf::Color::White, sf::Color colorTextHovered = sf::Color::Black, sf::Color colorTextActivated = sf::Color::Black);
	~Button();

	sf::Text* getText();
	void setText(string text);

	sf::Color getColor();
	sf::Color getColorActivated();
	sf::Color getColorHovered();
	sf::Color getColorText();
	sf::Color getColorTextActivated();
	sf::Color getColorTextHovered();
	sf::RectangleShape getRect();
	bool isActivated();

	void setHovered(bool hovered);
	void setActivated(bool activated);
	
	void draw(sf::RenderWindow* window);

protected:
	sf::RectangleShape m_rect;
	sf::Color m_color;
	sf::Color m_color_activated;
	sf::Color m_color_hovered;
	sf::Color m_color_text;
	sf::Color m_color_text_activated;
	sf::Color m_color_text_hovered;
	sf::Text m_text;

	bool m_hovered;
	bool m_activated;

	void updateTextPos();
};

