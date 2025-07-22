# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/07 14:59:43 by cgoldens          #+#    #+#              #
#    Updated: 2025/07/22 14:01:02 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -MMD
RM = rm -rf

SRCS = Contact.cpp PhoneBook.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

GREEN = \033[1;32m
CYAN = \033[1;36m
YELLOW = \033[1;33m
RESET = \033[0m

# Règles
all: header $(NAME)

header:
	@echo "$(GREEN)"
	@echo "   __________  ____  ____  ____        _______  ______ ___"
	@echo "  / ____/ __ \/ __ \/ __ \/ __ \      / ____/ |/ / __ <  /"
	@echo " / /   / /_/ / /_/ / / / / / / /_____/ __/  |   / / / / / "
	@echo "/ /___/ ____/ ____/ /_/ / /_/ /_____/ /___ /   / /_/ / /  "
	@echo "\____/_/   /_/    \____/\____/     /_____//_/|_\____/_/   "
	@echo "                                                          "
	@echo "BY CGOLDENS"
	@echo "$(RESET)"

%.o: %.cpp
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(CYAN)Build completed!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(RM) $(OBJS)

fclean: clean
	@echo "$(YELLOW)Cleaning $(NAME) binary"
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
