#include "GameController.h"

//=============================================================================
GameController::GameController(const sf::Vector2f &windowSize)
	:m_gameOverMenu(windowSize), m_summaryMenu(windowSize), m_player1(PlayerSettings::getPlayer1Pos(), "PLAYER 1"),
	m_player2(PlayerSettings::getPlayer2Pos(), "PLAYER 2"), m_computerPlayer(PlayerSettings::getPlayer2Pos(), "COMPUTER"),
	m_levelController(m_player1, m_computerPlayer)
{
	m_IsLevelRun = false;
}

//=============================================================================
bool GameController::playGame(sf::RenderWindow & window, bool mode)
{
	// set the level controller to multiplayer
	if (!mode)
		m_levelController.setPlayer2(m_player2);
	// set the level controller to singleplayer
	else
		m_levelController.setPlayer2(m_computerPlayer);

	// pass all stages in the game
	for (int numOfLevel = 0; numOfLevel < NUM_OF_LEVELS;)
	{
		m_IsLevelRun = false;

		window.clear();

		// draw the summary menu in every mode
		if (mode)
			m_summaryMenu.draw(window, numOfLevel, m_computerPlayer.getScore(), 
							   m_player1.getScore(), m_computerPlayer.getName(), m_player1.getName());
		else
			m_summaryMenu.draw(window, numOfLevel, m_player2.getScore(), 
							   m_player1.getScore(), m_player2.getName(), m_player1.getName());

		window.display();

		const std::type_info &type = handleSummaryEvents(window, numOfLevel);

		// update the level num only if the level is run
		if (m_IsLevelRun)
			numOfLevel++;

		// check if the player press the exit button or home button
		if (type.name() == (typeid(ExitButton)).name())
			return false;
		if (type.name() == (typeid(HomeButton)).name())
		{
			resetPlayers();
			return true;
		}
	}

	showGameOverMenu(window, mode);

	return handleGameOverEvents(window);
}

//=============================================================================
const std::type_info &GameController::handleSummaryEvents(sf::RenderWindow &window, int ln)
{
	sf::Event event;

	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			return typeid(ExitButton);
			break;
		case sf::Event::MouseMoved:
			m_summaryMenu.hover(window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }));
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
				return summaryClickHandle(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }), window, ln);
			break;
		}
	}

	return typeid(NULL);
}

//=============================================================================
const std::type_info &GameController::summaryClickHandle(const sf::Vector2f point, sf::RenderWindow &window, int ln)
{
	const std::type_info &type1 = m_summaryMenu.click(point);

	if (type1.name() == (typeid(ContinueButton)).name())
	{
		window.clear();
		sf::sleep(sf::Time(sf::seconds(0.5)));
		m_levelController.initLevel(ln); 
		if (ln > 0) 
		{
			m_computerPlayer.resetHook(PlayerSettings::getPlayer2Pos());
			m_player1.resetHook(PlayerSettings::getPlayer1Pos());
			m_player2.resetHook(PlayerSettings::getPlayer2Pos());
		}
		
		m_IsLevelRun = true;
		return m_levelController.run(window);
	}

	return typeid(NULL);
}

//=============================================================================
void GameController::showGameOverMenu(sf::RenderWindow &window, bool mode)
{
	// show the game over menu according the mode
	if (mode)
	{
		if (m_computerPlayer.getScore() > m_player1.getScore())
			m_gameOverMenu.setWinner(m_computerPlayer.getName());
		else
			m_gameOverMenu.setWinner(m_player1.getName());
	}
	else
	{
		if (m_player2.getScore() > m_player1.getScore())
			m_gameOverMenu.setWinner(m_player2.getName());
		else
			m_gameOverMenu.setWinner(m_player1.getName());
	}

	window.display();

	m_gameOverMenu.draw(window);

	window.display();
}

//=============================================================================
bool GameController::handleGameOverEvents(sf::RenderWindow & window)
{
	sf::Event event;

	while (true)
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				return false;
				break;
			case sf::Event::MouseMoved:
				m_gameOverMenu.hover(window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }));
				break;
			case sf::Event::MouseButtonReleased:
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					const std::type_info &type = m_gameOverMenu.click(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
					if (type.name() == (typeid(HomeButton)).name())
					{
						resetPlayers();
						return true;
					}
					else if (type.name() == (typeid(ExitButton)).name())
						return false;
				}
				break;
			}
		}
	}
}

//=============================================================================
void GameController::resetPlayers()
{
	m_computerPlayer = ComputerPlayer(PlayerSettings::getPlayer2Pos(), "COMPUTER");
	m_player1 = HumanPlayer(PlayerSettings::getPlayer1Pos(), "PLAYER 1");
	m_player2 = HumanPlayer(PlayerSettings::getPlayer2Pos(), "PLAYER 2");
}
