# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/08 22:15:49 by youkim            #+#    #+#              #
#    Updated: 2021/08/08 22:15:49 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft
LIBFT_PATH = ./$(LIBFT).a

CC = gcc
CFLAGS = #-Wall -Wextra -Werror
RM = rm -rf

DEBUG = gdb
DFLAGS = -g -ggdb
VFLAGS = --leak-check=full

SRR = main ft_pipex pathutil
SRC = $(addsuffix .c, $(SRR))
OBJ = $(SRC:%.c=%.o)

define make_libft
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a ./
endef

TEST_ARG = /dev/urandom "cat" "head -1" outfile
# TEST_ARG = infile 'ls -l' 'wc -l' outfile
# TEST_ARG = infile "awk '{count++} END {print count}'" 'wc -l' outfile

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(call make_libft)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_PATH)
# 	$@ -> curr. target. name
# 	$^ -> curr. dependancy. list

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

test: all
	./$(NAME) $(TEST_ARG)

leak: all
	colour-valgrind $(VFLAGS) ./$(NAME) $(TEST_ARG)

debug:
	$(call make_libft)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_PATH) $(DFLAGS)
	$(DEBUG) --args ./$(NAME) $(TEST_ARG)

releak: re leak

retest: re test

.PHONY: all clean fclean re test debug