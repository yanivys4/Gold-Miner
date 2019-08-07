#include "SinglePlayerBtn.h"

//=============================================================================
SinglePlayerBtn::SinglePlayerBtn(sf::Vector2f pos, sf::Vector2f size)
	:Button(pos, size)
{
	m_shape.setTexture(&Textures::instance()[SINGLE_PLAYER_TN]);
}

//=============================================================================
const std::type_info & SinglePlayerBtn::click(const sf::Vector2f & point)
{
	if (m_shape.getGlobalBounds().contains(point))
		return typeid(SinglePlayerBtn);
	return typeid(NULL);
}


