#pragma once

#include "VisualObject.h"
#include "Levels.h"

class LevelIndicator :
	public VisualObject
{
public:
	// public functions
	LevelIndicator() {};
	/*
	Constructor: get the position of the level indicator
	*/
	LevelIndicator(const sf::Vector2f &position);
	/*
	sets the level
	*/
	void setLevel(int lvl);
};

