# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/04 01:10:10 by faikhan           #+#    #+#              #
#    Updated: 2024/11/06 17:28:00 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf_helper.c ft_printf.c
OBJS	=	$(SRCS:.c=.o)
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			ar crs $(NAME) $(OBJS)

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
