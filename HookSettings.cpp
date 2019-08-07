#include "HookSettings.h"

sf::Vector2f HookSettings::m_hookBounds = { 80,-80 };
float HookSettings::m_rotateTime = 0.009f;
float HookSettings::m_grabTime = 0.0015f; 

//=============================================================================
sf::Vector2f HookSettings::getHookBounds()
{
	return m_hookBounds;
}

//=============================================================================
float HookSettings::getRotationTime()
{
	return m_rotateTime;
}

//=============================================================================
float HookSettings::getGrabTime()
{
	return m_grabTime;
}
//=============================================================================



