/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:39:55 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:33:32 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_image(t_game *g, int i, int j)
{
	const unsigned int	a = j * SIZE;
	const unsigned int	b = i * SIZE;

	if (g->lay.map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->item_img, a, b);
	else if (g->lay.map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->background, a, b);
	else if (g->lay.map[i][j] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->pacman.idle, a, b);
}

int	ft_update(t_game *g)
{
	int	i;
	int	j;

	if (g->draw)
	{
		g->player = find_spawn(g->lay.map);
		i = 0;
		while (g->lay.map[i])
		{
			j = 0;
			while (g->lay.map[i][j] && g->lay.map[i][j] != '\n')
			{
				ft_put_image(g, i, j);
				j++;
			}
			i++;
		}
		g->draw = 0;
	}
	return (0);
}
