#include "Board.h"

//=============================================================================
Board::Board()
{
}

//=============================================================================
void Board::initBoard(std::ifstream & levelFile)
{
	m_board.clear();
	
	sf::Vector2f position;
	char kindOfObject;
	for (size_t row = 0; row < BoardSettings::getBoardSize().x; ++row)
	{
		position.y = BoardSettings::getBasePos().y + (row * BoardSettings::getSmallSize().y);
		for (size_t col = 0; col < BoardSettings::getBoardSize().y; ++col)
		{
			position.x = BoardSettings::getBasePos().x + (col * BoardSettings::getSmallSize().x);
			levelFile.get(kindOfObject);
			auto ptr = Factory::create(kindOfObject, position);
			if (ptr)
			{
				ptr = setSizeOfRock(kindOfObject, std::move(ptr)); // if the object is not regular or golden rock nothing happens
				m_board.push_back(std::move(ptr));
			}

		}

		levelFile.get(kindOfObject); // for /n
	}
}

//=============================================================================
void Board::draw(sf::RenderWindow & window)
{
	for (auto & object : m_board)
	{
		object->draw(window);
	}
}

//=============================================================================
BoardObject * Board::checkCollision(const sf::FloatRect & rect) // !!!!!!!!!!!!!!!!!!!!!!!!!!!! cange put pointr outside
{
	for (size_t i = 0; i < m_board.size(); ++i)
	{
		if (m_board[i]->isIntersect(rect) && !m_board[i]->IsGrabed() && !m_board[i]->IsExplode())
		{
			return (m_board[i].get());
		}
	}

	return nullptr;
}

//=============================================================================
void Board::updateBoard()
{
	std::experimental::erase_if(m_board, [](const std::unique_ptr <BoardObject> & object)
	{
		return object->isOutOfGame();

	});
}

//=============================================================================
std::unique_ptr<BoardObject> Board::setSizeOfRock(char kind, std::unique_ptr<BoardObject> ptr)
{
	if (dynamic_cast<RegularRock *>(ptr.get())) // the object entered is regularRock
	{

		RegularRock * p = (RegularRock *)ptr.get(); // sure cast after check
		switch (kind)
		{
		case '1':
			p->setRockSize(BoardSettings::getSmallSize());
			break;
		case '2':
			p->setRockSize(BoardSettings::getRegularSize());
			break;
		case '3':
			p->setRockSize(BoardSettings::getBigSize());
			break;
		}
	}
	if (dynamic_cast<GoldenRock *>(ptr.get())) // the object entered is GoldenRock
	{

		GoldenRock * p = (GoldenRock *)ptr.get(); // sure cast after check
		switch (kind)
		{
		case '4':
			p->setRockSize(BoardSettings::getSmallSize());
			break;
		case '5':
			p->setRockSize(BoardSettings::getRegularSize());
			break;
		case '6':
			p->setRockSize(BoardSettings::getBigSize());
			break;
		}
	}

	return std::move(ptr); // return the unique ptr as it is
}

//=============================================================================
int Board::getCollisionScore(const sf::FloatRect &rect)
{
	for (size_t i = 0; i < m_board.size(); ++i)
	{
		if (m_board[i].get()->isIntersect(rect) && !m_board[i]->IsGrabed() && !m_board[i]->IsExplode())
		{
				return m_board[i]->getScore();
		}
	}

	return -10;
}

//=============================================================================
void Board::barrelExplode(const sf::FloatRect &rect, float deltaTime)
{
	for (auto &object : m_board)
	{
		if (object->isIntersect(rect) && !(dynamic_cast<Barrel *>(object.get())))
		{
			object->prepareForExplosion();
			object->explode(deltaTime);
			object->activateExplodeMode();
		}
	}
}

//=============================================================================
void Board::removeBarrelExp()
{
	std::experimental::erase_if(m_board, [](const std::unique_ptr <BoardObject> & object)
	{
		return object->IsExplode();

	});
}

//=============================================================================
bool Board::isEmpty() const
{
	return (m_board.size() == 0);
}

//=============================================================================
size_t Board::getNumberOfObjects() const
{
	return m_board.size();
}
//=============================================================================