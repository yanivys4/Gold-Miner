#pragma once

#include "BoardObject.h"

class Rock :
	public BoardObject
{
public:
	// public functions
	/*
	Constructor: gets the position for the object
	*/
	Rock(const sf::Vector2f &position);
	/*
	sets the size of the rock. small regular or big.
	*/
	virtual void setRockSize(const sf::Vector2f & rockSize);
	/*
	returns the score received according to the rock value.
	*/
	virtual int getScore()const = 0;
};

