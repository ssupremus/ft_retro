// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tkiselev <tkiselev@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:02:02 by tkiselev          #+#    #+#             //
//   Updated: 2018/10/07 22:02:23 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Player.hpp"
#include "Enemy.hpp"

Player::Player()
{}

Player::Player(int x, int y, char symbol)
:	Object(x, y, symbol), _score(0), _HP(100), _HPMAX(100)
{
	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		this->getBullet(i).setX(-1);
		this->getBullet(i).setY(-1);
		this->getBullet(i).setSymbol('o');
	}
}

Player::Player(Player const& other)
{
	*this = other;
}

Player & Player::operator=(Player const& other)
{
	this->_score = other.getScore();
	this->_HP = other.getHP();
	this->_HPMAX = other.getHPMAX();
	return *this;
}

Player::~Player()
{}

void	Player::takeDamage(int damage)
{
	if (damage > this->getHP())
		this->_HP = 0;
	else
		this->_HP -= damage;
}

void	Player::attack()
{
	for (int i = 0; i < COUNT_BULLETS; i++)
	{
		if (this->getBullet(i).getX() < 0)
		{
			this->getBullet(i).setX(this->getX() + 1);
			this->getBullet(i).setY(this->getY());
			return ;
		}
	}
}

void		Player::setScore(int val)
{
	this->_score = val;
}

int		Player::getScore() const
{
	return this->_score;
}

int		Player::getHP() const
{
	return this->_HP;
}

int		Player::getHPMAX() const
{
	return this->_HPMAX;
}

Bullet & Player::getBullet(int i)
{
	return (this->_bullets[i]);
}

void	Player::checkCollision(Object const& other)
{
	Enemy *tmp = (Enemy *)&other;

	if (this->getX() == other.getX() && this->getY() == other.getY())
		this->takeDamage(this->getHPMAX());
	else
	{
		for (int i = 0; i < COUNT_BULLETS; i++)
		{
			if (this->getX() == tmp->getBullet(i).getX() && this->getY() == tmp->getBullet(i).getY())
				this->takeDamage(25);
		}
	}
}
