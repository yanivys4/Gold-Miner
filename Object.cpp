#include "Object.h"

//=============================================================================
Object::Object(const sf::Vector2f & position)
{
	m_shape.setPosition(position);
}

//=============================================================================
void Object::draw( sf::RenderWindow & window)
{
	window.draw(m_shape);
}

//=============================================================================
sf::Vector2f Object::getPosition()
{
	return m_shape.getPosition();
}

//=============================================================================
Object::~Object() { ; }