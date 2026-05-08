/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	destroy_textures(t_game *g)
{
	if (g->tex.wall)
		mlx_destroy_image(g->mlx, g->tex.wall);
	if (g->tex.floor)
		mlx_destroy_image(g->mlx, g->tex.floor);
	if (g->tex.player)
		mlx_destroy_image(g->mlx, g->tex.player);
	if (g->tex.coin)
		mlx_destroy_image(g->mlx, g->tex.coin);
	if (g->tex.exit)
		mlx_destroy_image(g->mlx, g->tex.exit);
}

void	cleanup(t_game *g)
{
	if (g->mlx)
		destroy_textures(g);
	if (g->win && g->mlx)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	free_array(g->map.grid);
}

void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
