/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:27:49 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/18 20:17:35 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(t_lay *lay, t_point cur, char **data, char to_find)
{
	if (cur.x < 0 || cur.x >= lay->size.x || cur.y < 0 || cur.y >= lay->size.y
		|| data[cur.y][cur.x] == '1' || data[cur.y][cur.x] == 'x')
		return ;
	if (data[cur.y][cur.x] == to_find)
		lay->path = 1;
	data[cur.y][cur.x] = 'x';
	check_player(lay, (t_point){cur.x - 1, cur.y}, data, to_find);
	check_player(lay, (t_point){cur.x + 1, cur.y}, data, to_find);
	check_player(lay, (t_point){cur.x, cur.y - 1}, data, to_find);
	check_player(lay, (t_point){cur.x, cur.y + 1}, data, to_find);
}

void	check_item(t_lay *lay, t_point cur, char **data, char to_find)
{
	if (cur.x < 0 || cur.x >= lay->size.x || cur.y < 0 || cur.y >= lay->size.y
		|| data[cur.y][cur.x] == '1' || data[cur.y][cur.x] == 'x'
		|| data[cur.y][cur.x] == 'E')
		return ;
	if (data[cur.y][cur.x] == to_find)
		lay->path = 1;
	data[cur.y][cur.x] = 'x';
	check_item(lay, (t_point){cur.x - 1, cur.y}, data, to_find);
	check_item(lay, (t_point){cur.x + 1, cur.y}, data, to_find);
	check_item(lay, (t_point){cur.x, cur.y - 1}, data, to_find);
	check_item(lay, (t_point){cur.x, cur.y + 1}, data, to_find);
}
