/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:28:30 by daortega          #+#    #+#             */
/*   Updated: 2024/03/15 18:48:17 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include "../mlx/mlx.h"

/*###  KEY MAPPING	###*/
# define ESC_KEY 0x35
# define A_KEY 0x00
# define S_KEY 0x01
# define D_KEY 0x02
# define W_KEY 0x0D
# define UP_KEY 0x7E
# define DOWN_KEY 0x7D
# define LEFT_KEY 0x7B
# define RIGHT_KEY 0x7C

/*###   EVENT MAPPING   ###*/
# define EXIT_EVENT 17

/*---------STRUCTS----------*/
typedef struct s_map
{
	int	player;
	int	coin;
	int	exit;
	int	nlines;
	int	sline;
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_img
{
	void	*img;
	int		x;
	int		y;
}	t_img;

typedef struct s_imgs_scene
{
	t_img	player;
	t_img	playerl;
	t_img	playerb;
	t_img	playerr;
	t_img	coin;
	t_img	exit;
	t_img	tree;
	t_img	grass;
}	t_imgs_scene;

typedef struct s_mlx
{
	void			*mlx;
	void			*mlx_win;
	t_imgs_scene	sc;
}	t_mlx;

typedef struct s_data
{
	t_mlx			tmlx;
	char			**map;
	t_map			tmap;
	t_point			p_pos;
}	t_data;

/*--------------HEADERS--------------*/
int				check_arg(int argc, char *argv[]);
int				check_map(int fd, t_map *tmap);
t_map			init_tmap(void);
//void			print_tmap(t_map tmap);
char			*ft_sl_strdup(char *s1);
void			flood_fill(char **map, t_map *tmap, t_point pos);
char			**init_map(t_map tmap, char *file);
char			**free_map(char **map, int i);
char			**copy_map(char **map, t_map tmap);
void			print_map(char **map);
t_point			find_pos_player(char **map);
int				check_assets_pos(char **map, t_map tmap, t_point p_pos);
void			run_mlx(char **map, t_map tmap, t_point p_pos);
t_imgs_scene	init_scene(void *mlx);
void			fill_window(t_mlx mlx, char **map);
t_data			init_data(t_mlx tmlx, char **map, t_map tmap, t_point p_pos);
int				move_up(t_data *data, t_mlx tmlx, t_point p_pos, int movs);
int				move_left(t_data *data, t_mlx tmlx, t_point p_pos, int movs);
int				move_down(t_data *data, t_mlx tmlx, t_point p_pos, int movs);
int				move_right(t_data *data, t_mlx tmlx, t_point p_pos, int movs);
void			end_game(t_data *data);
#endif