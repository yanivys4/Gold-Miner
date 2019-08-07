#include "BoardObject.h"

//=============================================================================
BoardObject::BoardObject(const sf::Vector2f &position)
	:Object(position)
{
	m_outOfGame = false;
	m_IsGrabed = false;
	m_isExplode = false;
	m_explosionAnimation = Animation(&Textures::instance()[EXPLOSION_TN], 
									 AnimationSettings::getExplosionImageCount(), 
									 AnimationSettings::getExplosionTime());
}

//=============================================================================
bool BoardObject::isIntersect(const sf::FloatRect & rect)
{
	return m_shape.getGlobalBounds().intersects(rect);
}

//=============================================================================
void BoardObject::setOutOfGame()
{
	m_outOfGame = true;
}

//=============================================================================
bool BoardObject::isOutOfGame()
{
	return m_outOfGame;
}

//=============================================================================
void BoardObject::setPosition(const sf::Vector2f & pos)
{
	m_shape.setPosition(pos);
}

//=============================================================================
void BoardObject::setRotation(float angle)
{
	m_shape.setRotation(angle);
}

//=============================================================================
sf::Vector2f BoardObject::getObjectSize()
{
	return m_shape.getSize();
}

//=============================================================================
void BoardObject::activateGrabeMode()
{
	m_IsGrabed = true;
}

//=============================================================================
bool BoardObject::IsGrabed()
{
	return m_IsGrabed;
}

//=============================================================================
void BoardObject::activateExplodeMode()
{
	m_isExplode = true;
}

//=============================================================================
bool BoardObject::IsExplode()
{
	return m_isExplode;
}

//=============================================================================
void BoardObject::prepareForExplosion()
{
	m_shape.setSize(BoardSettings::getBigSize());
	m_shape.setTexture(&Textures::instance()[EXPLOSION_TN]);
}

//=============================================================================
bool BoardObject::explode(float deltaTime)
{
	if (!m_explosionAnimation.getOnceAnimation())
	{
		m_shape.setTextureRect(sf::IntRect(m_explosionAnimation.getUvRect(0, deltaTime)));
		return false;
	}

	m_outOfGame = true;

	return true; // object has exploded
}

//=============================================================================
void BoardObject::playExplosionSound()
{
	m_explosionSound.setBuffer(Sounds::instance()[EXPLOSION_SO]);
	m_explosionSound.play();
}

//=============================================================================
sf::FloatRect BoardObject::getGlobalBounds()
{
	return m_shape.getGlobalBounds();
}