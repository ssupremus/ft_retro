// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Player.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: tkiselev <tkiselev@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:02:36 by tkiselev          #+#    #+#             //
//   Updated: 2018/10/07 22:03:04 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Object.hpp"
#include "Bullet.hpp"

class Player : public Object
{
	Bullet	_bullets[COUNT_BULLETS];
	int		_score;
	int		_HP;
	int		_HPMAX;
public:
	Player();
	Player(int x, int y, char symbol);
	Player(Player const& other);
	Player & operator=(Player const& other);
	~Player();
	void	checkCollision(Object const& other);

	void	takeDamage(int damage);
	void	attack();

	void setScore(int val);
	int getScore() const;
	int getHP() const;
	int getHPMAX() const;
	Bullet	& getBullet(int i);
};

#endif
