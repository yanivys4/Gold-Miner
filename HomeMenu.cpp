#include "HomeMenu.h"

//=============================================================================
HomeMenu::HomeMenu(const sf::Vector2f &windowSize)
	:Menu(windowSize)
{
	// init background
	m_background.setTexture(&Textures::instance()[HOME_MENU_TN]);

	// init buttons
	sf::Vector2f startBtnPos = { 50, (windowSize.y / 8.f) * 2.5f };
	sf::Vector2f btnPos = { windowSize.x - ButtonsSettings::getRegularBtnSize().x - 20 , 20.f };
	m_buttons.push_back(std::make_unique<SinglePlayerBtn>(startBtnPos, ButtonsSettings::getStartBtnSize()));
	startBtnPos.x += ButtonsSettings::getStartBtnSize().x + 30;
	startBtnPos.y += 50;
	m_buttons.push_back(std::make_unique<MultiPlayerBtn>(startBtnPos, ButtonsSettings::getStartBtnSize()));
	m_buttons.push_back(std::make_unique<ExitButton>(btnPos, ButtonsSettings::getRegularBtnSize()));
	btnPos.x -= ButtonsSettings::getRegularBtnSize().x + 10;
	m_buttons.push_back(std::make_unique<MuteButton>(btnPos, ButtonsSettings::getRegularBtnSize()));
}

//=============================================================================
void HomeMenu::draw(sf::RenderWindow & window)
{
	window.draw(m_background);

	for (auto &btn : m_buttons)
	{
		btn->draw(window);
	}
}



