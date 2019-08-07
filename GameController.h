#pragma once

//==================== includes =========================
#include "LevelController.h"
#include "PlayerSettings.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "PauseMenu.h"
#include "GameOverMenu.h"
#include "SummaryMenu.h"

class GameController
{
public:
	// public functions
	/*
	Constructor: gets the window size
	*/
	GameController(const sf::Vector2f &windowSize);
	/*
	play the game
	mode: true = single player, false = multi player
	return false for close the program
	*/
	bool playGame(sf::RenderWindow & window, bool mode);

private:
	//private members
	GameOverMenu m_gameOverMenu;// holds the game over menu
	SummaryMenu m_summaryMenu;// holds the summary menu
	HumanPlayer m_player1;// holds player1
	HumanPlayer m_player2;// holds player2
	ComputerPlayer m_computerPlayer;// holds computer player
	LevelController m_levelController;// holds level controller
	bool m_IsLevelRun;// level run indicator

	// private functions
	/*
	handle the summary menu events
	*/
	const std::type_info &handleSummaryEvents(sf::RenderWindow &window, int ln);
	/*
	handle the summary click event
	*/
	const std::type_info &summaryClickHandle(const sf::Vector2f point, sf::RenderWindow &window, int ln);
	/*
	show the game over menu on the screen
	*/
	void showGameOverMenu(sf::RenderWindow &window, bool mode);
	//handle the game over menu events 
	bool handleGameOverEvents(sf::RenderWindow &window);
	// reset the players
	void resetPlayers();
};

