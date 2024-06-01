/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:10:34 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/15 14:35:25 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_lay	ft_newlay(void)
{
	t_lay	lay;

	lay.size.x = 0;
	lay.size.y = 0;
	lay.n_exit = 0;
	lay.n_player = 0;
	lay.n_items = 0;
	lay.map = (char **)ft_calloc(1024, sizeof(char *));
	if (!lay.map)
		print_error("Memory reservation (lay.map)");
	return (lay);
}

void	init_sprites(t_game *g)
{
	int	size;

	size = SIZE;
	g->exit_img = mlx_xpm_file_to_image(g->mlx,
			"assets/map/exit.xpm", &size, &size);
	g->item_img = mlx_xpm_file_to_image(g->mlx,
			"assets/map/item.xpm", &size, &size);
	g->wall_img = mlx_xpm_file_to_image(g->mlx,
			"assets/map/wall.xpm", &size, &size);
	g->background = mlx_xpm_file_to_image(g->mlx,
			"assets/map/black.xpm", &size, &size);
	g->pacman.idle = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_closed.xpm", &size, &size);
}
