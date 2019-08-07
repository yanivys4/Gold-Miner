#include "Menu.h"

//=============================================================================
Menu::Menu(const sf::Vector2f & windowSize)
	:m_background(windowSize)
{
}

//=============================================================================
void Menu::hover(const sf::Vector2f & point)
{
	for (auto &btn : m_buttons)
	{
		btn->hover(point);
	}
}

//=============================================================================
const std::type_info & Menu::click(const sf::Vector2f & point)
{
	for (auto &btn : m_buttons)
	{
		const std::type_info &type = btn->click(point);
		if (type.name() != (typeid(NULL)).name())
			return type;
	}

	return typeid(NULL);
}
