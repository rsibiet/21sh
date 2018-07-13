# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mathou <mathou@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/10 10:00:41 by mressier          #+#    #+#              #
#    Updated: 2016/05/19 12:40:32 by mressier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_DIR =	srcs
C_DIRS = $(shell find $(C_DIR) -type d -follow -print)
C_FILES = $(shell find $(C_DIR) -type f -follow -print | grep "\.c")

O_DIR =	.tmp/obj
O_DIRS = $(C_DIRS:$(C_DIR)%=$(O_DIR)%)
O_FILES = $(C_FILES:$(C_DIR)%.c=$(O_DIR)%.o)

FLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes

all: $(NAME)

$(NAME): $(O_FILES)
	@ar rcs $@ $^
	@ranlib $@
	@echo "\\n\033[32;1m $(NAME) has successfully been created ღ \033[0;0m\\n"

$(O_DIR)%.o: $(C_DIR)%.c
	@tput civis
	@mkdir -p $(O_DIRS) $(O_DIR)
	@printf "\033[2K [ \033[32;1mcompiling $(NAME) \033[0m] $<\r"
	@gcc $(INCLUDES) $(FLAGS) -o $@ -c $<
	@tput cnorm

clean:
	@echo "\033[41m[Clean objects in $(NAME)]\033[0;0m\\n"
	@rm -rf $(O_DIR)

fclean: clean
	@echo "\033[44m[Delete $(NAME)]\033[0;0m\\n"
	@rm -rf $(NAME)
	@rm -rf .tmp/

re: fclean all
