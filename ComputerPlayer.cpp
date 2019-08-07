#include "ComputerPlayer.h"

//=============================================================================
ComputerPlayer::ComputerPlayer(const sf::Vector2f & position, std::string name):Player(position, name)
{
	m_shape.setTexture(&Textures::instance()[COMP_MINING_TN]);	

	m_mineAnimation = Animation(&Textures::instance()[COMP_MINING_TN],
								AnimationSettings::getMineImageCount(),
								AnimationSettings::getSwitchTime());

	m_dynamiteAnimation = Animation(&Textures::instance()[COMP_THROW_TN],
									AnimationSettings::getDynamiteImageCount(), 
									AnimationSettings::getSwitchTime());
	
	m_bestAngle = UNUSED_ANGLE;
}

//=============================================================================
void ComputerPlayer::play(float deltaTime, Board & board, int lvl)
{
	// checks if the player is in frozen mode
	if (m_isFrozen)
	{
		m_freezeTime += m_freezeClock.getElapsedTime().asSeconds();

		if (m_freezeTime >= 2000.f)// checks if the time of freeze is passed
		{
			m_isFrozen = false;
			m_freezeTime = 0.f;
			changeToMineTexture();
		}
	}
	else if (!m_hook.isSent())// checks if the player isnt sent the hook
	{
		// find best angle only if best angle is unused
		if (m_bestAngle == UNUSED_ANGLE)
			m_bestAngle = findBestAngle(board, lvl);

		// checks if current angle even to best angle and update the is send indicator
		if (m_hook.getAngle() == m_bestAngle)
		{
			m_hook.setSent();
			m_bestAngle = UNUSED_ANGLE;
		}
		else// rotate the hook
			m_hook.rotate(deltaTime);
	}
	else// if the player send the hook
	{
		// checks if the hook attached some object and if the player isnt in throwing dynamite mode
		if (m_hook.isAttached() && !isThrowingDynamite())
		{
			if (dynamic_cast<RegularRock*> (m_hook.getGrabbedObject()))
			{
				// checks if the player need to throw dynamite
				if (m_hook.getGrabbedObject()->getObjectSize() == BoardSettings::getBigSize() && board.getNumberOfObjects() > 2)
				{
					dynamiteTry();
				}
			}
		}

		// send mode
		sendHook(deltaTime, board);
	}
			
}

//=============================================================================
void ComputerPlayer::changeToMineTexture()
{
	m_shape.setTexture(&Textures::instance()[COMP_MINING_TN]);
}

//=============================================================================
void ComputerPlayer::changeToThrowTexture()
{
	m_shape.setTexture(&Textures::instance()[COMP_THROW_TN]);
}

//=============================================================================
void ComputerPlayer::changeToFreezeTexture()
{
	m_shape.setTexture(&Textures::instance()[FROZEN_COMP_TN]);
}

//=============================================================================
float ComputerPlayer::findBestAngle(Board & board, int lvl)
{
	m_fakeRope = sf::RectangleShape(sf::Vector2f(10, 5));
	sf::RectangleShape fakeHook(sf::Vector2f(45, 45));// to imagine a hook
	m_fakeRope.setPosition(m_hook.getPosition());
	sf::Vector2f size = m_fakeRope.getSize();
	float bestAngle;

	std::vector<std::pair<float, int>> AnglesNScores;// holds all angles and the best score for every angle 

	// do the best algorithm random in relation to the stage 
	if (rand() % (4 - lvl) == 0)
	{
		// pass all of hook angle
		for (float i = -80; i <= 80; i += 2)
		{
			m_fakeRope.setRotation(i + 90);
			size.x = 10;
			fakeHook.setRotation(i);

			// pass all of distances until intersects with some object
			for (int j = 0; j < 600; j += 40)
			{
				size.x = float(j);
				m_fakeRope.setSize(size);
				fakeHook.setPosition(m_fakeRope.getTransform().transformPoint(m_fakeRope.getPoint(2)));

				// get the score of the object that collision with the fake hook
				int score = board.getCollisionScore(fakeHook.getGlobalBounds());

				// if the score is a score of some object move to next angle
				if (score != -10)
				{
					AnglesNScores.push_back(std::pair<float, int>(i, score));
					break;
				}
			}
		}

		int maxScore = 0;
		bestAngle = UNUSED_ANGLE;

		// find the best angle from all angles
		for (auto &pair : AnglesNScores)
		{
			if (pair.second > maxScore)
			{
				maxScore = pair.second;
				bestAngle = pair.first;
			}
		}
	}
	else// choose some random angle
	{
		bestAngle = (rand() % 161) - 80.f;
	}

	return bestAngle;// return the best angle
}
