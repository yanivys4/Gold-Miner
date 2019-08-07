#pragma once

#include <SFML/Graphics.hpp>
#include<experimental/vector>
#include <memory>
#include <fstream>
#include "Factory.h"
#include "BoardObject.h"
#include "RegularRock.h"
#include "GoldenRock.h"
#include "Hook.h"

class Board
{
public:
	// public functions
	
	//Constructor
	Board();
	/*
	initialize the board using a level file 
	*/
	void initBoard(std::ifstream & levelFile);
	/*
	draws the board
	*/
	void draw(sf::RenderWindow & window);
	/*
	gets a floatRect and check collision with one of the Board objects
	*/
	BoardObject * checkCollision(const sf::FloatRect & rect);
	/*
	// return the score of collision obj for any rect shape
	*/
	int getCollisionScore(const sf::FloatRect &rect); 
	/*
	check collison with the exploded barrel and activates explosion to the collided 
	objects
	*/
	void barrelExplode(const sf::FloatRect &rect, float deltaTime);
	/*
	removes objects from board  that are in explode mode  
	*/
	void removeBarrelExp();
	/*
	removes the objects that should be 
	removed (exploded or grabbed by one of the players)
	*/
	void updateBoard();
	/*
	returns true if the board has no objects
	*/
	bool isEmpty()const;
	/*
	returns the number of objects on board
	*/
	size_t getNumberOfObjects()const;

private:
	// private members
	std::vector <std::unique_ptr<BoardObject>> m_board; // the vector of objects on board

	// private functions
	/*
	gets a ptr to BoardObject and the kind of it. checks if the BoardObject is a Rock
	and if it is set the size of rock according to the kind using the setSize of rock class.
	*/
	std::unique_ptr<BoardObject> setSizeOfRock(char kind, std::unique_ptr<BoardObject> ptr);
};

