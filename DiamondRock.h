#pragma once

#include "Rock.h"
#include "Factory.h"

class DiamondRock :
	public Rock
{
public:
	// public functions
	/*
	Constructor: get the position of the Barrel
	*/
	DiamondRock(const sf::Vector2f &position);
	/*
	return the score of the Diamond
	*/
	virtual int getScore()const;
	
private:
	// private members
	static bool m_registerit;// dummy variable using for register to Factory
};

