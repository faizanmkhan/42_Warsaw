# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/27 01:08:32 by faikhan           #+#    #+#              #
#    Updated: 2025/12/28 13:29:08 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= OPEN
SRCS	= main.cpp ClapTrap.cpp
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
