#include "ToolBar.h"

//=============================================================================
ToolBar::ToolBar(sf::Vector2f windowSize)
{
	// init the pause button
	sf::Vector2f btnSize = ButtonsSettings::getRegularBtnSize();
	btnSize.x /= 2;
	btnSize.y /= 2;
	m_pauseButton = PauseButton({windowSize.x - btnSize.x - 10, 65},btnSize);

	// init the level indicator
	sf::Vector2f size = VisualObjectSettings::getLevelIndicatorSize();
	sf::Vector2f pos = { windowSize.x - size.x - 10 , 10 };
	m_levelIndicator = LevelIndicator(pos);

	// init the clock indicator
	pos.y += size.y + 10;
	m_clock = Clock(pos);

	// init player2 dynamite indicator
	pos = PlayerSettings::getPlayer2Pos();
	pos.x += 75;
	pos.y += 15;
	m_player2Dynamite = DynamiteIndicator(pos);

	// init player1 dynamite indicator
	pos = PlayerSettings::getPlayer1Pos();
	pos.x += 75;
	pos.y += 15;
	m_player1Dynamite = DynamiteIndicator(pos);

	// init player2 score indicator
	pos = PlayerSettings::getPlayer2Pos();
	pos.x -= 30;
	pos.y -= 20;
	m_player2Score = Score(pos);

	// init player1 score indicator
	pos = PlayerSettings::getPlayer1Pos();
	pos.x -= 30;
	pos.y -= 20;
	m_player1Score = Score(pos);
}

//=============================================================================
void ToolBar::draw(sf::RenderWindow & window)
{
	m_pauseButton.draw(window);
	m_levelIndicator.draw(window);
	m_clock.draw(window);
	m_player2Dynamite.draw(window);
	m_player1Dynamite.draw(window);
	m_player2Score.draw(window);
	m_player1Score.draw(window);
}

//=============================================================================
void ToolBar::hover(const sf::Vector2f & point)
{
	m_pauseButton.hover(point);
}

//=============================================================================
const std::type_info & ToolBar::click(const sf::Vector2f & point)
{
	return m_pauseButton.click(point);
}

//=============================================================================
void ToolBar::initToolBar(int lvl)
{
	m_levelIndicator.setLevel(lvl);
}

//=============================================================================
void ToolBar::updateToolbar(float time,  int Player1Score, int Player2Score,int numOfPlayer1Dynamites, int numOfPlayer2Dynamites)
{
	m_player1Score.setScore(Player1Score);
	m_player2Score.setScore(Player2Score);
	m_clock.setTime(time);
	m_player1Dynamite.setNumOfDynamites(numOfPlayer1Dynamites);
	m_player2Dynamite.setNumOfDynamites(numOfPlayer2Dynamites);
}