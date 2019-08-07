#pragma once

#include <SFML/Graphics.hpp>

class ControllerSettings
{
public:
	// public functions
	ControllerSettings() = delete;
	void operator=(const ControllerSettings &) = delete;
	/*
	returns the window size
	*/
	static sf::Vector2f getWindowSize();
	/*
	returns the window title
	*/
	static std::string getWindowTitle();

private:
	// private members
	static sf::Vector2f m_windowSize;// holds the window size
	static std::string m_windowTitle;// holds the window title
};

