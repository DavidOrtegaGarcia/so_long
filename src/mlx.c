/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:23:19 by daortega          #+#    #+#             */
/*   Updated: 2024/03/06 19:22:28 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"


int	move_up(t_data *data, t_mlx tmlx, t_point p_pos, int movs)
{

	if (data->map[p_pos.y -1][p_pos.x] == '1')
		return (movs);
	if (data->map[p_pos.y -1][p_pos.x] == '0')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.player.img,
			p_pos.x * tmlx.sc.player.x, (p_pos.y -1) * tmlx.sc.player.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.player.x, p_pos.y * tmlx.sc.grass.y);
	}
	if (data->map[p_pos.y -1][p_pos.x] == 'C')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.player.img,
			p_pos.x * tmlx.sc.player.x, (p_pos.y -1) * tmlx.sc.player.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.player.x, p_pos.y * tmlx.sc.grass.y);
		data->tmap.coin--;
	}
	//if (data->map[p_pos.y -1][p_pos.x] == 'E')
	data->p_pos.y--;
	movs++;
	return (movs);
}

static int	key_hook(int keycode, t_data *data)
{
	int	static movs = 0;

	if (keycode == W_KEY || keycode == UP_KEY)
		movs = move_up(data, data->tmlx, data->p_pos, movs);
	/*if (keycode == A_KEY || || keycode == LEFT_KEY)
		movs = move_left();
	if (keycode == S_KEY || || keycode == DOWN_KEY)
		movs = move_down();
	if (keycode == D_KEY)
		movs = move_right();
	if (keycode == ESC_KEY)*/

	ft_printf("Number of movs: %d\n", movs);
	return (0);
}

void  run_mlx(char **map, t_map tmap, t_point p_pos)
{
	t_mlx	tmlx;
	t_data	data;
	
	tmap.coin = tmap.coin;
	tmlx.mlx = mlx_init();
	tmlx.sc = init_scene(tmlx.mlx);
	tmlx.mlx_win = mlx_new_window(tmlx.mlx, tmap.sline * tmlx.sc.player.x,
	tmap.nlines * tmlx.sc.player.y , "so_long");
	fill_window(tmlx, map);
	data.tmlx = tmlx;
	data.map = map;
	data.tmap = tmap;
	data.p_pos = p_pos;
	mlx_key_hook(tmlx.mlx_win, key_hook, &data);
	mlx_loop(tmlx.mlx);
}
