#pragma once

#include "Rock.h"
#include "Factory.h"

class RegularRock :
	public Rock
{
public:
	// public functions
	/*
	Constructor: gets the position for the object
	*/
	RegularRock(const sf::Vector2f &position);
	/*
	returns the score of Regular rock.
	*/
	virtual int getScore()const;
	
private:
	// private members
	/*
	dummy variables using for register to Factory
	each one represents different size of Regular rock
	*/
	static bool m_registeritSmall;
	static bool m_registeritRegular;
	static bool m_registeritBig;
};

