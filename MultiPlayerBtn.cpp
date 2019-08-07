#include "MultiPlayerBtn.h"

//=============================================================================
MultiPlayerBtn::MultiPlayerBtn(sf::Vector2f pos, sf::Vector2f size)
	:Button(pos, size)
{
	m_shape.setTexture(&Textures::instance()[MULTI_PLAYER_TN]);
}

//=============================================================================
const std::type_info & MultiPlayerBtn::click(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
		return typeid(MultiPlayerBtn);
	return typeid(NULL);
}