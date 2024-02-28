# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daortega <daortega@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:34:28 by daortega          #+#    #+#              #
#    Updated: 2024/02/28 15:47:39 by daortega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMELIB = so_long.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address

#--------------<SRC>-------------
SRC = src/
CFILES = main.c check.c struct.c utils.c map.c
SRCC = $(addprefix $(SRC), $(CFILES))

OBJC = $(SRCC:.c=.o)

# RULES
all: makelib $(NAME)

makelib: 
	$(MAKE) -C libft

%.o: %.c $(NAMELIB) Makefile
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(OBJC) libft/libft.a
	$(CC) $(CFLAGS) libft/libft.a $(OBJC) -o $(NAME)

cleanlibft:
	$(MAKE) -C libft clean

fcleanlibft:
	$(MAKE) -C libft fclean

clean: cleanlibft
	rm -f $(OBJC)

fclean: clean fcleanlibft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
