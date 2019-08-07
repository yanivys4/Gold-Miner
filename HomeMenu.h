#pragma once

#include "Menu.h"
#include "SinglePlayerBtn.h"
#include "MultiPlayerBtn.h"
#include "ExitButton.h"
#include "MuteButton.h"

class HomeMenu :
	public Menu
{
public:
	// public functions
	/*
	Constructor: get the size of the window
	*/
	HomeMenu(const sf::Vector2f &windowSize);
	/*
	draw all menues elements to the window
	*/
	virtual void draw(sf::RenderWindow &window);
};

