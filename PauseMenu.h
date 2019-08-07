#pragma once

#include "Menu.h"
#include "HomeButton.h"
#include "ExitButton.h"
#include "ResumeButton.h"
#include "MuteButton.h"

class PauseMenu :
	public Menu
{
public:
	// public functions
	/*
	Constructor: get the size of the window
	*/
	PauseMenu(const sf::Vector2f &windowSize);
	/*
	draw all menues elements to the window
	*/
	virtual void draw(sf::RenderWindow &window);

private:
	// private members
	sf::RectangleShape m_image;// holds the image
};

