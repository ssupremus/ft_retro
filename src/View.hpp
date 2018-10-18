// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   View.hpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ysushkov <ysushkov@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:06:59 by ysushkov          #+#    #+#             //
//   Updated: 2018/10/07 22:06:59 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef VIEW_HPP
# define VIEW_HPP

# define RESIZE 410

#include "Player.hpp"
#include "Enemy.hpp"
#include "Object.hpp"
#include "Model.hpp"
#include "Bullet.hpp"
#include "Menu.hpp"
#include <ncurses.h>

class View
{
	View();
	View(View const& other);
	View & operator=(View const& other);
	~View();
public:
	static WINDOW *win;
	static void	init();
	static void	end();
	static void	showLayout();
	static void	redrawLayout();
	static void	showLogo();
	static void	showInitScreen();
	static void	showObject(Player * elem);
	static void	showObject(Enemy * elem);
	static void	showScore(Player * player);
	static void	cleanWindow(Player * elem);
	static void	cleanWindow(Enemy * elem);
};

#endif
