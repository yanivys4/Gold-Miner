#include "LevelIndicator.h"

//=============================================================================
LevelIndicator::LevelIndicator(const sf::Vector2f &position)
	:VisualObject(position)
{
	// init the shape
	m_shape.setTexture(&Textures::instance()[LEVEL_INDICATOR_TN]);
	m_shape.setSize(VisualObjectSettings::getLevelIndicatorSize());

	// init the text
	sf::Vector2f pos = { position.x + 50, position.y + 5 };
	m_text.setString("Level: 1");
	m_text.setPosition(pos);
}

//=============================================================================
void LevelIndicator::setLevel(int lvl)
{
	m_text.setString("Level: " + std::to_string(lvl + 1));
}
