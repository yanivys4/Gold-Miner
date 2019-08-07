#pragma once

#include <SFML/Graphics.hpp>

class VisualObjectSettings
{
public:
	// public functions
	VisualObjectSettings() = delete;
	void operator=(const VisualObjectSettings &) = delete;
	/*
	returns the size of level indicator
	*/
	static sf::Vector2f getLevelIndicatorSize();
	/*
	returns the size of clock indicator
	*/
	static sf::Vector2f getClockSize();
	/*
	returns the size of dynamite indicator
	*/
	static sf::Vector2f getDynamiteSize();
	/*
	returns the size of coin indicator
	*/
	static sf::Vector2f getCoinSize();

private:
	// private members
	static sf::Vector2f m_levelIndicatorSize; // size of level indicator
	static sf::Vector2f m_dynamiteSize;// size of dynamite indicator
	static sf::Vector2f m_clockSize;// size of clock indicator
	static sf::Vector2f m_coinSize;// size of coin indicator
};

