/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 20:19:46 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/18 20:20:26 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_player(t_lay *lay, t_point cur, char **data, char to_find)
{
	if (cur.x < 0 || cur.x >= lay->size.x || cur.y < 0 || cur.y >= lay->size.y
		|| data[cur.y][cur.x] == '1' || data[cur.y][cur.x] == 'x'
		|| data[cur.y][cur.x] == 'G')
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
		|| data[cur.y][cur.x] == 'E' || data[cur.y][cur.x] == 'G')
		return ;
	if (data[cur.y][cur.x] == to_find)
		lay->path = 1;
	data[cur.y][cur.x] = 'x';
	check_item(lay, (t_point){cur.x - 1, cur.y}, data, to_find);
	check_item(lay, (t_point){cur.x + 1, cur.y}, data, to_find);
	check_item(lay, (t_point){cur.x, cur.y - 1}, data, to_find);
	check_item(lay, (t_point){cur.x, cur.y + 1}, data, to_find);
}
