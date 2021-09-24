# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 14:32:23 by youkim            #+#    #+#              #
#    Updated: 2021/09/24 18:29:26 by youkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = # -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCLST =	strlen strlcpy strlcat strchr strncmp\
			strdup strjoin split qsplit\
			math exit purge2str putliteral comp_ascii\
			# memset memcpy memccpy memcmp memmove memchr\
			# substr strtrim strrchr strnstr strtrd\
			# putnbr_fd atoi itoa_base strmapi\
			# comp_alpha  convert math math_ll\


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

test: main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
    ifeq ($(TFLAG),clear)
		clear
    endif
		./$@

.PHONY: make bonus all clean fclean re solo test
