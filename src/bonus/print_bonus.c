/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:48:33 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 11:24:41 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(const char *s)
{
	ft_printf(RED "Error\n" YELLOW "%s" WHITE "\n", s);
	exit(1);
}

void	print_move(const int nb, const char *s)
{
	ft_printf(CYAN "Moves: %d\n" MAGENTA "ACTION: %s\n\n", nb, s);
}

static void	ft_print_score(t_game *g, int nb, int pos)
{
	void	*s;

	s = NULL;
	if (nb == 0)
		s = g->score.zero;
	else if (nb == 1)
		s = g->score.one;
	else if (nb == 2)
		s = g->score.two;
	else if (nb == 3)
		s = g->score.three;
	else if (nb == 4)
		s = g->score.four;
	else if (nb == 5)
		s = g->score.five;
	else if (nb == 6)
		s = g->score.six;
	else if (nb == 7)
		s = g->score.seven;
	else if (nb == 8)
		s = g->score.eight;
	else if (nb == 9)
		s = g->score.nine;
	mlx_put_image_to_window(g->mlx, g->win, s, 10 * pos, g->lay.size.y * 50);
}

void	print_window(t_game *g)
{
	int	m;
	int	i;
	int	num[4];

	m = g->moves;
	i = 0;
	if (m > 9999)
		return ;
	while (i < 4)
	{
		num[3 - i] = m % 10;
		m = m / 10;
		i++;
	}
	i = 0;
	m = g->moves;
	while (i < 4)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->background, 10 * i,
			g->lay.size.y * 50);
		ft_print_score(g, num[i], i);
		m = m / 10;
		i++;
	}
}
