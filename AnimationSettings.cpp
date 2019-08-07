#include "AnimationSettings.h"

float AnimationSettings::m_switchTime = 0.08f;
float AnimationSettings::m_throwTime = 0.08f;
float AnimationSettings::m_explosionTime = 0.06f;
sf::Vector2u AnimationSettings::m_mineImageCount = { 7,1 }; 
sf::Vector2u AnimationSettings::m_dynamiteImageCount = { 10,1 }; 
sf::Vector2u AnimationSettings::m_explosionImageCount = { 14,1 };

//=============================================================================
float AnimationSettings::getSwitchTime()
{
	return m_switchTime;
}

//=============================================================================
float AnimationSettings::getThrowTime()
{
	return m_throwTime;
}

//=============================================================================
float AnimationSettings::getExplosionTime()
{
	return m_explosionTime;
}

//=============================================================================
sf::Vector2u AnimationSettings::getMineImageCount()
{
	return m_mineImageCount;
}

//=============================================================================
sf::Vector2u AnimationSettings::getDynamiteImageCount()
{
	return m_dynamiteImageCount;
}

//=============================================================================
sf::Vector2u AnimationSettings::getExplosionImageCount()
{
	return m_explosionImageCount;
}

//=============================================================================

