// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Bullet.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tkiselev <tkiselev@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:00:09 by tkiselev          #+#    #+#             //
//   Updated: 2018/10/07 22:00:37 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef BULLET_HPP
# define BULLET_HPP

# define COUNT_BULLETS 20

#include "Object.hpp"

class Bullet : public Object
{
public:
	Bullet();
	Bullet(int x, int y, char symbol);
	Bullet(Bullet const& other);
	Bullet & operator=(Bullet const& other);
	~Bullet();
};

#endif
