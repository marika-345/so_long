/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define TILE 32
# define READ_BUF 1024

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W_UP 87
# define KEY_A_UP 65
# define KEY_S_UP 83
# define KEY_D_UP 68
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define EV_KEYPRESS 2
# define EV_DESTROY 17
# define MASK_KEYPRESS 1L
# define MASK_NONE 0L

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		exits;
	int		starts;
}	t_map;

typedef struct s_tex
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*coin;
	void	*exit;
}	t_tex;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_tex	tex;
	int		moves;
	int		collected;
}	t_game;

void	error_exit(t_game *g, const char *msg);
void	init_game(t_game *g);
int		has_extension(const char *file, const char *ext);

int		load_map(t_game *g, const char *path);

int		validate_map(t_game *g);

int		check_path(t_game *g);

int		init_mlx(t_game *g);

void	render_frame(t_game *g);

int		on_close(t_game *g);
int		on_keypress(int kc, t_game *g);
void	setup_hooks(t_game *g);

void	move_player(t_game *g, int dx, int dy);

void	cleanup(t_game *g);
void	free_array(char **arr);

#endif
