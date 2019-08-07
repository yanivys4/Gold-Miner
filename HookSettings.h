#pragma once

#include <SFML/Graphics.hpp>

class HookSettings
{
public:
	// public functions
	HookSettings() = delete;
	void operator=(const HookSettings &) = delete;
	/*
	returns the hook's angle bounds 
	*/
	static sf::Vector2f getHookBounds();
	/*
	returns the time that elapse between the 
	rotations of the hook which regulate it's speed.
	*/
	static float getRotationTime();
	/*
	returns the time that elapse between the 
	grab of the hook which regulate it's speed.
	*/
	static float getGrabTime();
	
private:
	// private members
	static sf::Vector2f m_hookBounds; // hook's angle bounds
	static float m_rotateTime; // time used to regulate speed of rotation 
	static float m_grabTime; // time used to regulate speed of grab
};

