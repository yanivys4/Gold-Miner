#pragma once

#include <SFML/Audio.hpp>
#include "Object.h"
#include "BoardSettings.h"
#include "Animation.h"
#include "Sounds.h"

class BoardObject :
	public Object
{
public:
	// public functions
	BoardObject() {};
	/*
	Constructor: get the position of the object
	*/
	BoardObject(const sf::Vector2f &position);
	/*
	check if the object is intersect with floatRect
	*/
	virtual bool isIntersect(const sf::FloatRect & rect);
	/*
	set the object to be out of game
	*/
	void setOutOfGame();
	/*
	checks if the object is out of game
	*/
	bool isOutOfGame();
	/*
	set the position of the object
	*/
	void setPosition(const sf::Vector2f & pos);
	/*
	set the rotation of the object
	*/
	void setRotation(float angle);
	/*
	return the object size
	*/
	sf::Vector2f getObjectSize();
	/*
	activate the object to grabe mode
	*/
	void activateGrabeMode();
	/*
	checks if the object is in grabe mode
	*/
	bool IsGrabed();
	/*
	activate the object to explode mode
	*/
	void activateExplodeMode();
	/*
	checks if the object is in explode mode
	*/
	bool IsExplode();
	/*
	prepare the object for explosion
	*/
	virtual void prepareForExplosion();
	/*
	explode th object
	*/
	bool explode(float deltaTime);
	/*
	play the sound of explosion
	*/
	void playExplosionSound();
	/*
	return FloatRect with the global bounds of the object
	*/
	sf::FloatRect getGlobalBounds();
	/*
	return the score of the object
	*/
	virtual int getScore()const = 0;

private:
	// private members
	bool m_outOfGame;// to know if the object is out of game
	bool m_IsGrabed;// to know if the object is in grabe mode
	bool m_isExplode;// to know if the object is in explode mode
	Animation m_explosionAnimation;// holds the explosion animation
	sf::Sound m_explosionSound;// holds the sound of the explosion
};

