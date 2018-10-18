// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Enemy.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ysushkov <ysushkov@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:01:19 by ysushkov          #+#    #+#             //
//   Updated: 2018/10/07 22:01:31 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef ENEMY_HPP
# define ENEMY_HPP

# define COUNT_ENEMIES 20

#include <iostream>
#include "Object.hpp"
#include "Bullet.hpp"

class Enemy : public Object
{
	bool	_active;
	Bullet	_bullets[COUNT_BULLETS];
public:
	Enemy();
	Enemy(int x, int y, char symbol);
	Enemy(Enemy const& other);
	Enemy & operator=(Enemy const& other);
	~Enemy();
	void	checkCollision(Object const& other);


	void	activate();
	void	deactivate();

	void	attack();
	bool	isActive() const;
	Bullet	& getBullet(int i);
};

#endif
