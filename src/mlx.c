/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:23:19 by daortega          #+#    #+#             */
/*   Updated: 2024/03/13 15:45:27 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	exit_hook(t_data *data)
{
	end_game(data);
	return (0);
}

static int	key_hook(int keycode, t_data *data)
{
	static int	movs = 0;

	if (keycode == W_KEY || keycode == UP_KEY)
		movs = move_up(data, data->tmlx, data->p_pos, movs);
	if (keycode == A_KEY || keycode == LEFT_KEY)
		movs = move_left(data, data->tmlx, data->p_pos, movs);
	if (keycode == S_KEY || keycode == DOWN_KEY)
		movs = move_down(data, data->tmlx, data->p_pos, movs);
	if (keycode == D_KEY || keycode == RIGHT_KEY)
		movs = move_right(data, data->tmlx, data->p_pos, movs);
	if (keycode == ESC_KEY || movs == -1)
		end_game(data);
	ft_printf("Number of movs: %d\n", movs);
	return (0);
}

void	run_mlx(char **map, t_map tmap, t_point p_pos)
{
	t_mlx	tmlx;
	t_data	data;

	tmap.coin = tmap.coin;
	tmlx.mlx = mlx_init();
	tmlx.sc = init_scene(tmlx.mlx);
	tmlx.mlx_win = mlx_new_window(tmlx.mlx, tmap.sline * tmlx.sc.player.x,
			tmap.nlines * tmlx.sc.player.y, "so_long");
	fill_window(tmlx, map);
	data = init_data(tmlx, map, tmap, p_pos);
	mlx_key_hook(tmlx.mlx_win, key_hook, &data);
	mlx_hook(tmlx.mlx_win, EXIT_EVENT, 0, exit_hook, &data);
	mlx_loop(tmlx.mlx);
}
