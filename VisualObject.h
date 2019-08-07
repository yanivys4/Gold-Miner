#pragma once

#include "Object.h"
#include "VisualObjectSettings.h"

class VisualObject :
	public Object
{
public:
	// publlic functions
	VisualObject() {};
	/*
	Constructor: get the position of the object
	*/
	VisualObject(const sf::Vector2f &position);
	/*
	draw the object to the window
	*/
	virtual void draw(sf::RenderWindow &window);
	virtual ~VisualObject() = 0;
	
protected:
	// protected members
	sf::Font m_font;// holds the font of the text
	sf::Text m_text;// holds the text of the object
};

