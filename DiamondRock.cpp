#include "DiamondRock.h"

// register to Factory
bool DiamondRock::m_registerit = Factory::registerit('#', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<DiamondRock>(pos); });

//=============================================================================
DiamondRock::DiamondRock(const sf::Vector2f & position):Rock(position)
{
	m_shape.setTexture(&Textures::instance()[DIAMOND_ROCK_TN]);
	m_shape.setSize(BoardSettings::getSmallSize());
}

//=============================================================================
int DiamondRock::getScore() const
{
	return 100 * int(m_shape.getSize().x);
}