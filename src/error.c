/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_exit(t_game *g, const char *msg)
{
	ft_putstr_fd("Error\n", 2);
	if (msg)
	{
		ft_putstr_fd((char *)msg, 2);
		ft_putstr_fd("\n", 2);
	}
	cleanup(g);
	exit(1);
}

void	init_game(t_game *g)
{
	g->mlx = NULL;
	g->win = NULL;
	g->map.grid = NULL;
	g->map.width = 0;
	g->map.height = 0;
	g->map.player_x = 0;
	g->map.player_y = 0;
	g->map.collectibles = 0;
	g->map.exits = 0;
	g->map.starts = 0;
	g->tex.wall = NULL;
	g->tex.floor = NULL;
	g->tex.player = NULL;
	g->tex.coin = NULL;
	g->tex.exit = NULL;
	g->moves = 0;
	g->collected = 0;
}

int	has_extension(const char *file, const char *ext)
{
	size_t	lf;
	size_t	le;

	lf = ft_strlen(file);
	le = ft_strlen(ext);
	if (lf < le)
		return (0);
	return (ft_strncmp(file + lf - le, ext, le) == 0);
}
