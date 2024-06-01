/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:56:42 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/18 14:58:41 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	newgame(t_game *g, t_lay *lay)
{
	g->moves = 0;
	g->draw = 1;
	g->lay = *lay;
	init_sprites(g);
	init_window(g);
	mlx_loop_hook(g->mlx, ft_update, (void *)g);
	mlx_hook(g->win, 2, 0, key_hook, (void *)g);
	mlx_hook(g->win, 17, 0, end_game, (void *)g);
	mlx_loop(g->mlx);
}

void	init_game(t_lay *lay)
{
	t_game		g;
	const int	x = lay->size.x;
	const int	y = lay->size.y;

	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, x * SIZE, y * SIZE, "Pacman");
	newgame(&g, lay);
}
