#include "PlayerSettings.h"

sf::Vector2f PlayerSettings::m_playerSize = { 80,120 };
sf::Vector2f PlayerSettings::m_player1Pos = { 600,50 };
sf::Vector2f PlayerSettings::m_player2Pos = { 300,50 };

//=============================================================================
sf::Vector2f PlayerSettings::getPlayer1Pos()
{
	return m_player1Pos;
}

//=============================================================================
sf::Vector2f PlayerSettings::getPlayer2Pos()
{
	return m_player2Pos;
}

//=============================================================================
sf::Vector2f PlayerSettings::getPlayerSize()
{
	return m_playerSize;
}
//=============================================================================


