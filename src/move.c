/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:25:28 by daortega          #+#    #+#             */
/*   Updated: 2024/03/08 17:23:43 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	acces_exit(t_map tmap, int movs)
{
	if (tmap.coin == 0)
	{
		ft_printf("Number of movs: %d\n", ++movs);
		return (-1);
	}
	return (movs);
}

int	move_up(t_data *data, t_mlx tmlx, t_point p_pos, int movs)
{
	if (data->map[p_pos.y -1][p_pos.x] == '1')
		return (movs);
	if (data->map[p_pos.y -1][p_pos.x] == 'E')
		return (acces_exit(data->tmap, movs));
	if (data->map[p_pos.y -1][p_pos.x] == '0')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.playerb.img,
			p_pos.x * tmlx.sc.playerb.x, (p_pos.y -1) * tmlx.sc.playerb.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.grass.x, p_pos.y * tmlx.sc.grass.y);
	}
	if (data->map[p_pos.y -1][p_pos.x] == 'C')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.playerb.img,
			p_pos.x * tmlx.sc.playerb.x, (p_pos.y -1) * tmlx.sc.playerb.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.grass.x, p_pos.y * tmlx.sc.grass.y);
		data->tmap.coin--;
		data->map[p_pos.y -1][p_pos.x] = '0';
	}
	data->map[p_pos.y][p_pos.x] = '0';
	data->p_pos.y--;
	movs++;
	return (movs);
}

int	move_left(t_data *data, t_mlx tmlx, t_point p_pos, int movs)
{
	if (data->map[p_pos.y][p_pos.x -1] == '1')
		return (movs);
	if (data->map[p_pos.y][p_pos.x -1] == 'E')
		return (acces_exit(data->tmap, movs));
	if (data->map[p_pos.y][p_pos.x -1] == '0')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.playerl.img,
			(p_pos.x -1) * tmlx.sc.playerl.x, p_pos.y * tmlx.sc.playerl.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.grass.x, p_pos.y * tmlx.sc.grass.y);
	}
	if (data->map[p_pos.y][p_pos.x -1] == 'C')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.player.img,
			(p_pos.x -1) * tmlx.sc.player.x, p_pos.y * tmlx.sc.player.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.grass.x, p_pos.y * tmlx.sc.grass.y);
		data->tmap.coin--;
		data->map[p_pos.y][p_pos.x -1] = '0';
	}
	data->map[p_pos.y][p_pos.x] = '0';
	data->p_pos.x--;
	movs++;
	return (movs);
}

int	move_down(t_data *data, t_mlx tmlx, t_point p_pos, int movs)
{
	if (data->map[p_pos.y +1][p_pos.x] == '1')
		return (movs);
	if (data->map[p_pos.y +1][p_pos.x] == 'E')
		return (acces_exit(data->tmap, movs));
	if (data->map[p_pos.y +1][p_pos.x] == '0')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.player.img,
			p_pos.x * tmlx.sc.player.x, (p_pos.y +1) * tmlx.sc.player.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.grass.x, p_pos.y * tmlx.sc.grass.y);
	}
	if (data->map[p_pos.y +1][p_pos.x] == 'C')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.player.img,
			p_pos.x * tmlx.sc.player.x, (p_pos.y +1) * tmlx.sc.player.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.grass.x, p_pos.y * tmlx.sc.grass.y);
		data->tmap.coin--;
		data->map[p_pos.y +1][p_pos.x] = '0';
	}
	data->map[p_pos.y][p_pos.x] = '0';
	data->p_pos.y++;
	movs++;
	return (movs);
}

int	move_right(t_data *data, t_mlx tmlx, t_point p_pos, int movs)
{
	if (data->map[p_pos.y][p_pos.x +1] == '1')
		return (movs);
	if (data->map[p_pos.y][p_pos.x +1] == 'E')
		return (acces_exit(data->tmap, movs));
	if (data->map[p_pos.y][p_pos.x +1] == '0')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.playerr.img,
			(p_pos.x +1) * tmlx.sc.playerr.x, p_pos.y * tmlx.sc.playerr.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.grass.x, p_pos.y * tmlx.sc.grass.y);
	}
	if (data->map[p_pos.y][p_pos.x +1] == 'C')
	{
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.playerr.img,
			(p_pos.x +1) * tmlx.sc.playerr.x, p_pos.y * tmlx.sc.playerr.y);
		mlx_put_image_to_window(tmlx.mlx, tmlx.mlx_win, tmlx.sc.grass.img,
			p_pos.x * tmlx.sc.grass.x, p_pos.y * tmlx.sc.grass.y);
		data->tmap.coin--;
		data->map[p_pos.y][p_pos.x +1] = '0';
	}
	data->map[p_pos.y][p_pos.x] = '0';
	data->p_pos.x++;
	movs++;
	return (movs);
}
