#pragma once

#include "Object.h"
class Dynamite :
	public Object
{
public:
	//public functions

	Dynamite() {};
	/*
	Constructor : gets the position and the switchTime for the throw speed 
	of the dynamite
	*/
	Dynamite(const sf::Vector2f &position, float switchTime);\
	/*
	draw function ovverided. draw only if in visible mode
	*/
	virtual void draw(sf::RenderWindow & window)override;
	/*
	activates the throw of the dynamite towards the given target
	*/
	bool sendDynamite(const sf::Vector2f & targetPos, float deltaTime);
	/*
	makes the dynamite vissible
	*/
	void makeDynamiteVissible(bool status);
	/*
	changes the rotation of the dynamite
	*/
	void setRotation(float angle);
private:

	//private members
	bool m_visible = false; 
	sf::Vector2f m_basePos;// The base position of the dynamite in the start of each throw
	float m_totalTime = 0.0f; // holds the total time elapsed and used to regulate the throw speed
	float m_switchTime; // holds the right time to advance the dynamite towards the target

	//private functions
	sf::Vector2f getEndOfDynamite(); // used to get the edge of the dynamite and by it to advance it

};

