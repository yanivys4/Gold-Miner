#pragma once

#include "VisualObject.h"

class Score :
	public VisualObject
{
public:
	// public functions
	Score() {};
	/*
	Constructor: get the position of the score
	*/
	Score(const sf::Vector2f &position);
	/*
	sets the score
	*/
	void setScore(int score);
};

