/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:48:05 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 11:25:47 by adrmarqu         ###   ########.fr       */
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
	lay.n_ghosts = 0;
	lay.map = (char **)ft_calloc(1024, sizeof(char *));
	if (!lay.map)
		print_error("Memory reservation (lay.map)");
	return (lay);
}

static void	init_ghosts(t_game *g, int size)
{
	g->ghost.frames = 0;
	g->ghost.dir = 0;
	g->ghost.limit = 1000;
	g->ghost.idle = mlx_xpm_file_to_image(g->mlx,
			"assets/ghosts/R/ghost_right1.xpm", &size, &size);
	g->ghost.idle2 = mlx_xpm_file_to_image(g->mlx,
			"assets/ghosts/R/ghost_left1.xpm", &size, &size);
}

static void	init_score(t_game *g, int size)
{
	g->score.zero = mlx_xpm_file_to_image(g->mlx,
			"assets/score/0.xpm", &size, &size);
	g->score.one = mlx_xpm_file_to_image(g->mlx,
			"assets/score/1.xpm", &size, &size);
	g->score.two = mlx_xpm_file_to_image(g->mlx,
			"assets/score/2.xpm", &size, &size);
	g->score.three = mlx_xpm_file_to_image(g->mlx,
			"assets/score/3.xpm", &size, &size);
	g->score.four = mlx_xpm_file_to_image(g->mlx,
			"assets/score/4.xpm", &size, &size);
	g->score.five = mlx_xpm_file_to_image(g->mlx,
			"assets/score/5.xpm", &size, &size);
	g->score.six = mlx_xpm_file_to_image(g->mlx,
			"assets/score/6.xpm", &size, &size);
	g->score.seven = mlx_xpm_file_to_image(g->mlx,
			"assets/score/7.xpm", &size, &size);
	g->score.eight = mlx_xpm_file_to_image(g->mlx,
			"assets/score/8.xpm", &size, &size);
	g->score.nine = mlx_xpm_file_to_image(g->mlx,
			"assets/score/9.xpm", &size, &size);
}

void	init_player(t_game *g, int size)
{
	g->pacman.dir = 0;
	g->pacman.frames = 0;
	g->pacman.limit = 5000;
	g->pacman.status = 0;
	g->pacman.idle = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_closed.xpm", &size, &size);
	g->pacman.right = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_semi_right.xpm", &size, &size);
	g->pacman.left = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_semi_left.xpm", &size, &size);
	g->pacman.up = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_semi_up.xpm", &size, &size);
	g->pacman.down = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_semi_down.xpm", &size, &size);
	g->pacman.right2 = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_open_right.xpm", &size, &size);
	g->pacman.left2 = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_open_left.xpm", &size, &size);
	g->pacman.up2 = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_open_up.xpm", &size, &size);
	g->pacman.down2 = mlx_xpm_file_to_image(g->mlx,
			"assets/pacman/pac_open_down.xpm", &size, &size);
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
	init_player(g, size);
	init_ghosts(g, size);
	init_score(g, size);
}
