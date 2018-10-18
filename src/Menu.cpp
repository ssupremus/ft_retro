// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Menu.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tkiselev <tkiselev@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:05:15 by tkiselev          #+#    #+#             //
//   Updated: 2018/10/07 22:05:36 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Menu.hpp"

std::string			*Menu::getItems() const
{
	return (this->_items);
}

int					Menu::getItemsSize() const
{
	return (this->_itemsSize);
}

int					Menu::getCurrent() const
{
	return (this->_current);
}

WINDOW*					Menu::getWin() const
{
	return (this->_win);
}

Menu::Menu()
:	_current(0), _itemsSize(0)
{}

Menu::Menu(Menu const& other)
{
	*this = other;
}

Menu::~Menu()
{}

Menu & Menu::operator=(Menu const& other)
{
	this->_items = other.getItems();
	this->_itemsSize = other.getItemsSize();
	this->_current = other.getCurrent();
	return *this;
}

Menu & Menu::operator++()
{
	this->_current++;
	if (this->getCurrent() == this->getItemsSize())
		this->_current = 0;
	return (*this);
}

Menu & Menu::operator--()
{
	this->_current--;
	if (this->getCurrent() < 0)
		this->_current = this->getItemsSize() - 1;
	return (*this);
}

Menu Menu::operator++(int)
{
	Menu tmp(*this);
	this->_current++;
	if (this->getCurrent() == this->getItemsSize())
		this->_current = 0;
	return (tmp);
}

Menu Menu::operator--(int)
{
	Menu tmp(*this);
	this->_current--;
	if (this->getCurrent() < 0)
		this->_current = this->getItemsSize() - 1;
	return (tmp);
}

std::string const& Menu::getChoice() const
{
	return (this->getItems()[this->getCurrent()]);
}

void				Menu::setItems(std::string *items, int size)
{
	this->_items = items;
	this->_itemsSize = size;
	this->_current = 0;
}

void			Menu::show()
{
	int x = Model::getWindowWidth() / 2;
	int y = Model::getWindowHeight() / 2;
	int i = 0;

	wattron(View::win, COLOR_PAIR(10));
	while (i < this->getItemsSize())
	{
		if (i == this->getCurrent())
			mvwprintw(View::win, y, x - 2, "> ");
		mvwprintw(View::win, y++, x, this->getItems()[i].c_str());
		i++;
	}
	wattroff(View::win, COLOR_PAIR(10));
	wrefresh(View::win);
}
