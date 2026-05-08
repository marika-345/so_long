/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	put_tile(t_game *g, void *img, int x, int y)
{
	mlx_put_image_to_window(g->mlx, g->win, img, x * TILE, y * TILE);
}

static void	render_cell(t_game *g, int x, int y)
{
	char	c;

	c = g->map.grid[y][x];
	if (c == '1')
	{
		put_tile(g, g->tex.wall, x, y);
		return ;
	}
	put_tile(g, g->tex.floor, x, y);
	if (c == 'C')
		put_tile(g, g->tex.coin, x, y);
	else if (c == 'E')
		put_tile(g, g->tex.exit, x, y);
}

void	render_frame(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			render_cell(g, x, y);
			x++;
		}
		y++;
	}
	put_tile(g, g->tex.player, g->map.player_x, g->map.player_y);
}
