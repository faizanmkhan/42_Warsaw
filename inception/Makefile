# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/27 22:08:17 by faikhan           #+#    #+#              #
#    Updated: 2026/06/29 14:02:24 by faikhan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR    := <your actual compose dir>
COMPOSE     := $(SRCS_DIR)/docker-compose.yml
ENV_FILE    := $(SRCS_DIR)/.env
COMPOSE_CMD := docker compose -f $(COMPOSE) --env-file $(ENV_FILE)

include $(ENV_FILE)
export

DATA_DIR    := /home/$(LOGIN)/data

all: data-dirs up

data-dirs:
	@mkdir -p $(DATA_DIR)/mariadb
	@mkdir -p $(DATA_DIR)/wordpress
	@mkdir -p $(DATA_DIR)/redis

build: data-dirs
	$(COMPOSE_CMD) build

up: data-dirs
	$(COMPOSE_CMD) up -d --build

down:
	$(COMPOSE_CMD) down

start:
	$(COMPOSE_CMD) start

stop:
	$(COMPOSE_CMD) stop

restart: down up

logs:
	$(COMPOSE_CMD) logs -f

ps: status

status:
	$(COMPOSE_CMD) ps

clean: down
	@docker system prune -f

fclean:
	$(COMPOSE_CMD) down -v --rmi all --remove-orphans
	@if [ -d "$(DATA_DIR)" ]; then \
		echo "Removing $(DATA_DIR) (you may be prompted for your password)..."; \
		sudo rm -rf "$(DATA_DIR)"; \
	fi
	@docker network prune -f

re: fclean all

help:
	@echo "Inception Makefile targets:"
	@echo "  make / make all - prepare data dirs and start everything (build if needed)"
	@echo "  make build      - build all images without starting them"
	@echo "  make up         - create data dirs, then build+start all containers"
	@echo "  make down       - stop and remove containers (volumes are kept)"
	@echo "  make start/stop - start/stop existing containers without rebuilding"
	@echo "  make restart    - down then up"
	@echo "  make logs       - follow logs of all services"
	@echo "  make ps/status  - list container status"
	@echo "  make clean      - down + prune dangling docker resources"
	@echo "  make fclean     - clean + wipe images/volumes + wipe \$$DATA_DIR"
	@echo "  make re         - fclean then all"

.PHONY: all build up down start stop restart logs ps status data-dirs clean fclean re help
