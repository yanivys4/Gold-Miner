#pragma once

#include <SFML/Graphics.hpp>
#include "Textures.h"
#include "TexturesSettings.h"

class Button
{
public:
	// public functions
	/*
	Constructor: get the position and size of the button.
	default position is {0,0), default size is {10,10}
	*/
	Button(sf::Vector2f pos = { 0.f, 0.f }, sf::Vector2f size = { 10.f, 10.f });
	/*
	draw the button on the window
	*/
	void draw(sf::RenderWindow &window);
	/*
	change the texture of the button if the point that was given is on the button
	*/
	void hover(const sf::Vector2f &point);
	/*
	check if the point that was given is on the button.
	every button return his type if yes or type of null if not
	*/
	virtual const std::type_info &click(const sf::Vector2f &point) = 0;

protected:
	// protected members
	sf::RectangleShape m_shape;// holds the shape of the button
};

