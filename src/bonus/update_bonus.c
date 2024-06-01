/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:47:47 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 11:23:51 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_anim(t_game *g)
{
	if (g->ghost.frames > g->ghost.limit)
	{
		g->ghost.frames = 0;
		g->draw = 1;
	}
	if (g->pacman.frames > g->pacman.limit)
	{
		g->pacman.frames = 0;
		g->draw = 1;
	}
}

static void	ft_put_image(t_game *g, int i, int j)
{
	const unsigned int	a = j * SIZE;
	const unsigned int	b = i * SIZE;

	if (g->lay.map[i][j] == 'C')
		mlx_put_image_to_window(g->mlx, g->win, g->item_img, a, b);
	else if (g->lay.map[i][j] == '0')
		mlx_put_image_to_window(g->mlx, g->win, g->background, a, b);
	else if (g->lay.map[i][j] == 'P')
		anim_player(g, (int)a, (int)b);
	else if (g->lay.map[i][j] == 'G')
		anim_ghost(g, (int)a, (int)b);
}

int	ft_update(t_game *g)
{
	int	i;
	int	j;

	set_anim(g);
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
	g->ghost.frames++;
	g->pacman.frames++;
	return (0);
}
