/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:56:00 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:34:33 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_image_on_window(t_game *g, int i, int j)
{
	unsigned const int	a = j * SIZE;
	unsigned const int	b = i * SIZE;

	if (g->lay.map[i][j] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->wall_img, a, b);
	else if (g->lay.map[i][j] == 'E')
		mlx_put_image_to_window(g->mlx, g->win, g->exit_img, a, b);
	else if (g->lay.map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->item_img, a, b);
	else if (g->lay.map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->background, a, b);
	else if (g->lay.map[i][j] == 'P')
		mlx_put_image_to_window(g->mlx, g->win, g->pacman.idle, a, b);
}

void	init_window(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->lay.map[i])
	{
		j = 0;
		while (g->lay.map[i][j] && g->lay.map[i][j] != '\n')
		{
			ft_put_image_on_window(g, i, j);
			j++;
		}
		i++;
	}
}