#include "View.hpp"
#include "Object.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include <unistd.h>

void	clearEverything(Player *player, Enemy *enemies)
{
	View::cleanWindow(player);
	for (int i = 0; i < COUNT_ENEMIES; i++)
	{
		if (enemies[i].isActive())
			View::cleanWindow(&enemies[i]);
	}
}

void	playerController(Player * ship)
{
	int c = getch();

	switch(c)
	{
		case KEY_UP:
			ship->move(0, -1);
			break;
		case KEY_DOWN:
			ship->move(0, 1);
			break;
		case KEY_RIGHT:
			ship->move(1, 0);
			break;
		case KEY_LEFT:
			ship->move(-1, 0);
			break;
		case ' ':
			ship->attack();
			break;
		case 'q':
			ship->takeDamage(100);
	}
}

void	moveAllObjects(Player * player, Enemy *enemies)
{
	int i;
	int j;
	for (i = 0; i < COUNT_BULLETS; i++)
	{
		if (player->getBullet(i).getX() > 0 && player->getBullet(i).getX() < (Model::getWindowWidth() - 2))
			player->getBullet(i).setX(player->getBullet(i).getX() + 1);
		else
			player->getBullet(i).setX(-1);
	}
	for (i = 0; i < COUNT_ENEMIES; i++)
	{
		if (enemies[i].isActive())
		{
			if (enemies[i].getX() > 1)
			{
				enemies[i].setX(enemies[i].getX() - 1);
			}
			else
			{
				enemies[i].deactivate();
			}

			for (j = 0; j < COUNT_BULLETS; j++)
			{
				if (enemies[i].getBullet(j).getX() > 0)
					enemies[i].getBullet(j).setX(enemies[i].getBullet(j).getX() - 2);
			}
		}
	}
}

void	checkAllCollisions(Player * ship, Enemy * enemies)
{
	int i;

	for (i = 0; i < COUNT_ENEMIES; i++)
	{
		if (enemies[i].isActive())
			ship->checkCollision(enemies[i]);
	}
	for (i = 0; i < COUNT_ENEMIES; i++)
	{
		if (enemies[i].isActive())
			enemies[i].checkCollision(*ship);
	}
}

void	game()
{
	Player	*ship = new Player(1, Model::getWindowHeight() / 2, '>');
	Enemy	enemies[COUNT_ENEMIES];
	int		n = 0;

	View::showLayout();
	wrefresh(View::win);
	nodelay(stdscr, true);
	while (ship->getHP() > 0)
	{
		usleep(15000);
		clearEverything(ship, enemies);
		if (clock() % 100 == 0)
		{
			for (int i = 0; i < COUNT_ENEMIES; i++)
			{
				if (enemies[i].isActive())
					enemies[i].attack();
			}
		}
		if (clock() % 100 == 0)
		{
			enemies[n].activate();
			enemies[n].attack();
			n++;
			if (n == COUNT_ENEMIES)
				n = 0;
		}
		moveAllObjects(ship,enemies);
		playerController(ship);
		View::showObject(ship);
		checkAllCollisions(ship, enemies);
		for (int i = 0; i < COUNT_ENEMIES; i++)
		{
			if (enemies[i].isActive())
				View::showObject(&enemies[i]);
		}
		View::showScore(ship);
	}
	delete ship;
}

int main()
{
	srand(time(0));
	View::init();
	while (1)
	{
		View::showInitScreen();
		game();
	}
	View::end();
	return (0);
}
