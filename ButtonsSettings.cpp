#include "ButtonsSettings.h"

sf::Vector2f ButtonsSettings::m_startBtnSize = { 200.f, 200.f };//Initializing the size of start button
sf::Vector2f ButtonsSettings::m_regularBtnSize = { 70.f, 70.f };//Initializing the size of regular button

//=============================================================================
sf::Vector2f ButtonsSettings::getStartBtnSize()
{
	return m_startBtnSize;
}

//=============================================================================
sf::Vector2f ButtonsSettings::getRegularBtnSize()
{
	return m_regularBtnSize;
}