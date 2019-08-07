#include "Rock.h"

//=============================================================================
Rock::Rock(const sf::Vector2f &position)
	:BoardObject(position)
{
}

//=============================================================================
void Rock::setRockSize(const sf::Vector2f & rockSize)
{
	m_shape.setSize(rockSize);
}

