// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Model.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ysushkov <ysushkov@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:06:19 by ysushkov          #+#    #+#             //
//   Updated: 2018/10/07 22:06:23 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Model.hpp"

int Model::speed = 0;

Model::Model()
{}

Model::Model(Model const& other)
{
	*this = other;
}

Model & Model::operator=(Model const& other)
{
	this->speed = other.speed;
	return (*this);
}

int Model::getWindowWidth()
{
	struct winsize size;
	ioctl(0,TIOCGWINSZ,&size);

	return (size.ws_col);
}

int Model::getWindowHeight()
{
	struct winsize size;
	ioctl(0,TIOCGWINSZ,&size);

	return (size.ws_row);
}
