/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:27:15 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/06/01 12:53:40 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_path(t_lay *lay, int x, int y, int type)
{
	t_point	start;
	char	**r;

	r = (char **)ft_calloc(1024, sizeof(char *));
	if (!r)
		print_error("Memory reservation (r_exit)");
	start.x = x;
	start.y = y;
	lay->path = 0;
	dup_map(lay->map, r);
	if (type)
		check_player(lay, start, r, 'P');
	else
		check_item(lay, start, r, 'P');
	ft_free(r);
	if (!lay->path)
		print_error("There is no possible path");
}

void	path(t_lay *lay)
{
	int	i;
	int	j;

	i = 0;
	while (lay->map[i])
	{
		j = 0;
		while (lay->map[i][j] && lay->map[i][j] != '\n')
		{
			if (lay->map[i][j] == 'E')
				find_path(lay, j, i, 1);
			if (lay->map[i][j] == 'C')
				find_path(lay, j, i, 0);
			j++;
		}
		i++;
	}
}
