// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Object.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tkiselev <tkiselev@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:03:30 by tkiselev          #+#    #+#             //
//   Updated: 2018/10/07 22:04:17 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Object.hpp"

Object::Object()
{}

Object::Object(int x, int y, char symbol)
{
	this->x = x;
	this->y = y;
	this->symbol = symbol;
}

Object::Object(Object const& other)
{
	*this = other;
}

Object::~Object()
{}

Object & Object::operator=(Object const& other)
{
	this->setX(other.getX());
	this->setY(other.getY());
	this->setSymbol(other.getSymbol());
	return *this;
}

char Object::getSymbol() const
{
	return this->symbol;
}

int Object::getX() const
{
	return this->x;
}

int Object::getY() const
{
	return this->y;
}

void	Object::setX(int val)
{
	this->x = val;
}

void	Object::setY(int val)
{
	this->y = val;
}

void	Object::setSymbol(char symbol)
{
	this->symbol = symbol;
}

void	Object::attack()
{}

void	Object::checkCollision(Object const& other)
{
	if (this == &other)
		return ;
}

void	Object::move(int xChange, int yChange)
{
	if (this->x == 1 && xChange == -1)
		return ;
	else if (this->x == Model::getWindowWidth() - 2 && xChange == 1)
		return ;
	else if (this->y == 1 && yChange == -1)
		return ;
	else if (this->y == Model::getWindowHeight() - 2 && yChange == 1)
		return ;
	this->x += xChange;
	this->y += yChange;
}
