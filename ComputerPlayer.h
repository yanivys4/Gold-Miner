#pragma once

#include "Player.h"

const float UNUSED_ANGLE = 420.f;// to sign unused angle

class ComputerPlayer :
	public Player
{
public:
	// public functions
	ComputerPlayer() {};
	/*
	Constructor: get the position and name of the player
	*/
	ComputerPlayer(const sf::Vector2f & position, std::string name);
	/*
	operate the player, get the delta time, board and level number
	*/
	virtual void play(float deltaTime, Board & board, int lvl);
	/*
	change the texture of the player to mine texture
	*/
	virtual void changeToMineTexture();
	/*
	change the texture of the player to throw texture
	*/
	virtual void changeToThrowTexture();
	/*
	change the texture of the player to freeze texture
	*/
	virtual void changeToFreezeTexture();

private:
	// private members
	sf::RectangleShape m_fakeRope;// fake rope that help to find the best angle
	float m_bestAngle;// holds the best angle

	// private functions
	/*
	find the best angle for the player
	*/
	float findBestAngle(Board & board, int lvl);
};

