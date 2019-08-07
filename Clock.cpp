#include "Clock.h"

//=============================================================================
Clock::Clock(const sf::Vector2f & position)
	:VisualObject(position)
{
	m_shape.setTexture(&Textures::instance()[CLOCK_TN]);
	m_shape.setSize(VisualObjectSettings::getClockSize());

	sf::Vector2f pos = { position.x + 40, position.y + 7 };
	m_text.setString("0:00");
	m_text.setPosition(pos);
}

//=============================================================================
void Clock::setTime(float time)
{
	float timeAsMillieSec = (time - int(time)) * 100;
	m_text.setString(std::to_string(int(time)) + ":" + std::to_string((int(timeAsMillieSec))));
}

