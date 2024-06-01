/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:50:54 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 11:26:36 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_name(const char *s, const char *ber)
{
	char	*ext;

	ext = ft_strrchr(s, '.');
	if (!ext || ft_strcmp(ext, ber) != 0)
		print_error("Wrong extension map");
}

static void	check_argc(int argc)
{
	if (argc < 2)
		print_error("No data");
	else if (argc > 2)
		print_error("Too many data");
}

static int	ft_open(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		print_error("That map does not exist");
	return (fd);
}

void	check_arguments(int num, char *map_name, t_lay *lay)
{
	int		fd;

	check_argc(num);
	check_name(map_name, ".ber");
	fd = ft_open(map_name);
	read_map(fd, lay);
	check_map(lay);
	close(fd);
}
