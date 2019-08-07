#include "MuteButton.h"

//=============================================================================
MuteButton::MuteButton(sf::Vector2f pos, sf::Vector2f size)
	:Button(pos, size)
{
	m_shape.setTexture(&Textures::instance()[MUTE_BUTTON_TN]);
	m_valid = true;
}

//=============================================================================
const std::type_info &MuteButton::click(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
	{
		if (m_valid)
		{
			// change to unmute texture
			m_shape.setTexture(&Textures::instance()[UNMUTE_BUTTON_TN]);
			m_valid = false;
		}
		else
		{
			// change to mute texture
			m_shape.setTexture(&Textures::instance()[MUTE_BUTTON_TN]);
			m_valid = true;
		}

		return typeid(MuteButton);
	}

	return typeid(NULL);
}