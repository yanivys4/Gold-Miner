#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>
#include "ControllerSettings.h"
#include "Board.h"
#include "Player.h"
#include "ToolBar.h"
#include "PauseMenu.h"
#include "SinglePlayerBtn.h"
#include "Textures.h"
#include "ContinueButton.h"
#include "HumanPlayer.h"

class LevelController
{
public:
	// public functions
	/*
	Constructor: gets 2 players
	*/
	LevelController(Player & player1, Player & player2);
	/*
	init the level
	*/
	void initLevel(int requestedLevel); // this function responsible to init the level
	/*
	run the level
	*/
	const std::type_info & run(sf::RenderWindow & window);
	/*
	sets player 2
	*/
	void setPlayer2(Player & player2);

private:
	//private members
	int m_currentLevel;// the level that is playing +1 because of the enum order
	Board m_board;// holds the board
	ToolBar m_toolBar;//holds the tool bar
	PauseMenu m_pauseMenu;// holds the pause menu
	sf::RectangleShape m_background;// holds the background
	Player *m_player1;// pointer to first player
	Player *m_player2;// pointer to second player
	float m_deltaTime = 0.0f;// holds the delta time
	float m_levelTime;// holds the level time
	float m_timeElapsed = 0;// holds the time elapsed
	sf::Clock m_clock;// holds the clock

	//private functions
	/*
	handle the events in the level
	*/
	std::string handleEvents(sf::RenderWindow & window);
	/*
	draw the level to the window
	*/
	void draw(sf::RenderWindow & window);
	/*
	open the file of the level
	*/
	void openLevelFile(std::ifstream & file, std::string name);
	/*
	close the file of the level
	*/
	void closeLevelFile(std::ifstream & file);
	/*
	init the level time
	*/
	void initLevelTime(std::ifstream & file);
	/*
	handle the click event
	*/
	const std::type_info &clickHandle(sf::RenderWindow &window, const sf::Vector2f &point);
	/*
	handle the pause menu events
	*/
	const std::type_info &pauseMenuHandleEvent(sf::RenderWindow &window);
};

