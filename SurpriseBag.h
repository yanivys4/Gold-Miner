#pragma once

#include "BoardObject.h"
#include "Factory.h"

class SurpriseBag :
	public BoardObject
{
public:
	// public functions
	/*
	Constructor: gets the position of object
	*/
	SurpriseBag(const sf::Vector2f &position);
	/*
	returns the score of the surprise bag.
	the reason it is exist is for the use of the computer algorithm.
	*/
	virtual int getScore()const;
	/*
	returns the feature the surprise bag holds in
	*/
	feature getFeature();

private:
	// private members
	static bool m_registerit; // dummy variable using for register to Factory
	feature m_feature; // the feature the surprise bag holds

	// private functions
	/*
	this function choose the kind of feature the surprise bag will hold randomally.
	*/
	void chooseKind(); 
};

