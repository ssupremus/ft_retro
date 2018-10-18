// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   View.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ysushkov <ysushkov@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:06:51 by ysushkov          #+#    #+#             //
//   Updated: 2018/10/07 22:06:53 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "View.hpp"

WINDOW *View::win = NULL;

View::View()
{}

View::View(View const& other)
{
	*this = other;
}

View & View::operator=(View const& other)
{
	this->win = other.win;
	return (*this);
}

View::~View()
{}

void View::init()
{
	initscr();
	noecho();
	keypad(stdscr, true);
	start_color();
	curs_set(0);
	clear();
	refresh();
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_CYAN, COLOR_CYAN);
	init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
	init_pair(10, COLOR_GREEN, COLOR_BLACK);
	init_pair(20, COLOR_GREEN, COLOR_BLACK);
	init_pair(21, COLOR_RED, COLOR_BLACK);
	init_pair(22, COLOR_YELLOW, COLOR_BLACK);
	init_pair(23, COLOR_GREEN, COLOR_BLACK);
	init_pair(24, COLOR_BLUE, COLOR_BLACK);
}

void View::end()
{
	endwin();
}

void	View::showLayout()
{
	char	c = '*';
	int		randomColor = rand() % 5 + 1;

	if (View::win)
		delwin(View::win);

	View::win = newwin(Model::getWindowHeight(), Model::getWindowWidth(), 0, 0);
	wattron(View::win, COLOR_PAIR(randomColor));
	wborder(View::win, c, c, c, c, c, c, c, c);
	wattroff(View::win, COLOR_PAIR(randomColor));
	wrefresh(View::win);
	refresh();
}

void	View::showLogo()
{
	int x = (Model::getWindowWidth() / 2) - 33;
	int randNum = rand() % 5 + 20;
	wattron(View::win, COLOR_PAIR(randNum));
	mvwprintw(View::win, 10, x, " _______ _________   _______  _______ _________ _______  _______ ");
	mvwprintw(View::win, 11, x, "(  ____ \\__   __/  (  ____ )(  ____ \\__   __/(  ____ )(  ___  )");
	mvwprintw(View::win, 12, x, "| (    \\/   ) (     | (    )|| (    \\/   ) (   | (    )|| (   ) |");
	mvwprintw(View::win, 13, x, "| (__       | |     | (____)|| (__       | |   | (____)|| |   | |");
	mvwprintw(View::win, 14, x, "|  __)      | |     |     __)|  __)      | |   |     __)| |   | |");
	mvwprintw(View::win, 15, x, "| (         | |     | (\\ (   | (         | |   | (\\ (   | |   | |");
	mvwprintw(View::win, 16, x, "| )         | |     | ) \\ \\__| (____/\\   | |   | ) \\ \\__| (___) |");
	mvwprintw(View::win, 17, x, "|/          )_(_____|/   \\__/(_______/   )_(   |/   \\__/(_______)");
	mvwprintw(View::win, 18, x, "              (_____)                                            ");
	wrefresh(View::win);
	wattroff(View::win, COLOR_PAIR(randNum));
}

void	View::showInitScreen()
{
	Menu		menu;
	std::string	mainMenu[] = {"Start game", "Exit"};
	std::string	levelsMenu[] = {"Easy", "Medium", "Hard"};
	std::string	choice = "";
	int		c;
	clock_t start = clock();

	menu.setItems(mainMenu, sizeof(mainMenu) / sizeof(mainMenu[0]));
	nodelay(stdscr, true);
	while (choice == "")
	{
		if ((clock() - start) % 10000 == 0)
		{
			View::showLayout();
			View::showLogo();
		}
		menu.show();
		c = getch();
		switch (c)
		{
			case KEY_UP:
				menu--;
				View::showLayout();
				View::showLogo();
				break ;
			case KEY_DOWN:
				menu++;
				View::showLayout();
				View::showLogo();
				break ;
			case 10:
				choice = menu.getChoice();
				break ;
		}
	}
	if (choice == mainMenu[1])	//	EXIT
	{
		View::end();
		std::cout << "Bye !" << std::endl;
		exit(0);
	}
	choice = "";
	menu.setItems(levelsMenu, sizeof(levelsMenu) / sizeof(levelsMenu[0]));
	while (choice == "")
	{
		if ((clock() - start) % 10000 == 0)
		{
			View::showLayout();
			View::showLogo();
		}
		menu.show();
		c = getch();
		switch (c)
		{
			case KEY_UP:
				menu--;
				View::showLayout();
				View::showLogo();
				break ;
			case KEY_DOWN:
				menu++;
				View::showLayout();
				View::showLogo();
				break ;
			case 10:
				choice = menu.getChoice();
				break ;
		}
	}

	if (choice == levelsMenu[2])		//	hard
		Model::speed = 100;
	else if (choice == levelsMenu[1])	//	medium
		Model::speed = 500;
	else								//	easy
		Model::speed = 1000;
}

void	View::showObject(Player * elem)
{
	int randNum = rand() % 5 + 20;
	wattron(View::win, COLOR_PAIR(randNum));
	mvwaddch(View::win, elem->getY(), elem->getX(), elem->getSymbol());

	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		if (elem->getBullet(i).getX() >= 0)
		{
			mvwaddch(View::win, elem->getBullet(i).getY(), elem->getBullet(i).getX(), elem->getBullet(i).getSymbol());
		}
	}
	wattroff(View::win, COLOR_PAIR(randNum));
	wrefresh(View::win);
	refresh();
}

void	View::showObject(Enemy * elem)
{
	int randNum = rand() % 5 + 20;
	wattron(View::win, COLOR_PAIR(randNum));
	mvwaddch(View::win, elem->getY(), elem->getX(), elem->getSymbol());

	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		if (elem->getBullet(i).getX() > 0)
		{
			mvwaddch(View::win, elem->getBullet(i).getY(), elem->getBullet(i).getX(), elem->getBullet(i).getSymbol());
		}
	}
	wattroff(View::win, COLOR_PAIR(randNum));
	wrefresh(View::win);
	refresh();
}

void	View::showScore(Player * player)
{
	int i;
	int j;

	mvwprintw(View::win, 1, 1, "Score: %3d", player->getScore());
	mvwprintw(View::win, 2, 1, "HP: %3d", player->getHP());
	j = 0;
	for (i = COUNT_BULLETS - 1; i >= 0; i--)
	{
		if (player->getBullet(i).getX() < 0)
			wattron(View::win, COLOR_PAIR(23));
		else
			wattron(View::win, COLOR_PAIR(21));
		mvwaddch(View::win, 3, j + 2, '!');
		wattroff(View::win, COLOR_PAIR(23));
		wattroff(View::win, COLOR_PAIR(21));
		j += 2;
	}
}

void	View::cleanWindow(Player * elem)
{
	mvwaddch(View::win, elem->getY(), elem->getX(), ' ');
	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		if (elem->getBullet(i).getX() > 0)
			mvwaddch(View::win, elem->getBullet(i).getY(), elem->getBullet(i).getX(), ' ');
	}
}

void	View::cleanWindow(Enemy * elem)
{
	mvwaddch(View::win, elem->getY(), elem->getX(), ' ');
	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		if (elem->getBullet(i).getX() > 0)
			mvwaddch(View::win, elem->getBullet(i).getY(), elem->getBullet(i).getX(), ' ');
	}
}
