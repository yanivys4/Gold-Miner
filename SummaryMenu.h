#pragma once

#include "Menu.h"
#include "ContinueButton.h"
#include "Levels.h"

class SummaryMenu :
	public Menu
{
public:
	// public functions
	/*
	Constructor: get the size of the window
	*/
	SummaryMenu(const sf::Vector2f &windowSize);
	/*
	draw all menues elements to the window
	*/
	virtual void draw(sf::RenderWindow &window) {};
	/*
	override the draw function.
	gets the level number, scores of the players and the names of the players*/
	void draw(sf::RenderWindow &window, int ln, int player2Score, int player1Score, std::string name2, std::string name1);

private:
	// private members
	sf::Font m_font;// holds the font
	sf::Text m_levelIndicator;// holds the level indicator
	sf::Text m_player2Score;// holds the player2 score
	sf::Text m_player1Score;// holds the player1 score
	sf::Text m_freeText;// holds the free text

	//private functions
	/*
	returns the free text according to the scores of the players
	*/
	sf::String getFreeText(int compScore, int playerScore, std::string name2, std::string name1);
};

