# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 14:11:51 by faikhan           #+#    #+#              #
#    Updated: 2025/01/24 16:09:44 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fract-ol
CC			= cc
RM			= rm -f
CFLAGS		= -g -Wall -Werror -Wextra -I./minilibx-linux
LDFLAGS		= -L./minilibx-linux -lX11 -lmlx -lXext -lm
MLX_DIR		= ./minilibx-linux

SRCS		= error.c helper.c image.c julia.c mandelbrot.c mlx.c main.c triangle.c

OBJS		= $(SRCS:.c=.o)

${NAME}		: ${OBJS} 
			@make -C $(MLX_DIR)
			${CC} ${OBJS} ${LDFLAGS} -o ${NAME}
all			: ${NAME}
clean		: 
			${RM} ${OBJS}
			@cd $(MLX_DIR) && $(MAKE) clean
fclean		: clean
			${RM} ${NAME}
			@cd $(MLX_DIR) && $(MAKE) clean
re			: fclean all

.PHONY		: all clean fclean re
