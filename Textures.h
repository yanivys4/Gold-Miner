#pragma once

#include <SFML/Graphics.hpp>
#include <experimental/vector>
#include "TexturesSettings.h"

class Textures 
{
public:
	// public functions
	/*
	instance function of Singelton
	*/
	static Textures& instance();
	/*
	operator [] to access the vector of textures
	with a given requested texturesNames enum
	*/
	sf::Texture& operator[](texturesNames t);

private:
	// private members
	std::vector<sf::Texture> m_textures;

	// private functions
	Textures();// private c-tor of Singelton
	Textures(const Textures &) = default;
	Textures & operator=(const Textures &) = default;
};

