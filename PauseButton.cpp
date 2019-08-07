#include "PauseButton.h"

//=============================================================================
PauseButton::PauseButton(sf::Vector2f pos, sf::Vector2f size)
	:Button(pos, size)
{
	m_shape.setTexture(&Textures::instance()[PAUSE_BUTTON_TN]);
}

//=============================================================================
const std::type_info & PauseButton::click(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
		return typeid(PauseButton);
	return typeid(NULL);
}

