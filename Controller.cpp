#include "Controller.h"

//=============================================================================
Controller::Controller()
	:m_window(sf::VideoMode(unsigned int(ControllerSettings::getWindowSize().x), unsigned int(ControllerSettings::getWindowSize().y)),
							ControllerSettings::getWindowTitle()),
	m_homeMenu(ControllerSettings::getWindowSize()),
	m_gameController(ControllerSettings::getWindowSize())
{
}

//=============================================================================
void Controller::run()
{
	// play the background music
	Sounds::instance().getbackgroundMusic().play();
	Sounds::instance().getbackgroundMusic().setLoop(true);

	// run the game as long as the window is open
	while (m_window.isOpen())
	{
		draw();
		handleEvents();
	}
}

//=============================================================================
void Controller::draw()
{
	m_window.clear();

	m_homeMenu.draw(m_window);

	m_window.display();
}

//=============================================================================
void Controller::handleEvents()
{
	sf::Event event;

	while (m_window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::MouseButtonReleased:
			if (event.mouseButton.button == sf::Mouse::Left)
				clickHandle(m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y }));
			break;
		case sf::Event::MouseMoved:
			m_homeMenu.hover(m_window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y }));
			break;
		}
	}
}

//=============================================================================
void Controller::clickHandle(const sf::Vector2f &point)
{
	const std::type_info &type = m_homeMenu.click(point);// get the type of button from the home menu

	if (type.name() != (typeid(NULL)).name())
	{
		if (type.name() == (typeid(ExitButton)).name())
		{
			m_window.close();
			return;
		}
		if (type.name() == (typeid(SinglePlayerBtn)).name())
		{
			if (!m_gameController.playGame(m_window, true))// play single player
				m_window.close();
			return;
		}
		if (type.name() == (typeid(MultiPlayerBtn)).name())
		{
			if (!m_gameController.playGame(m_window, false))// play multi player
				m_window.close();
			return;
		}
		if (type.name() == (typeid(MuteButton)).name())
		{
			if (Sounds::getbackgroundMusic().getStatus() == sf::SoundSource::Playing)
			{
				Sounds::getbackgroundMusic().pause();
			}
			else
			{
				Sounds::getbackgroundMusic().play();
			}
			return;
		}
	}
}