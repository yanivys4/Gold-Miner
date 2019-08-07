#include "VisualObject.h"

//=============================================================================
VisualObject::VisualObject(const sf::Vector2f & position)
	:Object(position)
{
	m_font.loadFromFile("Font.ttf");
	m_text = sf::Text("", m_font, 20);
}

//=============================================================================
void VisualObject::draw(sf::RenderWindow & window)
{
	Object::draw(window);
	m_text.setFont(m_font);
	window.draw(m_text);
}

//=============================================================================
VisualObject::~VisualObject() { ; }
