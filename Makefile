# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daortega <daortega@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:34:28 by daortega          #+#    #+#              #
#    Updated: 2024/03/06 19:25:01 by daortega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMELIB = libs/so_long.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address

#--------------<SRC>-------------
SRC = src/
CFILES = main.c check.c check_map.c  struct.c utils.c map.c mlx.c scene.c 
SRCC = $(addprefix $(SRC), $(CFILES))

OBJC = $(SRCC:.c=.o)

# RULES
all: makelibft makemlx $(NAME)

makelibft: 
	$(MAKE) -C libft

makemlx:
	$(MAKE) -C mlx
	
%.o: %.c $(NAMELIB) Makefile
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJC) libft/libft.a mlx/libmlx.a
	$(CC) $(CFLAGS) $(OBJC) -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

cleanlibft:
	$(MAKE) -C libft clean

fcleanlibft:
	$(MAKE) -C libft fclean

cleanmlx:
	$(MAKE) -C mlx clean

clean: cleanlibft cleanmlx
	rm -f $(OBJC)

fclean: clean fcleanlibft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
