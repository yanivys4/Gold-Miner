#include "HomeButton.h"

//=============================================================================
HomeButton::HomeButton(sf::Vector2f pos, sf::Vector2f size)
	:Button(pos, size)
{
	m_shape.setTexture(&Textures::instance()[HOME_BUTTON_TN]);
}

//=============================================================================
const std::type_info & HomeButton::click(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
		return typeid(HomeButton);
	return typeid(NULL);
}

