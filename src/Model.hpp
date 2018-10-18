// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Model.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ysushkov <ysushkov@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/07 22:06:28 by ysushkov          #+#    #+#             //
//   Updated: 2018/10/07 22:06:31 by ysushkov         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef MODEL_HPP
# define MODEL_HPP

#include <unistd.h>
#include <sys/ioctl.h>
#include "Object.hpp"

class Model
{
public:
	static int speed;
	Model();
	Model(Model const& other);
	~Model();
	Model & operator=(Model const& other);
	static int getWindowHeight();
	static int getWindowWidth();
};

#endif
