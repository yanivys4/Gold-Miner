#include "Player.h"

//=============================================================================
Player::Player(const sf::Vector2f & position, std::string name)
	:Object(position)
{
	m_shape.setSize(PlayerSettings::getPlayerSize());
	m_shape.setTextureRect(sf::IntRect(0, 0, int(PlayerSettings::getPlayerSize().x),
		int(PlayerSettings::getPlayerSize().y)));
	sf::Vector2f hookPos = { position.x + (PlayerSettings::getPlayerSize().x) * 1/3, position.y + (PlayerSettings::getPlayerSize().y) * 6/7 };
	m_hook = Hook(hookPos);
	m_isBarrelTime = false;

	m_font.loadFromFile("Font.ttf");
	m_name = sf::Text(name, m_font, 20);
	sf::Vector2f namePos = position;
	namePos.y -= 50;
	m_name.setPosition(namePos);

	m_rewardSound.setVolume(20);
	m_dynamite = Dynamite(m_shape.getTransform().transformPoint(m_shape.getPoint(3)), AnimationSettings::getSwitchTime());
}

//=============================================================================
void Player::draw(sf::RenderWindow & window)
{
	Object::draw(window);
	m_hook.draw(window);
	m_dynamite.draw(window);
	m_name.setFont(m_font);
	window.draw(m_name);
}

//=============================================================================
void Player::mine(float deltaTime)
{
	m_shape.setTextureRect(sf::IntRect (m_mineAnimation.getUvRect(0, deltaTime)));
}

//=============================================================================
void Player::throwDynamite(float deltaTime)
{
	m_shape.setTextureRect(sf::IntRect(m_dynamiteAnimation.getUvRect(0, deltaTime)));
}

//=============================================================================
void Player::sendHook(float deltaTime, Board & board)
{
	if (m_hook.isBack()) // grab mode 
	{
		if (m_hook.isThrowingDynamite())
		{

			if (!m_dynamiteAnimation.getOnceAnimation())
			{
				throwDynamite(deltaTime); // throw dynamite animation

			}
			else if (m_isThrowingDynamite)
			{
				m_dynamite.makeDynamiteVissible(true);
				m_dynamite.setRotation(m_hook.getAngle());
				if (!m_dynamite.sendDynamite(m_hook.getGrabbedObject()->getPosition(), deltaTime))
				{
					m_isThrowingDynamite = false;
					m_hook.getGrabbedObject()->prepareForExplosion();
					changeToMineTexture();
					m_hook.getGrabbedObject()->playExplosionSound();
				}

			}
			else if (!m_hook.getGrabbedObject()->explode(deltaTime))
			{
				// do nothing the action is in the condition
			}
			else
			{
				m_isThrowingDynamite = true;
				m_dynamite.makeDynamiteVissible(false);
				m_hook.updateIsAttached(false);
				m_hook.updateThrowingMode(false);
				m_hook.setGrabbedObject(nullptr);
				m_dynamiteAnimation.resetOnceAnimation();
				m_hook.setTexture(Textures::instance()[HOOK_TN]);
			}

			return;
		}

		mine(deltaTime);
	}
	else
	{
		m_shape.setTextureRect(sf::IntRect(0, 0,(int) PlayerSettings::getPlayerSize().x,
			(int)PlayerSettings::getPlayerSize().y));

		if (m_hook.setGrabbedObject(board.checkCollision(m_hook.getGlobalBounds())))
		{
			if (dynamic_cast<Barrel *>(m_hook.getGrabbedObject()))
			{
				if (!m_isBarrelTime)
				{
					m_hook.getGrabbedObject()->prepareForExplosion();
					m_isBarrelTime = true;
					m_hook.getGrabbedObject()->playExplosionSound();
				}
				if (!(m_hook.getGrabbedObject()->explode(deltaTime)))
				{
					board.barrelExplode(m_hook.getGrabbedObject()->getGlobalBounds(), deltaTime);
					m_hook.updateIsAttached(false);
					return;
				}
				else
				{
					board.removeBarrelExp();
					m_hook.setBack();
					m_isBarrelTime = false;
				}
			}
			else
				// if the hook has catched an object update the animation
				m_mineAnimation.setSwitchTime(m_hook.getGrabbedObject()->getObjectSize());
		}
	}

	//send only if not in throwDynamite mode
	if (m_hook.send(deltaTime))
	{
		if (m_hook.isAttached())
		{
			getReward();
			m_hook.setGrabbedObject(nullptr);
			m_mineAnimation.restartSwitchTime();
			m_hook.setTexture(Textures::instance()[HOOK_TN]); // restore hook texture to normal!!!!!!!!!!
		}

		//if the hook is not attached the hook back without a thing
		m_shape.setTextureRect(sf::IntRect(0, 0, (int)PlayerSettings::getPlayerSize().x,
			(int)PlayerSettings::getPlayerSize().y));
		m_hook.restoreIndicators();
	}
}

//=============================================================================
int Player::getScore() const
{
	return m_score;
}

//=============================================================================
int Player::getNumOfDynamites() const
{
	return m_numOfDynamites;
}

//=============================================================================
void Player::resetHook(const sf::Vector2f &position)
{
	m_hook.reset(position);
}

bool Player::isThrowingDynamite() const
{
	return m_hook.isThrowingDynamite();
}

//=============================================================================
std::string Player::getName() const
{
	return m_name.getString();
}

//=============================================================================
void Player::getReward()
{
	SurpriseBag * s; // used only for getting reward from surprise bag
	BoardObject * ptr = m_hook.getGrabbedObject();
	ptr->setOutOfGame();
	
	if (dynamic_cast<Rock *>(ptr))
	{
		m_score += ptr->getScore();
		playRewardSound();
	}
	else if (s = dynamic_cast<SurpriseBag*>(ptr))
	{
		getFeature(s->getFeature());
	}
}

//=============================================================================
void Player::getFeature(feature f)
{
	switch (f)
	{
	case EXTRA_DYNAMITE_F:
		m_numOfDynamites++;
		break;
	case EXTRA_COINS:
		m_score += 500;
		break;
	case FREEZE_F:
		changeToFreezeTexture();
		m_isFrozen = true;
		m_freezeClock.restart();
		break;
	}
}

//=============================================================================
void Player::updateIsSent()
{
	m_hook.setSent();
}

//=============================================================================
void Player::dynamiteTry()
{
	if (m_hook.isBack() && m_hook.isAttached() && m_numOfDynamites > 0)
	{
		m_hook.updateThrowingMode(true);// let the hook know the try to throw dynamite has succeded
		changeToThrowTexture();
		m_numOfDynamites--;
	}
}

//=============================================================================
void Player::playRewardSound()
{
	m_rewardSound.setBuffer(Sounds::instance()[REWRAD_SO]);
	m_rewardSound.play();
}
//=============================================================================