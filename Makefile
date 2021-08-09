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

CC = gcc
CFLAGS = # -Wall -Wextra -Werror

define make_libft
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT).a $(NAME)
endef

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(call make_libft)
	$(AR) $@ $^
# 	$@ -> curr. target. name
# 	$^ -> curr. dependancy. list

all: $(NAME)

bonus: all

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

test: all
	$(CC) $(CFLAGS) -c -o main.o main.c
	$(CC) -o test.out -L. $(NAME) main.o
	./test.out

leak: test
	valgrind --leak-check=full ./test.out

retest: re test

.PHONY: all clean fclean re test bonus