#include "RegularRock.h"


bool RegularRock::m_registeritSmall = Factory::registerit('1', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<RegularRock>(pos); });
bool RegularRock::m_registeritRegular = Factory::registerit('2', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<RegularRock>(pos); });
bool RegularRock::m_registeritBig = Factory::registerit('3', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<RegularRock>(pos); });

//=============================================================================
RegularRock::RegularRock(const sf::Vector2f &position) :Rock(position)
{
	m_shape.setTexture(&Textures::instance()[REGULAR_ROCK_TN]);

	// during init of rocks it is needed to set size outside the c-tor
}

//=============================================================================
int RegularRock::getScore() const
{
	return int(m_shape.getSize().x);
}
//=============================================================================