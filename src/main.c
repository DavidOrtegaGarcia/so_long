/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:04:50 by daortega          #+#    #+#             */
/*   Updated: 2024/02/12 18:33:56 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

int main(int argc, char *argv[])
{
	int fd;
	if (check_arg(argc, argv) == -1)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("The file doesn't exist\n");
		return (-1);
	}
	//check_map(fd);
}
