#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Object.h"
#include "PlayerSettings.h"
#include "Hook.h"
#include "Textures.h"
#include "Animation.h"
#include "Board.h"
#include "SurpriseBag.h"
#include "Barrel.h"
#include "Sounds.h"
#include "Dynamite.h"

class Player
	:public Object
{
public:
	// public functions
	Player() {};
	/*
	Constructor: gets the position of the player and it's name
	*/
	Player(const sf::Vector2f & position, std::string name);
	/*
	draws the player
	*/
	void draw(sf::RenderWindow & window);
	/*
	activates the mine animation
	*/
	void mine(float deltaTime);
	/*
	activates the throw dynamite animation
	*/
	void throwDynamite(float deltaTime);
	/*
	pure virtual function of play gets delta time,
	board of play and the number of level.
	*/
	virtual void play(float deltaTime, Board & board, int lvl ) = 0;
	/*
	activates the setSent function of hook
	*/
	virtual void updateIsSent();
	/*
	try to throw dynamite and success only if the terms allow
	*/
	virtual void dynamiteTry();
	/*
	send hook to mine.
	*/
	void sendHook(float deltaTime, Board & board);
	/*
	returns the score of the player
	*/
	int getScore()const;
	/*
	returns the number of dynamites the player has
	*/
	int getNumOfDynamites()const;
	/*
	returns the name of the player
	*/
	std::string getName()const;
	/*
	resets the hook attributes using the reset function of hook
	*/
	void resetHook(const sf::Vector2f &position);
	/*
	activate reward sound
	*/
	void playRewardSound();
	/*
	changes the texture of player to freeze texture
	*/
	virtual void changeToFreezeTexture() = 0;
	/*
	changes the texture of player to mine texture
	*/
	virtual void changeToMineTexture() = 0;
	/*
	changes the texture of player to throw dynamite texture
	*/
	virtual void changeToThrowTexture() = 0;
	/*
	returns the flag is throwing dynamite
	*/
	bool isThrowingDynamite()const;
	
	
protected:
	// protected members
	Animation m_mineAnimation; // mine animation
	Animation m_dynamiteAnimation; // throw dynamite animation
	bool m_isThrowingDynamite = true; // throwing dynamite flag
	bool m_isFrozen = false; // frozen flag
	float m_freezeTime = 0.0f; // time used to indicate if the time elapsed in freeze is over
	sf::Clock m_freezeClock; // freeze clock 
	Hook m_hook; // the player's hook
	sf::Sound m_rewardSound; // reward sound
	Dynamite m_dynamite; // dynamite tool throwd whenever the player throws a dynamite

private:
	// private members
	bool m_isBarrelTime; // barrel explosion time flag
	int m_score = 0; // player's score
	int m_numOfDynamites = 0; // number of dynamites the player has
	sf::Font m_font; // font of player's name
	sf::Text m_name; // text of players's name

	// private functions
	/*
	function being called only if the hook is back to
	player and the hook is attached with an object
	*/
	void getReward(); 
	/*
	get a feauture of a surprise bag
	*/
	void getFeature(feature f);
};

