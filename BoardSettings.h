#pragma once

#include <SFML/Graphics.hpp>

const enum feature{EXTRA_DYNAMITE_F, FREEZE_F, EXTRA_COINS};

class BoardSettings
{
public:
	// public functions
	BoardSettings() = delete;
	void operator=(const BoardSettings &) = delete;
	/*
	returns the size of small object.
	*/
	static sf::Vector2f getSmallSize();
	/*
	returns the size of regular object.
	*/
	static sf::Vector2f getRegularSize();
	/*
	returns the size of big object.
	*/
	static sf::Vector2f getBigSize();
	/*
	returns the base position which is the upper left 
	position of the board.
	*/
	static sf::Vector2f getBasePos();
	/*
	returns the dimensions of board MxN 
	*/
	static sf::Vector2u getBoardSize();
	/*
	returns the size of the explosion of barrel
	*/
	static sf::Vector2f getBarrelExpSize();
	/*
	returns the base value of a Boardobject
	*/
	static int getBaseValue();

private:
	// private members
	static sf::Vector2u m_boardSize; //the dimensions of the board
	static sf::Vector2f m_smallSize; // size of small object
	static sf::Vector2f m_regularSize; // size of regular object
	static sf::Vector2f m_bigSize; // size of big object
	static sf::Vector2f m_basePos; // upper left position of the board.
	static sf::Vector2f m_BarrelExpSize; // size of the explosion of barrel
	static int m_baseValue; // base value of boardObject
};

