/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:46:43 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:46:45 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_lay *lay)
{
	int	i;
	int	length;

	i = 0;
	while (1)
	{
		lay->map[i] = get_next_line(fd);
		if (!lay->map[i])
			return ;
		length = ft_strlen(lay->map[i]) - 1;
		if (length > 51)
			print_error("The map is too big (x < 52 && y < 27)");
		if (i == 0)
			lay->size.x = length;
		if (length != lay->size.x)
			print_error("Map is not rectangular");
		i++;
		lay->size.y++;
		if (lay->size.y > 26)
			print_error("The map is too big (x < 52 && y < 27)");
	}
}

static void	check_es(int spawn, int exit)
{
	if (spawn > 1 && exit <= 1)
		print_error("Too many players");
	else if (spawn <= 1 && exit > 1)
		print_error("Too many exits");
	else if (spawn > 1 && exit > 1)
		print_error("Too many players and exits");
	else if (spawn == 0 && exit > 0)
		print_error("No player");
	else if (spawn > 0 && exit == 0)
		print_error("No exit");
	else if (spawn == 0 && exit == 0)
		print_error("No player and exit");
}

static void	count(char c, t_lay *lay)
{
	if (c == 'E')
		lay->n_exit++;
	else if (c == 'P')
		lay->n_player++;
	else if (c == 'C')
		lay->n_items++;
	else if (c == 'G')
		lay->n_ghosts++;
}

static void	check_components(t_lay *lay)
{
	int	i;
	int	j;

	i = 0;
	while (lay->map[i])
	{
		j = 0;
		while (lay->map[i][j] && lay->map[i][j] != '\n')
		{
			if (lay->map[i][j] != '1' && (i == 0 || j == 0
				|| i == lay->size.y - 1 || j == lay->size.x - 1))
				print_error("Map is not surrounded by walls");
			if (!ft_find(lay->map[i][j], "01CPEG"))
				print_error("Wrong data of the map");
			count(lay->map[i][j], lay);
			j++;
		}
		i++;
	}
	check_es(lay->n_player, lay->n_exit);
}

void	check_map(t_lay *lay)
{
	check_components(lay);
	path(lay);
}
