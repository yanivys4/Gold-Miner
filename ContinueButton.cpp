#include "ContinueButton.h"

//=============================================================================
ContinueButton::ContinueButton(sf::Vector2f pos, sf::Vector2f size)
	:Button(pos, size)
{
	m_shape.setTexture(&Textures::instance()[CONTINUE_BUTTON_TN]);
}

//=============================================================================
const std::type_info & ContinueButton::click(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
		return typeid(ContinueButton);
	return typeid(NULL);
}


