#include "Barrel.h"

// register to Factory
bool Barrel::m_registerit = Factory::registerit('B', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<Barrel>(pos); });

//=============================================================================
Barrel::Barrel(const sf::Vector2f &position) :BoardObject(position)
{
	m_shape.setTexture(&Textures::instance()[BARREL_TN]);
	m_shape.setSize(BoardSettings::getRegularSize());
}

//=============================================================================
int Barrel::getScore() const
{
	return -1;
}

//=============================================================================
void Barrel::prepareForExplosion()
{
	m_shape.setSize(BoardSettings::getBarrelExpSize());
	m_shape.setTexture(&Textures::instance()[EXPLOSION_TN]);
	sf::Vector2f newPos = m_shape.getPosition();
	newPos.x -= 40;
	newPos.y -= 40;
	m_shape.setPosition(newPos);
}

