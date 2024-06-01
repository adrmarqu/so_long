/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:47:07 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 11:24:00 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *g)
{
	if (key == 12 || key == 53)
		end_game(g);
	else if (key == 0)
	{
		g->pacman.dir = 1;
		move_win(g, -1, 0);
	}
	else if (key == 13)
	{
		g->pacman.dir = 2;
		move_win(g, 0, -1);
	}
	else if (key == 1)
	{
		g->pacman.dir = 3;
		move_win(g, 0, 1);
	}
	else if (key == 2)
	{
		g->pacman.dir = 0;
		move_win(g, 1, 0);
	}
	g->pacman.frames = 0;
	return (1);
}
