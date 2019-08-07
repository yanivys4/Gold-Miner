#include "GoldenRock.h"

bool GoldenRock::m_registeritSmall = Factory::registerit('4', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<GoldenRock>(pos); });
bool GoldenRock::m_registeritRegular = Factory::registerit('5', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<GoldenRock>(pos); });
bool GoldenRock::m_registeritBig = Factory::registerit('6', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<GoldenRock>(pos); });

//=============================================================================
GoldenRock::GoldenRock(const sf::Vector2f & position):Rock(position)
{
	
	m_shape.setTexture(&Textures::instance()[GOLDEN_ROCK_TN]);
	
}

//=============================================================================
int GoldenRock::getScore() const
{
	return 8 *  int(m_shape.getSize().x);
}
//=============================================================================



