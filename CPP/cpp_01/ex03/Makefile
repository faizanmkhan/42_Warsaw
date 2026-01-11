# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/24 21:23:41 by faikhan           #+#    #+#              #
#    Updated: 2025/12/25 00:10:56 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= unnecessaryViolence
SRCS	= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJS	= $(SRCS:.cpp=.o)
CC		= c++
CFLAGS	= -g3 -Wall -Werror -Wextra -std=c++98 -fsanitize=address
RM		= rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		: fclean all

.PHONY	: all clean fclean re
