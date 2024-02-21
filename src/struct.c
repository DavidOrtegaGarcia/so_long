/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:20:03 by daortega          #+#    #+#             */
/*   Updated: 2024/02/21 19:21:20 by daortega         ###   ########.fr       */
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

t_map init_tmap(void)
{
	t_map tmap;

	tmap.coin = 0;
	tmap.exit = 0;
	tmap.player = 0;
	tmap.nlines = 0;
	tmap.sline = 0;
	return (tmap);
}
