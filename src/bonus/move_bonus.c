/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:46:28 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 11:24:15 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_win(t_game *g, int x, int y)
{
	const char	c = g->lay.map[g->player.y + y][g->player.x + x];

	g->draw = 1;
	if (c == '1' || (c == 'E' && g->lay.n_items))
		return ;
	else if (c == 'E' && !g->lay.n_items)
		win_game(g);
	else if (c == 'G')
		lose_game(g);
	else if (c == 'C')
		g->lay.n_items--;
	g->lay.map[g->player.y][g->player.x] = '0';
	g->lay.map[g->player.y + y][g->player.x + x] = 'P';
	g->moves++;
	print_window(g);
}
