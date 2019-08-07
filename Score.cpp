#include "Score.h"

//=============================================================================
Score::Score(const sf::Vector2f &position)
	:VisualObject(position)
{
	// init shape
	m_shape.setTexture(&Textures::instance()[COIN_TN]);
	m_shape.setSize(VisualObjectSettings::getCoinSize());

	// init text
	sf::Vector2f pos = { position.x + 35, position.y };
	m_text.setString("0");
	m_text.setFillColor(sf::Color::Yellow);
	m_text.setCharacterSize(25);
	m_text.setPosition(pos);
}

//=============================================================================
void Score::setScore(int score)
{
	m_text.setString(std::to_string(score));
}

