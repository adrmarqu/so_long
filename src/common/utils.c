/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:13:23 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:40:14 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_find(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

t_point	find_spawn(char **map)
{
	int		i;
	int		j;
	t_point	spawn;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'P')
			{
				spawn.x = j;
				spawn.y = i;
				return (spawn);
			}
			j++;
		}
		i++;
	}
	spawn.x = -1;
	spawn.y = -1;
	return (spawn);
}

void	dup_map(char **map, char **r)
{
	int	i;

	i = 0;
	while (map[i])
	{
		r[i] = ft_strdup(map[i]);
		i++;
	}
	map[i] = NULL;
}

void	ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		s[i] = NULL;
		i++;
	}
	free(s);
	s = NULL;
}
