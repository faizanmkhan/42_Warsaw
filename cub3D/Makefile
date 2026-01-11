# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/04 22:27:19 by faikhan           #+#    #+#              #
#    Updated: 2025/12/06 13:50:38 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

NAME		= cub3D
CC			= cc
RM			= rm -f
CFLAGS		= -g -Wall -Werror -Wextra -I./inc -I./mlx
LDFLAGS		= -L./mlx -lmlx -L./libft -lft -lX11 -lXext -lm
MLX_DIR		= ./mlx
LIBFT_DIR	= ./libft

SRCS		= src/engine/main.c \
			  src/engine/init.c \
			  src/engine/init_helper.c \
			  src/engine/movement.c \
			  src/engine/movement_direction.c \
			  src/parser/parse_map.c \
			  src/parser/parse_map_alloc.c \
			  src/parser/parse_map_alloc_helper.c \
			  src/parser/parse_map_helpers.c \
			  src/parser/parse_map_helpers2.c \
			  src/parser/parse_map_pctx.c \
			  src/parser/parse_pctx_helper.c \
			  src/parser/parse_map_texture.c \
			  src/parser/parse_map_flood.c \
			  src/parser/parse_flood_helper.c \
			  src/renderer/renderer.c \
			  src/renderer/renderer_draw.c \
			  src/renderer/renderer_draw_helper.c \
			  src/renderer/renderer_draw_helper2.c \
			  src/renderer/renderer_ray.c \
			  src/renderer/renderer_ray_helper.c

OBJS		= $(SRCS:.c=.o)

${NAME}		: ${OBJS}
			@make -C $(MLX_DIR)
			@make -C $(LIBFT_DIR)
			${CC} ${OBJS} ${LDFLAGS} -o ${NAME}

all			: ${NAME}

clean		: 
			${RM} ${OBJS}
			@cd $(MLX_DIR) && $(MAKE) clean
			@cd $(LIBFT_DIR) && $(MAKE) clean

fclean		: clean
			${RM} ${NAME}
			@cd $(MLX_DIR) && $(MAKE) clean
			@cd $(LIBFT_DIR) && $(MAKE) fclean

re			: fclean all

.PHONY		: all clean fclean re

