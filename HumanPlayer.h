#pragma once

#include "Player.h"

class HumanPlayer :
	public Player
{
public:
	// public functions
	HumanPlayer() {};
	/*
	Constructor: gets the position of the player and it's name
	*/
	HumanPlayer(const sf::Vector2f & position, std::string name);
	/*
	play function gets delta time,
	board of play and the number of level.
	*/
	virtual void play(float deltaTime, Board & board, int lvl);
	/*
	changes the texture of Humanplayer to mine texture
	*/
	virtual void changeToMineTexture() ;
	/*
	changes the texture of humanplayer to throw dynamite texture
	*/
	virtual void changeToThrowTexture();
	/*
	changes the texture of humanplayer to freeze texture
	*/
	virtual void changeToFreezeTexture();
};

