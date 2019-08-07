#include "PauseMenu.h"

//=============================================================================
PauseMenu::PauseMenu(const sf::Vector2f &windowSize)
	:Menu(windowSize)
{
	// init the background
	sf::Color backColor = sf::Color::White;
	backColor.a = 1;
	m_background.setFillColor(backColor);

	// init the image
	sf::Vector2f rectSize = { windowSize.x / 2, windowSize.y / 4 };
	m_image.setSize(rectSize);
	sf::Vector2f rectPos = { windowSize.x / 4, windowSize.y / 3 };
	m_image.setPosition(rectPos);
	m_image.setTexture(&Textures::instance()[PAUSE_MENU_TN]);

	// init the buttons
	sf::Vector2f btnPos = { rectPos.x + 70, rectPos.y + 50 };
	m_buttons.push_back(std::make_unique<HomeButton>(btnPos, ButtonsSettings::getRegularBtnSize()));
	btnPos.x += 100;
	m_buttons.push_back(std::make_unique<ExitButton>(btnPos, ButtonsSettings::getRegularBtnSize()));
	btnPos.x += 100;
	m_buttons.push_back(std::make_unique<ResumeButton>(btnPos, ButtonsSettings::getRegularBtnSize()));
	btnPos.x += 100;
	m_buttons.push_back(std::make_unique<MuteButton>(btnPos, ButtonsSettings::getRegularBtnSize()));
}

//=============================================================================
void PauseMenu::draw(sf::RenderWindow & window)
{
	window.draw(m_background);
	window.draw(m_image);

	for (auto &btn : m_buttons)
	{
		btn->draw(window);
	}
}


