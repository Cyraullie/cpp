# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 17:17:10 by cgoldens          #+#    #+#              #
#    Updated: 2025/10/24 13:57:18 by cgoldens         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Array

SRCDIR = ./
INCDIR = ./
OBJDIR = ./build/

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = $(shell find $(SRCDIR) -type f -name "*.cpp")
OBJS = $(SRCS:$(SRCDIR)%.cpp=$(OBJDIR)%.o)

GREEN = \033[1;32m
CYAN = \033[1;36m
YELLOW = \033[1;33m
RESET = \033[0m

# Règles
all: header $(NAME)

header:
	@echo "$(GREEN)"
	@echo "   __________  ____  ____  _____      _______  ______ ___ "
	@echo "  / ____/ __ \\/ __ \\/ __ \\/__  /     / ____/ |/ / __ \\__ \\"
	@echo " / /   / /_/ / /_/ / / / /  / /_____/ __/  |   / / / /_/ /"
	@echo "/ /___/ ____/ ____/ /_/ /  / /_____/ /___ /   / /_/ / __/ "
	@echo "\\____/_/   /_/    \\____/  /_/     /_____//_/|_\\____/____/ "
	@echo "                                                          "
	@echo "BY CGOLDENS"
	@echo "$(RESET)"

${OBJDIR}%.o: $(SRCDIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -I$(INCDIR) -c -o $@ $<

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(CYAN)Build completed!$(RESET)"

clean:
	@echo "$(YELLOW)Cleaning object files...$(RESET)"
	$(RM) $(OBJS)
	$(RM) $(OBJDIR)

fclean: clean
	@echo "$(YELLOW)Cleaning $(NAME) binary$(RESET)"
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re
