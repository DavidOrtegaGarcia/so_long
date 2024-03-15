/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:15:53 by daortega          #+#    #+#             */
/*   Updated: 2024/03/15 19:45:46 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static int	check_lst_line(char *line, int sline)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (i != sline)
		return (0);
	return (1);
}

static int	check_line(char *line, char *line2, t_map *map)
{
	int	i;

	i = 0;
	if (line == NULL)
	{
		if (check_lst_line(line2, map->sline) == 0)
			return (0);
		return (-1);
	}
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == 'P')
			map->player++;
		else if (line[i] == 'C')
			map->coin++;
		else if (line[i] == 'E')
			map->exit++;
		else if (line[i] != '1' && line[i] != '0')
			return (0);
		i++;
	}
	if (i != map->sline || line[0] != '1' || line[i - 1] != '1')
		return (0);
	return (1);
}

static int	read_file(char *line, int fd, t_map *tmap)
{
	char	*line2;

	while (line != NULL)
	{
		line2 = ft_strdup(line);
		if (line2 == NULL)
			return (free(line), 0);
		free(line);
		line = get_next_line(fd);
		if (check_line(line, line2, tmap) == 0)
			return (free(line), free(line2), 0);
		if (line != NULL)
			tmap->nlines++;
		if (tmap->nlines > 25)
			return (free(line), free(line2), 0);
		free(line2);
	}
	free(line);
	return (1);
}

static int	check_first_line(char *line, int *sline)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1' || i >= 50)
			return (0);
		i++;
	}
	if (line[i] == '\0')
		return (0);
	*sline = i;
	return (1);
}

int	check_map(int fd, t_map *tmap)
{
	char	*line;

	line = get_next_line(fd);
	if (check_first_line(line, &tmap->sline) == 0)
		return (free(line), 0);
	tmap->nlines++;
	if (read_file(line, fd, tmap) == 0)
		return (0);
	if ((tmap->nlines < 3 && tmap->sline < 5)
		|| (tmap->nlines < 5 && tmap->sline < 3)
		|| tmap->coin <= 0 || tmap->player != 1 || tmap->exit != 1)
		return (0);
	return (1);
}
