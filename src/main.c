/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:04:50 by daortega          #+#    #+#             */
/*   Updated: 2024/02/28 18:38:27 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	open_and_fill_map(char **argv, t_map *tmap)
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
	void	*mlx;
	void	*mlx_win;

	if (check_arg(argc, argv) == -1)
		return (-1);
	if (open_and_fill_map(argv, &tmap) == -1)
		return (-1);
	print_tmap(tmap);
	map = init_map(tmap, argv[1]);
	if (map == NULL)
		return (ft_printf("Malloc failed\n"), -1);
	print_map(map);
	if (check_assets_pos(map, tmap) == -1)
		return (free_map(map, tmap.nlines), -1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Hello world!");
	mlx_loop(mlx);
	free_map(map, tmap.nlines);
}
