/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:19:31 by daortega          #+#    #+#             */
/*   Updated: 2024/03/08 17:36:51 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	end_game(t_data *data)
{
	mlx_destroy_window(data->tmlx.mlx, data->tmlx.mlx_win);
	free(data->tmlx.mlx);
	free_map(data->map, data->tmap.nlines);
	ft_printf("GAME OVER\n");
	exit(1);
}

void	flood_fill(char **map, t_map *tmap, t_point pos)
{
	if (pos.y < 0 || pos.y >= tmap->nlines || pos.x < 0 || pos.x >= tmap->sline
		|| map[pos.y][pos.x] == '1' || map[pos.y][pos.x] == 'F')
		return ;
	if (map[pos.y][pos.x] == 'C')
		tmap->coin--;
	if (map[pos.y][pos.x] == 'E')
	{
		tmap->exit--;
		map[pos.y][pos.x] = '1';
		return ;
	}
	map[pos.y][pos.x] = 'F';
	flood_fill(map, tmap, (t_point){pos.x - 1, pos.y});
	flood_fill(map, tmap, (t_point){pos.x + 1, pos.y});
	flood_fill(map, tmap, (t_point){pos.x, pos.y - 1});
	flood_fill(map, tmap, (t_point){pos.x, pos.y + 1});
}

t_point	find_pos_player(char **map)
{
	int		i;
	int		j;
	t_point	p_pos;

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

static size_t	ft_linelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_sl_strdup(char *s1)
{
	char	*str;
	size_t	s1_length;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	s1_length = ft_linelen(s1) + 1;
	str = (char *) malloc(s1_length * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
