#pragma once

#include <map>
#include <vector>
#include "BoardObject.h"

class Factory
{
public:
	// public functions

	using Pfn = std::unique_ptr<BoardObject>(*)(const sf::Vector2f & ); // define pointer to function used by factory
	/*
	This function gets char represents a type of BoardObject and a position to create it and calls the right c-tor 
	from the map.
	*/
	static std::unique_ptr<BoardObject> create(char name, const sf::Vector2f & position);
	/*
	This function responssible of register new BoardObject presentetion to the map as a pair (char, pointer to ctor)
	*/
	static bool registerit(char name, Pfn f);
private:
	// private members
	/*
	init the m_map before the usage of all BoardObject derived classes
	*/
	static auto & getMap()
	{
		/*
		the map holds pairs of char key and a pointer to
		function that construct an object that derives from BoardObject
		*/
		static std::map<char, Pfn> m_map; 
		return m_map;
	}
};

