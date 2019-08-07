#include "Dynamite.h"
#include "VisualObjectSettings.h"
#include <iostream>

//=============================================================================
Dynamite::Dynamite(const sf::Vector2f &position, float switchTime):Object(position), m_basePos(position),m_switchTime(switchTime)
{
	m_shape.setPosition(position);
	m_shape.setTexture(&Textures::instance()[DYNAMITE_TN]);
	m_shape.setSize(VisualObjectSettings::getDynamiteSize());
}

//=============================================================================
void Dynamite::draw(sf::RenderWindow & window)
{
	if (m_visible)
		Object::draw(window);//!!!!!!!!!!!!!!!!!!!!!!!!!!!
}

//=============================================================================
bool Dynamite::sendDynamite(const sf::Vector2f & targetPos, float deltaTime)
{
	m_totalTime += deltaTime;
	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		if (m_shape.getPosition().y - targetPos.y >= 10)
		{
			m_visible = false;
			m_shape.setPosition(m_basePos);
			return false; // the dynamite has reached the target
		}
		else
		{
			sf::Vector2f newPos = getEndOfDynamite();
			m_shape.setPosition(newPos);
		}

		return true;
	}

	return true;
}

//=============================================================================
void Dynamite::makeDynamiteVissible(bool status)
{
	m_visible = status;
}

//=============================================================================
void Dynamite::setRotation(float angle)
{
	m_shape.setRotation(angle);
}

//=============================================================================
sf::Vector2f Dynamite::getEndOfDynamite()
{
	return m_shape.getTransform().transformPoint(m_shape.getPoint(3));
}
//=============================================================================



