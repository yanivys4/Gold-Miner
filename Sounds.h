#pragma once

#include <SFML/Audio.hpp>
#include <experimental/vector>
#include "SoundsSettings.h"

class Sounds
{
public:
	// public functions
	/*
	instance function of Singelton
	*/
	static Sounds & instance();
	/*
	operator [] to access the vector of sound buffers 
	with a given requested soundName enum
	*/
	sf::SoundBuffer & operator[](SoundsNames s);
	/*
	static function returns the background music of game
	*/
	static sf::Music & getbackgroundMusic();

private:
	//private members
	std::vector<sf::SoundBuffer> m_sounds; // vector of sound buffers
	static sf::Music m_backgroundMusic;

	// private functions
	Sounds(); // private c-tor of Singelton
	Sounds(const Sounds &) = default;
	Sounds & operator=(const Sounds &) = default;
};

