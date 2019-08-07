#include "BoardSettings.h"
#include "ControllerSettings.h"

sf::Vector2u BoardSettings::m_boardSize = { 25,50 };
sf::Vector2f BoardSettings::m_smallSize = { 20,20 };
sf::Vector2f BoardSettings::m_regularSize = { 40,40 };
sf::Vector2f BoardSettings::m_bigSize = { 80,80 };
sf::Vector2f BoardSettings::m_basePos = { 0, 200 };
sf::Vector2f BoardSettings::m_BarrelExpSize = { 150, 150 };
int BoardSettings::m_baseValue = 10;

//=============================================================================
sf::Vector2f BoardSettings::getSmallSize()
{
	return m_smallSize;
}

//=============================================================================
sf::Vector2f BoardSettings::getRegularSize()
{
	return m_regularSize;
}

//=============================================================================
sf::Vector2f BoardSettings::getBigSize()
{
	return m_bigSize;
}

//=============================================================================
sf::Vector2f BoardSettings::getBasePos()
{
	return m_basePos;
}

//=============================================================================
sf::Vector2u BoardSettings::getBoardSize()
{
	return m_boardSize;
}

//=============================================================================
sf::Vector2f BoardSettings::getBarrelExpSize()
{
	return m_BarrelExpSize;
}

//=============================================================================
int BoardSettings::getBaseValue()
{
	return m_baseValue;
}
//=============================================================================