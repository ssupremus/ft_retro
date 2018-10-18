// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ysushkov <ysushkov@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:00:55 by ysushkov          #+#    #+#             //
//   Updated: 2018/10/07 22:01:09 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Enemy.hpp"
#include "Player.hpp"

Enemy::Enemy()
:	Object(Model::getWindowWidth() - 1, 0, '<'), _active(false)
{
	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		this->getBullet(i).setX(-1);
		this->getBullet(i).setY(-1);
		this->getBullet(i).setSymbol('o');
	}
}

Enemy::Enemy(int x, int y, char symbol)
:	Object(x, y, symbol), _active(false)
{
	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		this->getBullet(i).setX(-1);
		this->getBullet(i).setY(-1);
		this->getBullet(i).setSymbol('o');
	}
}

Enemy::Enemy(Enemy const& other)
{
	*this = other;
}

Enemy & Enemy::operator=(Enemy const& other)
{
	this->_active = other.isActive();
	return *this;
}

Enemy::~Enemy()
{}

void	Enemy::attack()
{
	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		if (this->getBullet(i).getX() < 0)
		{
			this->getBullet(i).setX(this->getX() - 1);
			this->getBullet(i).setY(this->getY());
			return ;
		}
	}
}

void	Enemy::activate()
{
	this->_active = true;
	this->y = (rand() % (Model::getWindowHeight() - 2)) + 1;
	this->x = Model::getWindowWidth() - 2;
}

void	Enemy::deactivate()
{
	this->_active = false;
}

bool	Enemy::isActive() const
{
	return (this->_active);
}

Bullet	& Enemy::getBullet(int i)
{
	return (this->_bullets[i]);
}

void	Enemy::checkCollision(Object const& other)
{
	Player *tmp = (Player *)&other;

	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		if (this->getX() == tmp->getBullet(i).getX() && this->getY() == tmp->getBullet(i).getY())
		{
			this->deactivate();
			tmp->setScore(tmp->getScore() + 10);
		}
	}
}
