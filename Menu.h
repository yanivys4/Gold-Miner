#pragma once

#include <SFML/Graphics.hpp>
#include <experimental/vector>
#include "TexturesSettings.h"
#include "ButtonsSettings.h"
#include "Textures.h"
#include "Button.h"

class Menu
{
public:
	// public functions
	/*
	Constructor: get the size of the window
	*/
	Menu(const sf::Vector2f &windowSize);
	/*
	draw all menues elements to the window
	*/
	virtual void draw(sf::RenderWindow &window) = 0;
	/*
	activate the hover function of all buttons in the menu
	*/
	void hover(const sf::Vector2f &point);
	/*
	activate the click function of all buttons in the menu
	*/
	const std::type_info &click(const sf::Vector2f &point);

protected:
	// protected members
	sf::RectangleShape m_background;// holds the backgroung
	std::vector<std::unique_ptr<Button>> m_buttons;// holds the buttons
};

