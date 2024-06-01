/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:27:28 by adrmarqu          #+#    #+#             */
/*   Updated: 2024/04/22 11:33:15 by adrmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE 50

# include "../libft/libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include "../libft/mlx/mlx.h"
# include "color.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct t_data
{
	int				x;
	int				y;
}					t_point;

typedef struct s_lay
{
	char			**map;
	int				n_exit;
	int				n_player;
	int				n_items;
	int				n_ghosts;
	int				path;
	t_point			size;
}					t_lay;

typedef struct g_data
{
	int				dir;
	int				frames;
	int				limit;
	int				status;
	void			*idle;
	void			*idle2;
	void			*right;
	void			*right2;
	void			*left;
	void			*left2;
	void			*up;
	void			*up2;
	void			*down;
	void			*down2;
}					t_anim;

typedef struct p_data
{
	void			*zero;
	void			*one;
	void			*two;
	void			*three;
	void			*four;
	void			*five;
	void			*six;
	void			*seven;
	void			*eight;
	void			*nine;
}					t_score;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*background;
	void			*exit_img;
	void			*item_img;
	void			*wall_img;
	int				moves;
	int				draw;
	unsigned int	random;
	t_lay			lay;
	t_point			player;
	t_anim			ghost;
	t_anim			pacman;
	t_score			score;
}					t_game;

t_lay		ft_newlay(void);
void		check_arguments(int num, char *map_name, t_lay *lay);
void		read_map(int fd, t_lay *lay);
void		check_map(t_lay *lay);
void		path(t_lay *lay);

void		check_player(t_lay *lay, t_point cur, char **data, char to_find);
void		check_item(t_lay *lay, t_point cur, char **data, char to_find);

void		print_error(const char *s);
void		print_move(const int nb, const char *s);
void		print_window(t_game *g);

int			ft_find(char c, const char *set);
t_point		find_spawn(char **map);
void		dup_map(char **map, char **r);
void		ft_free(char **s);

void		init_window(t_game *g);
void		init_game(t_lay *lay);
void		init_sprites(t_game *g);
int			ft_update(t_game *g);
int			key_hook(int key, t_game *g);

int			end_game(t_game *g);
int			win_game(t_game *g);
int			lose_game(t_game *g);

void		move(t_game *g, int x, int y, const char *move);
void		move_win(t_game *g, int x, int y);

void		anim_ghost(t_game *g, int a, int b);
void		anim_player(t_game *g, int a, int b);

#endif
