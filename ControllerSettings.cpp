#include "ControllerSettings.h"

sf::Vector2f ControllerSettings::m_windowSize = { 1000.f, 700.f };//Initializing the size of the window
std::string ControllerSettings::m_windowTitle = "Gold Miner";//Initializing the title of the window

//=============================================================================
sf::Vector2f ControllerSettings::getWindowSize()
{
	return m_windowSize;
}

//=============================================================================
std::string ControllerSettings::getWindowTitle()
{
	return m_windowTitle;
}
