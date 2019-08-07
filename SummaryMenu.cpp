#include "SummaryMenu.h"

//=============================================================================
SummaryMenu::SummaryMenu(const sf::Vector2f &windowSize)
	:Menu(windowSize)
{
	// init background
	m_background.setTexture(&Textures::instance()[SUMMARY_MENU_TN]);

	// init button
	sf::Vector2f btnPos = { (windowSize.x / 2) - (ButtonsSettings::getRegularBtnSize().x / 2), (windowSize.y / 6) * 5 };
	m_buttons.push_back(std::make_unique<ContinueButton>(btnPos, ButtonsSettings::getRegularBtnSize()));

	m_font.loadFromFile("Font.ttf");

	// init indicators
	sf::Vector2f pos = { windowSize.x / 2 + 120, windowSize.y / 7 + 5 };
	m_levelIndicator = sf::Text("1", m_font, 100);
	m_levelIndicator.setPosition(pos);
	m_levelIndicator.setFillColor(sf::Color::Black);

	pos.x = windowSize.x / 8;
	pos.y = windowSize.y / 2 - 75;

	m_player2Score = sf::Text("0", m_font, 50);
	m_player2Score.setPosition(pos);
	m_player2Score.setFillColor(sf::Color::Black);

	pos.x *= 4;
	pos.x += 75;

	m_player1Score = sf::Text("0", m_font, 50);
	m_player1Score.setPosition(pos);
	m_player1Score.setFillColor(sf::Color::Black);

	pos.x = windowSize.x / 6;
	pos.y = ((windowSize.y / 7) * 4) + 30;

	m_freeText = sf::Text("BLA BLA BLA", m_font, 50);
	m_freeText.setPosition(pos);
	m_freeText.setFillColor(sf::Color::Black);
}

//=============================================================================
void SummaryMenu::draw(sf::RenderWindow &window, int ln, int Player2Score, int player1Score, std::string name2, std::string name1)
{
	window.draw(m_background);

	for (auto &btn : m_buttons)
	{
		btn->draw(window);
	}

	m_levelIndicator.setString(std::to_string(ln + 1));

	m_player2Score.setString(name2 + "\nSCORE: " + std::to_string(Player2Score));
	m_player1Score.setString(name1 + "\nSCORE: " + std::to_string(player1Score));

	m_freeText.setString(getFreeText(Player2Score, player1Score, name2, name1));

	window.draw(m_levelIndicator);
	window.draw(m_player2Score);
	window.draw(m_player1Score);
	window.draw(m_freeText);
}

//=============================================================================
sf::String SummaryMenu::getFreeText(int player2Score, int player1Score, std::string name2, std::string name1)
{
	sf::String str;

	if (player2Score == 0 && player1Score == 0)
		str = "       START PLAY\nTry to beat your opponent";
	else if (player2Score == player1Score)
		str = "       Try harder!";
	else if (player2Score > player1Score)
		str = name2 + " Excellent!\n" + name1 + " Wake Up!";
	else
		str = name1 + " Excellent!\n" + name2 + " Wake Up!";

	return str;
}