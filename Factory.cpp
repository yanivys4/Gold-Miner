#include "Factory.h"

//=============================================================================
std::unique_ptr<BoardObject> Factory::create(char name, const sf::Vector2f & position) 
{
	auto it = Factory::getMap().find(name); // get an iterator in the place of the certain key 
	if (it == Factory::getMap().end()) // if the key does not exist(reached to end) return nullptr
		return nullptr;
	return it->second(position); // returns the product of the constructor - unique_ptr with the constructed object
}

//=============================================================================
bool Factory::registerit(char name, Pfn f)
{
	Factory::getMap().emplace(name, f); // emplace the Pfn to the map with the key name
	return true;
}

דביר יא זין מעופף
