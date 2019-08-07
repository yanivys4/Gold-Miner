#pragma once

#include "PauseButton.h"
#include "Clock.h"
#include "DynamiteIndicator.h"
#include "LevelIndicator.h"
#include "ButtonsSettings.h"
#include <SFML/Graphics.hpp>
#include "VisualObjectSettings.h"
#include "PlayerSettings.h"
#include "Score.h"

class ToolBar
{
public:
	// public functions
	/*
	Constructor: gets the window size
	*/
	ToolBar(sf::Vector2f windowSize);
	/*
	draw all elements to the window
	*/
	void draw(sf::RenderWindow &window);
	/*
	activate the hover function of the pause button
	*/
	void hover(const sf::Vector2f &point);
	/*
	activate the click function of the pause button
	*/
	const std::type_info &click(const sf::Vector2f &point);
	/*
	init the tool bar
	*/
	void initToolBar(int lvl);
	/*
	update all elements of the tool bar
	*/
	void updateToolbar(float time, int Player1Score, int player2Score, int numOfPlayer1Dynamites, int numOfPlayer2Dynamites);
	
private:
	// private members
	PauseButton m_pauseButton;// holds the pause button
	LevelIndicator m_levelIndicator;// holds the level indicator
	Clock m_clock;// holds the clock indicator
	DynamiteIndicator m_player2Dynamite;// holds the player2 dynamite indicator
	DynamiteIndicator m_player1Dynamite;// holds the player1 dynamite indicator
	Score m_player2Score;// holds the player2 score indicator
	Score m_player1Score;// holds the player1 score indicator
};

