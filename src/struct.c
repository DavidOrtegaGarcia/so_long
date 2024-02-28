/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 17:20:03 by daortega          #+#    #+#             */
/*   Updated: 2024/02/26 15:44:12 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

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
