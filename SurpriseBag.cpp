#include "SurpriseBag.h"

bool SurpriseBag::m_registerit = Factory::registerit('?', [](const sf::Vector2f & pos) -> std::unique_ptr<BoardObject> { return std::make_unique<SurpriseBag>(pos); });

//=============================================================================
SurpriseBag::SurpriseBag(const sf::Vector2f & position):BoardObject(position)
{
	m_shape.setTexture(&Textures::instance()[SURPRISE_BAG_TN]);
	m_shape.setSize(BoardSettings::getRegularSize()); 
	chooseKind();
}

//=============================================================================
int SurpriseBag::getScore() const
{
	return 1;
}

//=============================================================================
feature SurpriseBag::getFeature()
{
	return m_feature;
}

//=============================================================================
void SurpriseBag::chooseKind()
{
	int kind = rand() % 3;
	switch (kind)
	{
	case 0 :
		m_feature = EXTRA_DYNAMITE_F;
		break;
	case 1:
		m_feature = FREEZE_F;
		break;
	case 2:
		m_feature = EXTRA_COINS;
		break;
	}
}