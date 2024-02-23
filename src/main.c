/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:04:50 by daortega          #+#    #+#             */
/*   Updated: 2024/02/23 16:35:45 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_printf("%s", map[i]);
		i++;
	}
}

static char	**free_map(char **map, int i)
{
	while (--i >= 0)
		free(map[i]);
	free(map);
	return (NULL);
}

static char	**init_map(t_map tmap, char *file)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
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

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	tmap;
	char	**map;

	if (check_arg(argc, argv) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("The file doesn't exist\n"), -1);
	tmap = init_tmap();
	if (check_map(fd, &tmap) == 0)
		return (close(fd), ft_printf("Invalid map\n"), -1);
	close(fd);
	print_tmap(tmap);
	map = init_map(tmap, argv[1]);
	if (map == NULL)
		return (ft_printf("Malloc failed\n"), -1);
	print_map(map);
}
