# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 18:46:49 by faikhan           #+#    #+#              #
#    Updated: 2025/02/03 19:09:29 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME		= server
CLIENT_NAME		= client
CC				= cc
CFLAGS			= -g -Wall -Werror -Wextra

SERVER_SRC		= server.c
CLIENT_SRC		= client.c

SERVER_OBJ		= $(SERVER_SRC:.c=.o)
CLIENT_OBJ		= $(CLIENT_SRC:.c=.o)

all				: ${SERVER_NAME} ${CLIENT_NAME}

${SERVER_NAME}	: ${SERVER_OBJ}
				${CC} ${SERVER_OBJ} -o ${SERVER_NAME}
${CLIENT_NAME}	: ${CLIENT_OBJ}
				${CC} ${CLIENT_OBJ} -o ${CLIENT_NAME}

clean			:
				${RM} ${SERVER_OBJ} ${CLIENT_OBJ}
fclean			: clean
				${RM} ${SERVER_NAME} ${CLIENT_NAME}
re				: fclean all
bonus			: all

.PHONY			: all clean fclean re bonus