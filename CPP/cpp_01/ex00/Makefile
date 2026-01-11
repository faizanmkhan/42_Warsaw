# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/10 01:05:14 by faikhan           #+#    #+#              #
#    Updated: 2025/12/21 23:59:47 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	BraiiiiiiinnnzzzZ
SRCS	=	Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJS	=	$(SRCS:.cpp=.o)
CC		=	c++
CFLAGS	=	-g3 -Wall -Werror -Wextra -std=c++98 -fsanitize=address
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re