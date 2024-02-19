/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:15:53 by daortega          #+#    #+#             */
/*   Updated: 2024/02/19 19:25:11 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	check_lst_line(char *line, int sline)
{
	int i;

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

int	check_first_line(char *line, int *sline)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	if (line[i] == '\0')
		return (0);
	*sline = i;
	return (1);
}
int	check_line(char *line, int *sline, t_map *map, int nlines)
{
	int i;

	i = 0;
	if (nlines == 0)
		return (check_first_line(line, sline));
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
	if (line[i] == '\0')
		return (check_lst_line(line, *sline));
	if (i != *sline || line[0] != '1' || line[i - 1] != '1')
		return (0);
	return (1);
}

int	check_map(int fd)
{
	char	*line;
	int		nlines;
	int		sline;
	t_map	map;

	nlines = 0;
	sline = 0;
	map = init_map();
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (check_line(line, &sline, &map, nlines) == 0)
			return (0);
		free(line);
		nlines++;
	}
	if ((nlines < 3 && sline < 5) || (nlines < 5 && sline < 3) ||
		map.coin > 0 || map.player != 1 || map.exit != 1)
		return (0);
	return (1);
}

int	check_ber(char *file)
{
	int	size;

	size = ft_strlen(file);
	if (size > 4)
	{
		size -= 4;
		if (ft_strncmp(&file[size], ".ber", 4) == 0)
			return (1);
	}
	return (0);
}

int check_arg(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf("You have to pass only 1 argumnent\n");
		return (-1);
	}
	if (check_ber(argv[1]) == 0)
	{
		ft_printf("File not valid\n");
		return (-1);
	}
}
