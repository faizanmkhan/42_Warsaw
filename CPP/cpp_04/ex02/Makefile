# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/31 00:25:47 by faikhan           #+#    #+#              #
#    Updated: 2026/01/01 16:48:40 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= absClass
SRCS	= main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
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