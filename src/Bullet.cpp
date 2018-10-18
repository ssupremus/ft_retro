// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.cpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tkiselev <tkiselev@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 21:58:52 by tkiselev          #+#    #+#             //
//   Updated: 2018/10/07 22:00:02 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Bullet.hpp"

Bullet::Bullet()
{}

Bullet::~Bullet()
{}

Bullet::Bullet(int x, int y, char symbol)
:	Object(x, y, symbol)
{}

Bullet::Bullet(Bullet const& other)
{
	*this = other;
}

Bullet & Bullet::operator=(Bullet const& other)
{
	this->x = other.x;
	this->y = other.y;
	this->symbol = other.symbol;
	return (*this);
}
