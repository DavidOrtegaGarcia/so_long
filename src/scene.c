/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 15:47:38 by daortega          #+#    #+#             */
/*   Updated: 2024/03/06 17:51:37 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static void	put_image2(char **map, int x, int y, t_mlx tmlx)
{
	if (map[y][x] == 'E')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.exit.img,
			x * tmlx.sc.exit.x, y * tmlx.sc.exit.y);
	}
	if (map[y][x] == 'P')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.player.img,
			x * tmlx.sc.player.x, y * tmlx.sc.player.y);
	}
	if (map[y][x] == '0')
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			x * tmlx.sc.grass.x, y * tmlx.sc.grass.y);
}

static void	put_image(char **map, int x, int y, t_mlx tmlx)
{
	if (map[y][x] == '1')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.tree.img,
			x * tmlx.sc.player.x, y * tmlx.sc.player.y);
	}
	if (map[y][x] == 'C')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.coin.img,
			x * tmlx.sc.coin.x, y * tmlx.sc.coin.y);
	}
	put_image2(map, x, y, tmlx);
}

void	fill_window(t_mlx mlx, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
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

t_imgs_scene	init_scene(void *mlx)
{
	t_imgs_scene	sc;

	sc.player.img = mlx_xpm_file_to_image(mlx, "textures/Player.xpm",
			&sc.player.x, &sc.player.y);
	sc.coin.img = mlx_xpm_file_to_image(mlx, "textures/Coin.xpm",
			&sc.coin.x, &sc.coin.y);
	sc.exit.img = mlx_xpm_file_to_image(mlx, "textures/Door.xpm",
			&sc.exit.x, &sc.exit.y);
	sc.tree.img = mlx_xpm_file_to_image(mlx, "textures/Tree.xpm",
			&sc.tree.x, &sc.tree.y);
	sc.grass.img = mlx_xpm_file_to_image(mlx, "textures/Grass.xpm",
			&sc.grass.x, &sc.grass.y);
	return (sc);
}
