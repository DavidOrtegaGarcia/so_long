/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:30 by daortega          #+#    #+#             */
/*   Updated: 2024/02/19 17:25:18 by daortega         ###   ########.fr       */
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
}	t_map;

int	check_arg(int argc, char *argv[]);
t_map init_map(void);
#endif