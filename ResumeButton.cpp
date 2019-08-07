#include "ResumeButton.h"

//=============================================================================
ResumeButton::ResumeButton(sf::Vector2f pos, sf::Vector2f size)
	:Button(pos, size)
{
	m_shape.setTexture(&Textures::instance()[RESUME_BUTTON_TN]);
}

//=============================================================================
const std::type_info & ResumeButton::click(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
		return typeid(ResumeButton);
	return typeid(NULL);
}

