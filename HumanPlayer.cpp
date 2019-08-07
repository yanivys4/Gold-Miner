#include "HumanPlayer.h"

//=============================================================================
HumanPlayer::HumanPlayer(const sf::Vector2f & position, std::string name)
	:Player(position, name)
{
	m_shape.setTexture(&Textures::instance()[PLAYER_MINING_TN]);
	m_mineAnimation = Animation(&Textures::instance()[PLAYER_MINING_TN],
								AnimationSettings::getMineImageCount(),
								AnimationSettings::getSwitchTime());
	m_dynamiteAnimation = Animation(&Textures::instance()[PLAYER_THROW_TN],
									AnimationSettings::getDynamiteImageCount(),
									AnimationSettings::getThrowTime());
	
}

//=============================================================================
void HumanPlayer::play(float deltaTime, Board & board, int lvl)
{
	if (m_isFrozen)
	{
		m_freezeTime += m_freezeClock.getElapsedTime().asSeconds();
		if (m_freezeTime >= 2000.0f)
		{
			m_isFrozen = false;
			m_freezeTime = 0.0f;
			changeToMineTexture();
		}
	}
	else
	{
		if (!m_hook.isSent())
			m_hook.rotate(deltaTime);
		else
			sendHook(deltaTime, board);
	}
}

//=============================================================================
void HumanPlayer::changeToMineTexture()
{
	m_shape.setTexture(&Textures::instance()[PLAYER_MINING_TN]);
}

//=============================================================================
void HumanPlayer::changeToThrowTexture()
{
	m_shape.setTexture(&Textures::instance()[PLAYER_THROW_TN]);
}

//=============================================================================
void HumanPlayer::changeToFreezeTexture()
{
	m_shape.setTexture(&Textures::instance()[FROZEN_PLAYER_TN]);
}
//=============================================================================