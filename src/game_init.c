/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	load_textures(t_game *g)
{
	int	w;
	int	h;

	g->tex.wall = mlx_xpm_file_to_image(g->mlx,
			"textures/wall.xpm", &w, &h);
	g->tex.floor = mlx_xpm_file_to_image(g->mlx,
			"textures/floor.xpm", &w, &h);
	g->tex.player = mlx_xpm_file_to_image(g->mlx,
			"textures/player.xpm", &w, &h);
	g->tex.coin = mlx_xpm_file_to_image(g->mlx,
			"textures/coin.xpm", &w, &h);
	g->tex.exit = mlx_xpm_file_to_image(g->mlx,
			"textures/exit.xpm", &w, &h);
	if (!g->tex.wall || !g->tex.floor || !g->tex.player
		|| !g->tex.coin || !g->tex.exit)
		return (0);
	return (1);
}

int	init_mlx(t_game *g)
{
	int	w;
	int	h;

	g->mlx = mlx_init();
	if (!g->mlx)
		return (0);
	w = g->map.width * TILE;
	h = g->map.height * TILE;
	g->win = mlx_new_window(g->mlx, w, h, "so_long");
	if (!g->win)
		return (0);
	if (!load_textures(g))
		return (0);
	return (1);
}
