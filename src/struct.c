/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:20:03 by daortega          #+#    #+#             */
/*   Updated: 2024/02/21 16:20:05 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	print_map(t_map map)
{
	ft_printf("Player: %d\n", map.player);
	ft_printf("Coin: %d\n", map.coin);
	ft_printf("Exit: %d\n", map.exit);
	ft_printf("Nlines: %d\n", map.nlines);
	ft_printf("Slines: %d\n", map.sline);
}

t_map init_map(void)
{
	t_map map;

	map.coin = 0;
	map.exit = 0;
	map.player = 0;
	map.nlines = 0;
	map.sline = 0;
	return (map);
}
