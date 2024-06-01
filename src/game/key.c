/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:43:29 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:52:03 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *g)
{
	if (key == 12 || key == 53)
		end_game(g);
	else if (key == 0)
		move(g, -1, 0, "A");
	else if (key == 13)
		move(g, 0, -1, "W");
	else if (key == 1)
		move(g, 0, 1, "S");
	else if (key == 2)
		move(g, 1, 0, "D");
	return (1);
}
