#pragma once

#include "VisualObject.h"

class DynamiteIndicator :
	public VisualObject
{
public:
	// public functions
	DynamiteIndicator() {};
	/*
	Constructor: get the position of the dynamite indicator
	*/
	DynamiteIndicator(const sf::Vector2f &position);
	/*
	sets the num of dynamites
	*/
	void setNumOfDynamites(int numOfdynamites);
};

