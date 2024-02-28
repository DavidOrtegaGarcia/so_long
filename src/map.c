/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:24:21 by daortega          #+#    #+#             */
/*   Updated: 2024/02/28 18:10:25 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**copy_map(char **map, t_map tmap)
{
	char	**newmap;
	int		i;

	i = 0;
	newmap = (char **) malloc((tmap.nlines + 1) * sizeof(char *));
	if (newmap == NULL)
		return (NULL);
	while (map[i] != NULL)
	{
		newmap[i] = ft_strdup(map[i]);
		if (newmap[i] == NULL)
			return (free_map(newmap, i));
		i++;
	}
	newmap[i] = NULL;
	return (newmap);
}

char	**free_map(char **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
	return (NULL);
}

char	**init_map(t_map tmap, char *file)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = (char **) malloc((tmap.nlines + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	while (i < tmap.nlines)
	{
		map[i] = ft_sl_strdup(get_next_line(fd));
		if (map[i] == NULL)
			return (free_map(map, i));
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
