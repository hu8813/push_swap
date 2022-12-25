# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/23 22:14:00 by huaydin           #+#    #+#              #
#    Updated: 2022/12/25 15:38:09 by huaydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g 
LIBFT_DIR = libft
RM = rm -rf
SRCS = utils.c move.c sort.c main.c
SRC	= $(addprefix ./src/,$(SRCS))
OBJ = $(SRC:.c=.o)

all: $(NAME) 
	@$(RM) src/*.o
	@echo "Done!"
	@echo "To test the program, run 'make test' or 'make test size=10'"
	@echo "for example for testing 10 random numbers"
	@echo "./push_swap 1 2 3 4 5 6 7 8 9 10"

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFT_DIR) -lft

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $? -I./$(LIBFT_DIR)
	@mv *.o src

$(LIBFT):
	make -s -C $(LIBFT_DIR) 

clean:	
	@$(RM) src/*.o

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all clean

.PHONY: all clean fclean test re

OS = $(shell uname)

size ?= 10

ifeq ($(OS),Linux)
CHECKER = valgrind ./push_swap $(ARG) | ./checker_linux $(ARG)
else
CHECKER = ./push_swap $(ARG) | ./checker_Mac $(ARG)
endif

test:
	@$(eval ARG = $(shell shuf -i 0-500 -n $(size)))
	@echo "Checker result: "
	$(CHECKER)
	@echo "Instructions count: "
	@./push_swap $(ARG) | wc -l