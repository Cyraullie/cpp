# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 14:59:43 by cgoldens          #+#    #+#              #
#    Updated: 2025/05/07 15:10:12 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf

SRCS = megaphone.cpp

OBJS = $(SRCS:.c=.o)

GREEN = \033[1;32m
CYAN = \033[1;36m
YELLOW = \033[1;33m
RESET = \033[0m

# Règles
all: header $(NAME)

header:
	@echo "$(GREEN)"
	@echo "   __________  ____  ____  ____        _______  ______ ___ "
	@echo "  / ____/ __ \/ __ \/ __ \/ __ \      / ____/ |/ / __ \\__ \\"
	@echo " / /   / /_/ / /_/ / / / / / / /_____/ __/  |   / / / /_/ /"
	@echo "/ /___/ ____/ ____/ /_/ / /_/ /_____/ /___ /   / /_/ / __/ "
	@echo "\____/_/   /_/    \____/\____/     /_____//_/|_\____/____/ "
	@echo "                                                           "
	@echo "BY CGOLDENS"
	@echo "$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -I ./ -c -o $@ $<

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(CYAN)Build completed!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(MAKE) clean -s -C $(LIBFT_PATH) 
	$(RM) $(OBJS)

fclean: clean
	@echo "$(YELLOW)Cleaning $(NAME) binary
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
