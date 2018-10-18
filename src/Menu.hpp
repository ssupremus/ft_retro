// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Menu.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tkiselev <tkiselev@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:05:44 by tkiselev          #+#    #+#             //
//   Updated: 2018/10/07 22:06:07 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MENU_HPP
# define MENU_HPP

#include <ncurses.h>
#include "Model.hpp"
#include "View.hpp"
#include <iostream>

class Menu
{
private:
	int				_current;
	int				_itemsSize;
	std::string		*_items;
	WINDOW			*_win;

public:
	Menu();
	Menu(Menu const& other);
	~Menu();
	Menu & operator=(Menu const& other);

	Menu &	operator++();
	Menu &	operator--();
	Menu 	operator++(int);
	Menu 	operator--(int);

	WINDOW				*getWin() const;
	std::string const&	getChoice() const;
	std::string			*getItems() const;
	int					getItemsSize() const;
	int					getCurrent() const;
	void				setItems(std::string *items, int size);

	void				show();
};

#endif
