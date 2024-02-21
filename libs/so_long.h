/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:30 by daortega          #+#    #+#             */
/*   Updated: 2024/02/21 18:05:27 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int	player;
	int	coin;
	int	exit;
	int	nlines;
	int	sline;
}	t_map;

int		check_arg(int argc, char *argv[]);
int		check_map(int fd);
t_map	init_map(void);
void	print_map(t_map map);
#endif