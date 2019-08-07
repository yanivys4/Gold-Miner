#pragma once

#include <SFML/Graphics.hpp>
#include "AnimationSettings.h"
#include "BoardSettings.h"

class Animation
{
public:

	// public functions
	Animation() {};
	/*
	Constructor : gets a pointer to the texture the animation animate, 
	imageCount and switchTime that .
	*/
	Animation(sf::Texture * texture, sf::Vector2u imageCount, float switchTime);
	/*
	sets switch time depends on the size received.
	*/
	void setSwitchTime(const sf::Vector2f & size);
	/*
	restarts the switch time to the general time taken from AnimationSettings
	*/
	void restartSwitchTime();
	/*
	restart onceAnimation flag to false.
	*/
	void resetOnceAnimation();   
	/*
	returns the status of the flag onceAnimation
	*/
	bool getOnceAnimation()const;
	/*
	activates the animation using the private function update and returns
	the updated intRect.
	*/
	sf::IntRect & getUvRect(int row, float deltaTime);
	
private:
	// private members
	sf::IntRect m_uvRect; // the intRect that keep changing and "catch" one frame time.
	sf::Vector2u m_imageCount; //number of frames in the texture
	sf::Vector2u m_currentImage; // holds the coordinates of the frame that is currently shown inside the texture.
	float m_totalTime; // the total time decides when to move to the next frame.
	float m_switchTime;//decide the time of switch frames
	bool m_onceAnimation = false; // a flag indicates that the animation has show at least once the full texture (all frames)

	// private functions
	/*
	updates the uvRect to the next frame according to the delta time. the row decides which row it is in the texture.
	*/
	void update(int row, float deltaTime);
};

