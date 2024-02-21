/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:04:50 by daortega          #+#    #+#             */
/*   Updated: 2024/02/21 18:30:41 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int	main(int argc, char *argv[])
{
	int	fd;
	
	if (check_arg(argc, argv) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("The file doesn't exist\n"), -1);
	if (check_map(fd) == 0)
		return (close(fd), ft_printf("Invalid map\n"), -1);
	close(fd);
}
