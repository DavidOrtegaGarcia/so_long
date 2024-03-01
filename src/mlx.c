/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:23:19 by daortega          #+#    #+#             */
/*   Updated: 2024/03/01 20:05:20 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	put_image(char **map, int x, int y, t_mlx mlx)
{
	if (map[y][x] == '1')
	{
		//mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.grass1.img, i, j);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.tree.img, x * mlx.sc.player.x, y * mlx.sc.player.y);
	}
	if (map[y][x] == 'C')
	{
		//mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.grass2.img, i, j);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.coin.img, x * mlx.sc.player.x, y * mlx.sc.player.y);
	}
	if (map[y][x] == 'E')
	{
		//mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.grass2.img, i, j);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.exit.img, x * mlx.sc.player.x, y * mlx.sc.player.y);
	}
	if (map[y][x] == 'P')
	{
		//mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.grass2.img, i, j);
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.player.img, x * mlx.sc.player.x, y * mlx.sc.player.y);
	}
	if (map[y][x] == '0')
		mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.sc.grass2.img, x * mlx.sc.player.x, y * mlx.sc.player.y);
}

void	fill_window(t_mlx mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			put_image(map, j, i, mlx);
			j++;
		}
		i++;
	}
}

t_imgs_scene init_scene(void *mlx)
{
	t_imgs_scene	sc;

	sc.player.img = mlx_xpm_file_to_image(mlx, "textures/Warrior.xpm", 
	&sc.player.x, &sc.player.y);
	sc.coin.img = mlx_xpm_file_to_image(mlx, "textures/Potion.xpm", 
	&sc.coin.x, &sc.coin.y);
	sc.exit.img = mlx_xpm_file_to_image(mlx, "textures/Chest.xpm", 
	&sc.exit.x, &sc.exit.y);
	sc.tree.img = mlx_xpm_file_to_image(mlx, "textures/Tree.xpm", 
	&sc.tree.x, &sc.tree.y);
	sc.grass1.img = mlx_xpm_file_to_image(mlx, "textures/Grass1.xpm", 
	&sc.grass1.x, &sc.grass2.y);
	sc.grass2.img = mlx_xpm_file_to_image(mlx, "textures/Grass2.xpm", 
	&sc.grass2.x, &sc.grass2.y);
	return (sc);
}

void  run_mlx(char **map, t_map tmap)
{
	t_mlx	mlx;

	tmap.coin = tmap.coin;
	mlx.mlx = mlx_init();
	mlx.sc = init_scene(mlx.mlx);
	mlx.mlx_win = mlx_new_window(mlx.mlx, tmap.sline * mlx.sc.player.x,
	tmap.nlines * mlx.sc.player.y , "so_long");
	fill_window(mlx, map);
	mlx_loop(mlx.mlx);
}
