#pragma once
#include <SFML/Graphics.hpp>

class PlayerSettings
{
public:
	// public functions
	PlayerSettings() = delete;
	void operator=(const PlayerSettings &) = delete;
	/*
	returns the position of player1
	*/
	static sf::Vector2f getPlayer1Pos();
	/*
	returns the position of player2
	*/
	static sf::Vector2f getPlayer2Pos();
	/*
	returns the size of a player 
	*/
	static sf::Vector2f getPlayerSize();

private:
	// private members
	static sf::Vector2f m_playerSize; // size of player
	static sf::Vector2f m_player1Pos; //player1 position
	static sf::Vector2f m_player2Pos; //player2 position
};

