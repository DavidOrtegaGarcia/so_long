/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:30 by daortega          #+#    #+#             */
/*   Updated: 2024/02/23 18:57:57 by daortega         ###   ########.fr       */
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

typedef	struct s_point
{
	int	y;
	int	x;
}	t_point;
int		check_arg(int argc, char *argv[]);
int		check_map(int fd, t_map *map);
t_map	init_tmap(void);
void	print_tmap(t_map tmap);
char	*ft_sl_strdup(char *s1);
#endif