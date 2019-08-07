//==================== includes =========================
#pragma once

#include <SFML/Graphics.hpp>
#include "ControllerSettings.h"
#include "HomeMenu.h"
#include "GameController.h"

class Controller
{
public:
	// public functions
	Controller();
	/*
	run the controller
	*/
	void run();

private:
	// private members
	sf::RenderWindow m_window;// holds the window
	HomeMenu m_homeMenu;// holds the home menu
	GameController m_gameController;// holds the game controller

	//private functions
	/*
	draw all elements to the window
	*/
	void draw();
	/*
	handle events
	*/
	void handleEvents();
	/*
	handle click eevent
	*/
	void clickHandle(const sf::Vector2f &point);
};


