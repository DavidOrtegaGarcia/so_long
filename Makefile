# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daortega <daortega@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 14:34:28 by daortega          #+#    #+#              #
#    Updated: 2024/03/20 17:08:26 by daortega         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAMELIB = libs/so_long.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

#--------------<SRC>-------------
SRC = src/
CFILES = main.c check.c check_map.c  struct.c utils.c map.c mlx.c scene.c move.c
SRCC = $(addprefix $(SRC), $(CFILES))

DIR_O = tmp/
OBJC = $(addprefix $(DIR_O), $(SRCC:.c=.o))

# RULES
all: makelibft makemlx $(DIR_O) $(NAME)

makelibft: 
	$(MAKE) -C libft 

makemlx:
	$(MAKE) -C mlx
	
$(DIR_O):
	mkdir -p $(DIR_O)

$(DIR_O)%.o: %.c $(NAMELIB) Makefile
	mkdir -p $(dir $@)
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
	rm -rf $(DIR_O)
	rm -f $(OBJC)

fclean: clean fcleanlibft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
