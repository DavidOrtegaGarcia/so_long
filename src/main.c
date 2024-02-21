/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:04:50 by daortega          #+#    #+#             */
/*   Updated: 2024/02/21 19:52:07 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

char **init_map(t_map tmap, char *file)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	fd = open(file)
	map = (char**) malloc(tmap.nlines * sizeof(char *));
	if (map == NULL)
		return (NULL);
	while (i < tmap.nlines)
	{
		map[i] = (char *) malloc(tmap.nlines * sizeof(char));
		if (map[i] == NULL)
			return (freeMap(i));
		
	}
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
	if (check_map(fd, &map) == 0)
		return (close(fd), ft_printf("Invalid map\n"), -1);
	close(fd);
	map = init_map(tmap, argv[1]);
	
}
