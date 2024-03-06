/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 17:38:20 by daortega          #+#    #+#             */
/*   Updated: 2024/03/06 19:24:44 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	check_assets_pos(char **map, t_map tmap, t_point p_pos)
{
	char	**cmap;

	cmap = copy_map(map, tmap);
	if (cmap == NULL)
		return (ft_printf("Malloc failed\n"), -1);
	flood_fill(cmap, &tmap, p_pos);
	if (tmap.coin != 0 || tmap.exit != 0)
		return (ft_printf("Invalid map\n"), free_map(cmap, tmap.nlines), -1);
	free_map(cmap, tmap.nlines);
	return (1);
}

static int	check_ber(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (size > 4)
	{
		size -= 4;
		if (ft_strncmp(&file[size], ".ber", 4) == 0)
			return (1);
	}
	return (0);
}

int	check_arg(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("You have to pass only 1 argumnent\n");
		return (-1);
	}
	if (check_ber(argv[1]) == 0)
	{
		ft_printf("File not valid\n");
		return (-1);
	}
	return (1);
}
