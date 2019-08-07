#include "GameOverMenu.h"

//=============================================================================
GameOverMenu::GameOverMenu(const sf::Vector2f &windowSize)
	:Menu(windowSize)
{
	// init the background
	sf::Color backColor = sf::Color::White;
	backColor.a = 100;
	m_background.setFillColor(backColor);

	// init the image
	m_image.setTexture(&Textures::instance()[GAME_OVER_BACK_TN]);
	m_image.setSize(windowSize);

	// init the buttons
	sf::Vector2f btnPos = { windowSize.x - 2 * ButtonsSettings::getRegularBtnSize().x - 20, windowSize.y - ButtonsSettings::getRegularBtnSize().x - 10 };
	m_buttons.push_back(std::make_unique<HomeButton>(btnPos, ButtonsSettings::getRegularBtnSize()));
	btnPos.x += 10 + ButtonsSettings::getRegularBtnSize().x;
	m_buttons.push_back(std::make_unique<ExitButton>(btnPos, ButtonsSettings::getRegularBtnSize()));

	// init the text
	m_font.loadFromFile("Font.ttf");
	m_winner = sf::Text("", m_font, 80);
	m_winner.setFillColor(sf::Color::Yellow);
	m_winner.setOutlineThickness(2);
	m_winner.setOutlineColor(sf::Color::Black);
	sf::Vector2f pos = windowSize;
	pos.x /= 4;
	pos.x += 40;
	pos.y /= 8;
	m_winner.setPosition(pos);
}

//=============================================================================
void GameOverMenu::draw(sf::RenderWindow & window)
{
	window.draw(m_background);
	window.draw(m_image);

	for (auto &btn : m_buttons)
	{
		btn->draw(window);
	}

	m_winner.setFont(m_font);
	window.draw(m_winner);
}

//=============================================================================
void GameOverMenu::setWinner(std::string winner)
{
	m_winner.setString(winner);
}