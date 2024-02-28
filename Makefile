# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daortega <daortega@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:34:28 by daortega          #+#    #+#              #
#    Updated: 2024/02/28 19:30:26 by daortega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMELIB = libs/so_long.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Imlx
#-fsanitize=address

#--------------<SRC>-------------
SRC = src/
CFILES = main.c check.c check2.c  struct.c utils.c map.c
SRCC = $(addprefix $(SRC), $(CFILES))

OBJC = $(SRCC:.c=.o)

# RULES
all: makelibft makemlx $(NAME)

makelibft: 
	$(MAKE) -C libft

makemlx:
	$(MAKE) -C mlx
	
%.o: %.c $(NAMELIB) Makefile
	$(CC) $(CFLAGS) -c -o $@ $< 

$(NAME): $(OBJC) libft/libft.a mlx/mlx.a
	$(CC) $(CFLAGS) libft/libft.a mlx/mlx.a $(OBJC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

cleanlibft:
	$(MAKE) -C libft clean

fcleanlibft:
	$(MAKE) -C libft fclean

cleanmlx:
	$(MAKE) -C mlx clean

fcleanmlx:
	$(MAKE) -C mlx fclean

clean: cleanlibft cleanmlx
	rm -f $(OBJC)

fclean: clean fcleanlibft fcleanmlx
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
