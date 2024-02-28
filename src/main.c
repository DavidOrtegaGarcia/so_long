/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:04:50 by daortega          #+#    #+#             */
/*   Updated: 2024/02/26 19:26:01 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

t_point find_pos_player(char **map)
{
	int i;
	int	j;
	t_point p_pos;

	p_pos.y = -1;
	p_pos.x = -1;
 	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				{
					p_pos.y = i;
					p_pos.x = j;
					return (p_pos);
				}
			j++;
		}
		i++;
	}
	return (p_pos);
}
int open_and_fill_map(char **argv, t_map *tmap)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("The file doesn't exist\n"), -1);
	*tmap = init_tmap();
	if (check_map(fd, tmap) == 0)
		return (close(fd), ft_printf("Invalid map\n"), -1);
	close(fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	tmap;
	char	**map;
	char	**cmap;
	t_point p_pos;

	if (check_arg(argc, argv) == -1)
		return (-1);
	if (open_and_fill_map(argv, &tmap) == -1)
		return (-1);
	print_tmap(tmap);
	map = init_map(tmap, argv[1]);
	if (map == NULL)
		return (ft_printf("Malloc failed\n"), -1);
	print_map(map);
	p_pos = find_pos_player(map);
	ft_printf("Player position: %d, %d\n",p_pos.y, p_pos.x);
	cmap = copy_map(map, tmap);
	if (cmap == NULL)
		return (ft_printf("Malloc failed\n"), -1);
	flood_fill(cmap, &tmap, p_pos);
	if (tmap.coin != 0 || tmap.exit != 0)
		return (ft_printf("Invalid map\n"), -1);
	free_map(cmap, tmap.nlines);
	free_map(map, tmap.nlines);
}
