#pragma once

#include <SFML/Graphics.hpp>
#include "ControllerSettings.h"

class ButtonsSettings
{
public:
	// public functions
	ButtonsSettings() = delete;
	void operator=(const ButtonsSettings &) = delete;
	/*
	returns the size of start button
	*/
	static sf::Vector2f getStartBtnSize();
	/*
	returns the size of regular button
	*/
	static sf::Vector2f getRegularBtnSize();

private:
	// private members
	static sf::Vector2f m_startBtnSize;// holds the size of start button
	static sf::Vector2f m_regularBtnSize;// holds the size of regular button
};

