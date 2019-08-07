#pragma once

#include "VisualObject.h"

class Clock :
	public VisualObject
{
public:
	// public functions
	Clock() {};
	/*
	Constructor: get the position of the Clock indicator
	*/
	Clock(const sf::Vector2f &position);
	/*
	set the time that shown on the clock
	*/
	void setTime(float time);
};

