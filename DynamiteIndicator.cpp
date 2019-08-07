#include "DynamiteIndicator.h"

//=============================================================================
DynamiteIndicator::DynamiteIndicator(const sf::Vector2f & position)
	: VisualObject(position)
{
	// init the shape
	m_shape.setTexture(&Textures::instance()[DYNAMITE_TN]);
	m_shape.setSize(VisualObjectSettings::getDynamiteSize());

	// init the text
	sf::Vector2f pos = { position.x + 10, position.y + 10 };
	m_text.setString("X0");
	m_text.setFillColor(sf::Color::Red);
	m_text.setPosition(pos);
}

//=============================================================================
void DynamiteIndicator::setNumOfDynamites(int numOfdynamites)
{
	m_text.setString("X" +std::to_string(numOfdynamites));
}


