#include "VisualObjectSettings.h"

sf::Vector2f VisualObjectSettings::m_levelIndicatorSize = { 150, 40 };
sf::Vector2f VisualObjectSettings::m_clockSize = { 100, 40 };
sf::Vector2f VisualObjectSettings::m_dynamiteSize = { 10, 40 };
sf::Vector2f VisualObjectSettings::m_coinSize = { 30, 30 };

//=============================================================================
sf::Vector2f VisualObjectSettings::getLevelIndicatorSize()
{
	return m_levelIndicatorSize;
}

//=============================================================================
sf::Vector2f VisualObjectSettings::getClockSize()
{
	return m_clockSize;
}

//=============================================================================
sf::Vector2f VisualObjectSettings::getDynamiteSize()
{
	return m_dynamiteSize;
}

//=============================================================================
sf::Vector2f VisualObjectSettings::getCoinSize()
{
	return m_coinSize;
}
//=============================================================================