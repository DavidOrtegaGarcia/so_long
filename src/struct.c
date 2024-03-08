/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:20:03 by daortega          #+#    #+#             */
/*   Updated: 2024/03/08 17:36:27 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

t_data	init_data(t_mlx tmlx, char **map, t_map tmap, t_point p_pos)
{
	t_data	data;

	data.tmlx = tmlx;
	data.map = map;
	data.tmap = tmap;
	data.p_pos = p_pos;
	return (data);
}

void	print_tmap(t_map tmap)
{
	ft_printf("Player: %d\n", tmap.player);
	ft_printf("Coin: %d\n", tmap.coin);
	ft_printf("Exit: %d\n", tmap.exit);
	ft_printf("Nlines: %d\n", tmap.nlines);
	ft_printf("Slines: %d\n", tmap.sline);
}

t_map	init_tmap(void)
{
	t_map	tmap;

	tmap.coin = 0;
	tmap.exit = 0;
	tmap.player = 0;
	tmap.nlines = 0;
	tmap.sline = 0;
	return (tmap);
}
