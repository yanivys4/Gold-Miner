#pragma once

#include "Button.h"

class PauseButton : 
	public Button
{
public:
	// public functions
	/*
	Constructor: get the position and size of the button.
	default position is {0,0), default size is {10,10}
	*/
	PauseButton(sf::Vector2f pos = { 0.f, 0.f }, sf::Vector2f size = { 10.f, 10.f });
	/*
	check if the point that was given is on the button.
	the button return his type if yes or type of null if not
	*/
	virtual const std::type_info &click(const sf::Vector2f &point);
};

