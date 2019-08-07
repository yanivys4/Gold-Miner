#include "LevelController.h"
#include "Levels.h"

//=============================================================================
LevelController::LevelController(Player & player1, Player & player2)
	:m_toolBar(ControllerSettings::getWindowSize()), m_pauseMenu(ControllerSettings::getWindowSize()),
	m_player1(&player1), m_player2(&player2)
{
	// init the background
	m_background.setTexture(&Textures::instance()[LEVEL_BACKGROUND_TN]);
	m_background.setSize(ControllerSettings::getWindowSize());
	m_background.setPosition({ 0,0 });
}

//=============================================================================
void LevelController::initLevel(int requestedLevel)
{
	m_currentLevel = requestedLevel;
	m_timeElapsed = 0; // restart clock
	std::ifstream levelFile;
	openLevelFile(levelFile,LevelNames[requestedLevel]);
	initLevelTime(levelFile);
	m_board.initBoard(levelFile);
	m_toolBar.initToolBar(m_currentLevel);
	closeLevelFile(levelFile);
}

//=============================================================================
const std::type_info &LevelController::run(sf::RenderWindow & window)
{
	m_clock.restart(); // to prevent delays of animation

	std::string type = handleEvents(window);

	while (type != (typeid(ExitButton)).name() && type != (typeid(HomeButton)).name() && type != (typeid(SinglePlayerBtn)).name())
	{
		m_deltaTime = m_clock.restart().asSeconds();
		m_timeElapsed += m_deltaTime;
		m_player1->play(m_deltaTime, m_board, m_currentLevel);
		m_player2->play(m_deltaTime, m_board, m_currentLevel);
		// delete out of game objects
		m_board.updateBoard();
		// update the tool bar
		m_toolBar.updateToolbar((m_levelTime - m_timeElapsed), m_player1->getScore(),
								m_player2->getScore(), m_player1->getNumOfDynamites(),
								m_player2->getNumOfDynamites());
		window.clear();
		draw(window);
		window.display();

		type = handleEvents(window);

		if (type == (typeid(ResumeButton)).name())
			m_clock.restart();
	}

	if (type == (typeid(ExitButton)).name())
		return typeid(ExitButton);

	if (type == (typeid(HomeButton)).name())
		return typeid(HomeButton);

	return typeid(NULL);
}

//=============================================================================
void LevelController::setPlayer2(Player & player2)
{
	m_player2 = &player2;
}

//=============================================================================
std::string LevelController::handleEvents(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			return typeid(ExitButton).name();
			break;
		case sf::Event::MouseMoved:
			m_toolBar.hover(window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }));
			break;
		case sf::Event::MouseButtonReleased:
			return (clickHandle(window, window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }))).name();
			break;
		case sf::Event::KeyPressed:
			// player1 send hook
			if (event.key.code == sf::Keyboard::Down)
				m_player1->updateIsSent();
			// player1 throw dynamite
			else if (event.key.code == sf::Keyboard::Up)
				if (!m_player1->isThrowingDynamite())
					m_player1->dynamiteTry();
			// checks if player2 isnt computer
			if (dynamic_cast<HumanPlayer *>(m_player2))
			{
				// player1 send hook
				if (event.key.code == sf::Keyboard::S)
					m_player2->updateIsSent();
				// player1 throw dynamite
				else if (event.key.code == sf::Keyboard::W)
					if(!m_player2->isThrowingDynamite())
						m_player2->dynamiteTry();
			}
			break;
		}
	}

	// if the board is empty or the time is over pass to the next level
	if (m_board.isEmpty() || (m_levelTime - m_timeElapsed) < 0)
		return (typeid(SinglePlayerBtn)).name();

	return (typeid(NULL)).name();
}

//=============================================================================
void LevelController::draw(sf::RenderWindow & window)
{
	window.draw(m_background);
	m_board.draw(window);
	m_player1->draw(window);
	m_player2->draw(window);
	m_toolBar.draw(window);
}

//=============================================================================
void LevelController::openLevelFile(std::ifstream & file, std::string name)
{
	file.open(name);
}

//=============================================================================
void LevelController::closeLevelFile(std::ifstream & file)
{
	file.close();
}

//=============================================================================
void LevelController::initLevelTime(std::ifstream & file)
{
	std::string temp;
	std::getline(file, temp);
	m_levelTime = float(std::stoi(temp));
}

//=============================================================================
const std::type_info &LevelController::clickHandle(sf::RenderWindow &window, const sf::Vector2f & point)
{
	const std::type_info &type = m_toolBar.click(point);
	std::string type2;

	if (type.name() == (typeid(PauseButton)).name())
	{
		type2 = pauseMenuHandleEvent(window).name();

		while (type2 == (typeid(MuteButton)).name() || type2 == (typeid(NULL)).name())
		{
			if (type2 == (typeid(MuteButton)).name())
			{
				// play or pause the music
				if (Sounds::getbackgroundMusic().getStatus() == sf::SoundSource::Playing)
				{
					Sounds::getbackgroundMusic().pause();
				}
				else
				{
					Sounds::getbackgroundMusic().play();
					Sounds::getbackgroundMusic().setLoop(true);
				}
			}

			m_pauseMenu.draw(window);
			window.display();

			type2 = pauseMenuHandleEvent(window).name();
		}
	}

	if (type2 == (typeid(HomeButton)).name())
		return typeid(HomeButton);

	if (type2 == (typeid(ExitButton)).name())
		return typeid(ExitButton);

	if (type2 == (typeid(ResumeButton)).name())
		return typeid(ResumeButton);

	return typeid(NULL);
}

//=============================================================================
const std::type_info &LevelController::pauseMenuHandleEvent(sf::RenderWindow & window)
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
			m_pauseMenu.hover(window.mapPixelToCoords({ event.mouseMove.x,event.mouseMove.y }));
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
				return m_pauseMenu.click(window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
			break;
		}
	}

	return typeid(NULL);
}