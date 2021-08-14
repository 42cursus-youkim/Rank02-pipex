# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 14:32:23 by youkim            #+#    #+#              #
#    Updated: 2021/08/14 13:07:30 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCLST =	memset bzero memcpy memccpy memmove memchr memcmp\
			calloc strdup\
			strlen strlcpy strlcat strchr strrchr strnstr strncmp atoi\
			substr strjoin strtrim split itoa_base strmapi\
			putliteral putnbr_fd math exit purge2str\
			comp_alpha comp_ascii convert math math_ll
SRCLSB =	add utils delone clear iter map

SOURCES =	$(addprefix ./ft_,		$(addsuffix	.c,			$(SRCLST)))
SOURCEB =	$(addprefix ./ft_lst,	$(addsuffix	.c,			$(SRCLSB)))

OBJECTS =	$(SOURCES:%.c=%.o)
OBJECTB =	$(SOURCEB:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJECTS)
	$(AR) $@ $^

all: $(NAME)

bonus: $(OBJECTS) $(OBJECTB)
	$(AR) $(NAME) $^

clean:
	$(RM) $(OBJECTS) $(OBJECTB)

fclean: clean
	$(RM) $(NAME)

re: fclean all

solo: all clean

.PHONY: make bonus all clean fclean re solo
