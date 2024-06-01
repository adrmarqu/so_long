/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:43:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/10 14:04:15 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clear(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_window(g->mlx, g->win);
	ft_free(g->lay.map);
	exit(0);
}

int	end_game(t_game *g)
{
	ft_printf(GRAY "You exit the game" WHITE "\n");
	ft_clear(g);
	return (0);
}

int	win_game(t_game *g)
{
	ft_printf(GREEN "You win" WHITE "\n");
	ft_clear(g);
	return (0);
}

int	lose_game(t_game *g)
{
	ft_printf(RED "You lose" WHITE "\n");
	ft_clear(g);
	return (0);
}
