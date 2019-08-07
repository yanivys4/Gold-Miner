#pragma once

#include "BoardObject.h"
#include "Factory.h"

class Barrel :
	public BoardObject
{
public:
	// public functions
	/*
	Constructor: get the position of the Barrel
	*/
	Barrel(const sf::Vector2f &position);
	/*
	return the score of the Barrel
	*/
	virtual int getScore()const;
	/*
	prepare the barrel for explosion
	*/
	virtual void prepareForExplosion();

private:
	// private members
	static bool m_registerit;// dummy variable using for register to Factory
};

