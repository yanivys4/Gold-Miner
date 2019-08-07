#include "ExitButton.h"

//=============================================================================
ExitButton::ExitButton(sf::Vector2f pos, sf::Vector2f size)
	:Button(pos, size)
{
	m_shape.setTexture(&Textures::instance()[EXIT_BUTTON_TN]);
}

//=============================================================================
const std::type_info &ExitButton::click(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
		return typeid(ExitButton);
	return typeid(NULL);
}

