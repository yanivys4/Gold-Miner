#include "Hook.h"
#include <math.h>

//=============================================================================
Hook::Hook(const sf::Vector2f &position)
	:Object(position), m_rope(sf::Vector2f(10, 5))
{
	// init shape
	m_shape.setTexture(&Textures::instance()[HOOK_TN]);
	m_shape.setSize({40, 40});
	m_shape.setOrigin({ m_shape.getSize().x /2,0});
	m_angle = 80.f;

	// init times
	m_totalRotateTime = 0.0f;
	m_totalGrabTime = 0.0f;
	m_grabTime = HookSettings::getGrabTime();

	// init indicators
	m_isSent = false;
	m_direction = false;
	m_isBack = false;
	m_isAttached = false;
	m_throwingDynamite = false;

	//init rope
	sf::Color ropeColor = sf::Color(126, 80, 55);
	m_rope.setPosition(position);
	m_rope.setFillColor(ropeColor);
	m_shape.setPosition(getEndOfRope());
}

//=============================================================================
void Hook::draw(sf::RenderWindow & window)
{
	Object::draw(window);
	window.draw(m_rope);
}

//=============================================================================
void Hook::reset(const sf::Vector2f &position)
{
	sf::Vector2f hookPos = { position.x + (PlayerSettings::getPlayerSize().x) * 1 / 3, position.y + (PlayerSettings::getPlayerSize().y) * 6 / 7 };
	m_shape.setTexture(&Textures::instance()[HOOK_TN]);
	m_shape.setSize({ 40, 40 });
	m_shape.setOrigin({ m_shape.getSize().x / 2,0 });
	m_direction = false;
	restoreIndicators();
	m_totalRotateTime = 0.0f;
	m_totalGrabTime = 0.0f;
	m_angle = 80.f;
	m_grabTime = HookSettings::getGrabTime();
	m_rope.setSize(sf::Vector2f(10, 5));
	m_rope.setPosition(hookPos);
	m_shape.setPosition(getEndOfRope());
	m_grabbedObject = nullptr;
}

//=============================================================================
void Hook::setAngle()
{
	m_rope.setRotation(m_angle + 90);
	m_shape.setRotation(m_angle);
	m_shape.setPosition(getEndOfRope());
}

//=============================================================================
float Hook::getAngle() const
{
	return m_angle;
}

//=============================================================================
sf::Vector2f Hook::getEndOfRope()
{
	return m_rope.getTransform().transformPoint(m_rope.getPoint(2));
}

//=============================================================================
void Hook::rotate(float deltaTime)
{
	m_totalRotateTime += deltaTime;
	if (m_totalRotateTime >= HookSettings::getRotationTime())
	{
		m_totalRotateTime -= HookSettings::getRotationTime();
		if (m_angle == (HookSettings::getHookBounds().y)) // most left angle
		{
			m_direction = true;
		}
		else if (m_angle == (HookSettings::getHookBounds().x)) // most right angle
		{
			m_direction = false;
		}

		if (m_direction) // move right
		{
			m_angle++;
		}

		else
		{
			m_angle--;
		}

		setAngle(); // update the actual angle
	}
}

//=============================================================================
bool Hook::send(float deltaTime)
{
	m_totalGrabTime += deltaTime;
	
	sf::Vector2f pos = m_shape.getPosition();
	sf::Vector2f size = m_rope.getSize();

	if (!m_isBack) // send hook down
	{
		size.x += 1;
		m_rope.setSize(size);
	}

	// sets the position of the hook to the end of the rope
	sf::Vector2f newPos = getEndOfRope();
	m_shape.setPosition(newPos);

	// check collision and change m_isBack if found collision
	// by the way when there will be explosion after explosion m_isBack will be changed
	// to true and the object exploded will be udated to be deleted

	if (pos.x < 0 || pos.x > ControllerSettings::getWindowSize().x || pos.y > ControllerSettings::getWindowSize().y)//happens once if the hook has not taken anything
		m_isBack = true;
		
	if (m_isBack)
		grab(size);

	if (size.x == 10)
		return true; // back to player check the situation

	return false;
}

//=============================================================================
void Hook::setSent()
{
	m_isSent = true;
}

//=============================================================================
void Hook::setBack()
{
	m_isBack = true;
}

//=============================================================================
void Hook::updateIsAttached(bool status)
{
	m_isAttached = status;
}

//=============================================================================
sf::FloatRect Hook::getGlobalBounds() const
{
	return m_shape.getGlobalBounds();
}

//=============================================================================
bool Hook::setGrabbedObject(BoardObject *obj)
{
	if (obj == nullptr)
	{
		// the case object was deleted and the player wants to restore the hook 
		m_grabTime = HookSettings::getGrabTime();
		m_grabbedObject = obj; 
		
		return false;
	}

	if (m_grabbedObject == nullptr)
	{
		m_grabbedObject = obj;
		m_isAttached = true;
		if (!dynamic_cast<Barrel*> (m_grabbedObject))
		{
			m_isBack = true;
			m_grabbedObject->activateGrabeMode();
			changeGrabSpeed(obj->getObjectSize());
			m_grabbedObject->setRotation(m_shape.getRotation() + 45);
			m_shape.setTexture(&Textures::instance()[HALF_HOOK_TN]);
		}
		 
		return true;
	}

	return true;
}

//=============================================================================
BoardObject * Hook::getGrabbedObject()
{
	return m_grabbedObject;
}

//=============================================================================
void Hook::setTexture(sf::Texture & texture)
{
	m_shape.setTexture(&texture);
}

//=============================================================================
void Hook::grab(sf::Vector2f & size)
{
	if (m_totalGrabTime >= m_grabTime)
	{
		m_totalGrabTime -= m_grabTime;
		size.x -= 1;
		m_rope.setSize(size);
	}

	if(m_isAttached)
		m_grabbedObject->setPosition(m_shape.getPosition());
}

//=============================================================================
void Hook::changeGrabSpeed(const sf::Vector2f & size)
{
	if (size == BoardSettings::getRegularSize())
		m_grabTime = HookSettings::getGrabTime() + 0.005f * 1.2f;
	else if (size == BoardSettings::getBigSize())
		m_grabTime = HookSettings::getGrabTime() + 0.005f * 3.f;
	else
		m_grabTime = HookSettings::getGrabTime() + 0.005f;
}

//=============================================================================
void Hook::restoreIndicators()
{
	m_isBack = false; // for next time use in retrieve hook
	m_isSent = false; // no more in send mode the hook is back at the player
	m_isAttached = false; // no more attached 
}

//=============================================================================
float Hook::getGrabTime()
{
	return m_grabTime;
}

//=============================================================================
bool Hook::isSent()
{
	return m_isSent;
}

//=============================================================================
bool Hook::isBack()
{
	return m_isBack;
}

//=============================================================================
bool Hook::isAttached()
{
	return m_isAttached;
}

//=============================================================================
bool Hook::isThrowingDynamite()const
{
	return m_throwingDynamite;
}

//=============================================================================
void Hook::updateThrowingMode(bool status)
{
	m_throwingDynamite = status;
}
