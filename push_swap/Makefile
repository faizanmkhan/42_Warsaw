# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 20:19:33 by faikhan           #+#    #+#              #
#    Updated: 2025/02/05 00:29:07 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
BONUS_NAME		= checker
CC				= cc
CFLAGS			= -g -Wall -Werror -Wextra
RM				= rm -f
NAME_SRCS		= push_swap.c
COMMON_SRCS		= p_s_atoi.c rotate_instruct.c utils.c ft_split.c quick_sort.c \
				push_instruct.c  sorting.c rev_rot_instruct.c swap_instruct.c
BONUS_SRCS		= checker.c get_next_line.c get_next_line_utils.c

NAME_OBJS		= ${NAME_SRCS:.c=.o}
COMMON_OBJS		= ${COMMON_SRCS:.c=.o}
BONUS_OBJS		= ${BONUS_SRCS:.c=.o}

all				: ${NAME}

${NAME}			: ${NAME_OBJS} ${COMMON_OBJS}
				${CC} ${CFLAGS} ${NAME_OBJS} ${COMMON_OBJS} -o ${NAME}

${BONUS_NAME}	: ${COMMON_OBJS} ${BONUS_OBJS}
				${CC} ${CFLAGS} ${COMMON_OBJS} ${BONUS_OBJS} -o ${BONUS_NAME}

bonus			: ${BONUS_NAME}

clean			:
				${RM} ${NAME_OBJS} ${COMMON_OBJS} ${BONUS_OBJS}

fclean			: clean
				${RM} ${NAME} ${BONUS_NAME}

re				: fclean all

.PHONY			: all clean fclean re bonus