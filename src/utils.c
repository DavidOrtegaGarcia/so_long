/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daortega <daortega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:19:31 by daortega          #+#    #+#             */
/*   Updated: 2024/02/23 15:42:12 by daortega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/so_long.h"

static size_t	ft_linelen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

char	*ft_sl_strdup(const char *s1)
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
	while (i < s1_length)
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
