// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Object.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tkiselev <tkiselev@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:04:30 by tkiselev          #+#    #+#             //
//   Updated: 2018/10/07 22:05:01 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef OBJECT_HPP
# define OBJECT_HPP

#include "Model.hpp"

class Object
{
protected:
	char	symbol;
	int		x;
	int 	y;
public:
	Object();
	Object(int x, int y, char symbol);
	Object(Object const& other);
	Object & operator=(Object const& other);
	virtual ~Object();
	virtual void attack();
	virtual void	checkCollision(Object const& other);

	void	move(int x, int y);

	char	getSymbol() const;
	int		getX() const;
	int		getY() const;
	void	setSymbol(char val);
	void	setX(int val);
	void	setY(int val);
};

#endif
