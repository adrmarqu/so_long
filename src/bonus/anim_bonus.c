/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 12:43:41 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 11:23:42 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	my_rand(t_game *g)
{
	g->random = g->random * 1103515245 + 12345;
	return ((unsigned int)(g->random / 65536) % 32768);
}

void	anim_ghost(t_game *g, int a, int b)
{
	g->ghost.dir = my_rand(g) % 10;
	if (g->ghost.dir == 0)
		mlx_put_image_to_window(g->mlx, g->win, g->ghost.idle, a, b);
	else if (g->ghost.dir == 1)
		mlx_put_image_to_window(g->mlx, g->win, g->ghost.idle2, a, b);
}

static void	update_status(t_game *g)
{
	g->pacman.status++;
	if (g->pacman.status > 3)
		g->pacman.status = 0;
}

static void	pacman(t_game *g, void *anim, int a, int b)
{
	mlx_put_image_to_window(g->mlx, g->win, g->background, a, b);
	mlx_put_image_to_window(g->mlx, g->win, anim, a, b);
}

void	anim_player(t_game *g, int a, int b)
{
	int	st;

	st = g->pacman.status;
	if (!st)
		mlx_put_image_to_window(g->mlx, g->win, g->pacman.idle, a, b);
	else
	{
		if (g->pacman.dir == 0 && (st == 1 || st == 3))
			pacman(g, g->pacman.right, a, b);
		else if (g->pacman.dir == 0 && st == 2)
			pacman(g, g->pacman.right2, a, b);
		else if (g->pacman.dir == 1 && (st == 1 || st == 3))
			pacman(g, g->pacman.left, a, b);
		else if (g->pacman.dir == 1 && st == 2)
			pacman(g, g->pacman.left2, a, b);
		else if (g->pacman.dir == 2 && (st == 1 || st == 3))
			pacman(g, g->pacman.up, a, b);
		else if (g->pacman.dir == 2 && st == 2)
			pacman(g, g->pacman.up2, a, b);
		else if (g->pacman.dir == 3 && (st == 1 || st == 3))
			pacman(g, g->pacman.down, a, b);
		else if (g->pacman.dir == 3 && st == 2)
			pacman(g, g->pacman.down2, a, b);
	}
	update_status(g);
}
