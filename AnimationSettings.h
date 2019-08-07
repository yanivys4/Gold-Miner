#pragma once

#include <SFML/Graphics.hpp>

class AnimationSettings
{
public:
	// public functions
	AnimationSettings() = delete;
	void operator =(const AnimationSettings &) = delete;
	/*
	returns the basic switch time of frames.
	*/
	static float getSwitchTime();
	/*
	returns the throw animation switch time of frames.
	*/
	static float getThrowTime();
	/*
	returns the explosion animation switch time of frames
	*/
	static float getExplosionTime();
	/*
	returns the coordinates of mine animation texture.
	*/
	static sf::Vector2u getMineImageCount();
	/*
	returns the coordinates of throwDynamite animation texture.
	*/
	static sf::Vector2u getDynamiteImageCount();
	/*
	returns the coordinates of explosion animation texture.
	*/
	static sf::Vector2u getExplosionImageCount();

private:
	// private members
	static float m_switchTime; // the basic switch time of frames
	static float m_throwTime; // the switch time of throw dynamite animation
	static float m_explosionTime;// the switch time of explosion animation
	static sf::Vector2u m_mineImageCount; // coordinates of mine animation texture
	static sf::Vector2u m_dynamiteImageCount; // coordinates of throwDynamite animation texture
	static sf::Vector2u m_explosionImageCount; // coordinates of explosion animation texture
	
};

