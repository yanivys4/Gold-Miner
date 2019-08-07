#pragma once

#include<SFML/Graphics.hpp>
#include <experimental/vector>
#include <memory>
#include "TexturesSettings.h"
#include "Textures.h"

class Object
{
public:
	// public functions
	Object() {};
	/*
	Constructor: get the position of the Barrel
	*/
	Object(const sf::Vector2f &position);
	virtual ~Object() = 0;
	/*
	draw the object to the window
	*/
	virtual void draw(sf::RenderWindow & window);
	/*
	returns the position of the object
	*/
	virtual sf::Vector2f getPosition();
	
protected:
	// protected members
	sf::RectangleShape m_shape;// holds the shape of the object
};

