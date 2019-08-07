#pragma once

#include "Menu.h"
#include "HomeButton.h"
#include "ExitButton.h"
#include "TexturesSettings.h"

class GameOverMenu :
	public Menu
{
public:
	// public functions
	/*
	Constructor: get the size of the window
	*/
	GameOverMenu(const sf::Vector2f &windowSize);
	/*
	draw all menues elements to the window
	*/
	virtual void draw(sf::RenderWindow &window);
	/*
	sets the winner according to the name that was given
	*/
	void setWinner(std::string winner);

private:
	// private members
	sf::RectangleShape m_image;// holds the image
	sf::Font m_font;// holsd the font
	sf::Text m_winner;// holds the winner name
};

