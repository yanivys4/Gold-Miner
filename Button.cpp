#include "Button.h"

//=============================================================================
Button::Button(sf::Vector2f pos, sf::Vector2f size)
{
	m_shape.setPosition(pos);
	m_shape.setSize(size);
}

//=============================================================================
void Button::draw(sf::RenderWindow & window)
{
	window.draw(m_shape);
}

//=============================================================================
void Button::hover(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
	{
		sf::Color c = sf::Color::White;
		c.a = 150;
		m_shape.setFillColor(c);
	}
	else
	{
		m_shape.setFillColor(sf::Color::White);
	}
}
