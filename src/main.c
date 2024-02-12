/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:04:50 by daortega          #+#    #+#             */
/*   Updated: 2024/02/12 17:59:49 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

/*int	check_map(int fd)
{
	char *line = NULL;

	while(line != NULL)
	{
		line = get_next_line(fd);
		if (check_line(line) = 0)
			return (0)
		free(line);
	}
	return (1);
}*/
int check_ber(char *file)
{
	int size;

	size = ft_strlen(file);
	if (size > 4)
	{
		size -= 4;
		if (ft_strncmp(&file[size], ".ber", 4) == 0)
			return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		ft_printf("You have to pass only 1 argumnent\n");
		return (-1);
	}
	if (check_ber(argv[1]) == 0)
	{
		ft_printf("File not valid\n");
		return(-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("The file doesn't exist\n");
		return(-1);
	}
	//check_map(fd);
}
