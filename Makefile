#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysushkov <ysushkov@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/07 21:22:44 by ysushkov          #+#    #+#              #
#    Updated: 2018/10/07 21:39:14 by ysushkov         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =	ft_retro

CC =	clang++

FLAGS =	-Wall -Wextra -Werror

SRC =	src/main.cpp src/Bullet.cpp src/Enemy.cpp src/Menu.cpp src/Model.cpp \
		src/Object.cpp src/Player.cpp src/View.cpp

LIB =	-lncurses

OBJ =	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIB)
			@echo "\033[92mDONE\033[0m"
$(OBJ):		%.o: %.cpp
			$(CC) $(FLAGS) -c $< -o $@

clean:
			@/bin/rm -f $(OBJ)
			@echo "\033[92mObject files have been deleted\033[0m"
fclean:		clean
			@/bin/rm -f $(NAME)
			@echo "\033[92mExecutables have been deleted\033[0m"

re:			fclean all

.PHONY:		all clean fclean re
