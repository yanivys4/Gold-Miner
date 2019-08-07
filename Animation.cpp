#include "Animation.h"

//=============================================================================
Animation::Animation(sf::Texture * texture, sf::Vector2u imageCount, float switchTime)
	:m_imageCount(imageCount), m_switchTime(switchTime)
{
	m_totalTime = 0.0f;
	m_currentImage.x = 0;
	m_uvRect.width = texture->getSize().x  / int(m_imageCount.x);
	m_uvRect.height = texture->getSize().y / int(m_imageCount.y);
}

//=============================================================================
void Animation::update(int row,float deltaTime)
{
	m_currentImage.y = row;
	m_totalTime += deltaTime;

	if (m_totalTime >= m_switchTime)
	{
		m_totalTime -= m_switchTime;
		m_currentImage.x++;

		if (m_currentImage.x >= m_imageCount.x)
		{
			m_onceAnimation = true; // reached one set of whole frames
			m_currentImage.x = 0;
		}
	}

	m_uvRect.left = ( m_currentImage.x * m_uvRect.width);
	m_uvRect.top = (m_currentImage.y * m_uvRect.height);
}

//=============================================================================
void Animation::setSwitchTime(const sf::Vector2f & size)
{
	// change to small switch time and than change by it format
	if (size == BoardSettings::getSmallSize())
	{
		m_switchTime = AnimationSettings::getSwitchTime() *1.2f;
	}
	else if (size == BoardSettings::getRegularSize())
	{
		m_switchTime = AnimationSettings::getSwitchTime() * 1.5f;
	}
	else
	{
		m_switchTime = AnimationSettings::getSwitchTime() * 2;
	}
}

//=============================================================================
void Animation::restartSwitchTime()
{
	m_switchTime = AnimationSettings::getSwitchTime();
}

//=============================================================================
void Animation::resetOnceAnimation()
{
	m_onceAnimation = false;
}

//=============================================================================
sf::IntRect & Animation::getUvRect(int row, float deltaTime)
{
	update(row, deltaTime);
	return m_uvRect;
}

//=============================================================================
bool Animation::getOnceAnimation() const
{
	return m_onceAnimation;
}
