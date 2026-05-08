/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static char	**dup_grid(char **src, int h)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (h + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < h)
	{
		copy[i] = ft_strdup(src[i]);
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

static void	flood(char **grid, int x, int y, t_map *m)
{
	if (x < 0 || y < 0 || x >= m->width || y >= m->height)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	grid[y][x] = 'V';
	flood(grid, x + 1, y, m);
	flood(grid, x - 1, y, m);
	flood(grid, x, y + 1, m);
	flood(grid, x, y - 1, m);
}

static int	has_unreached(char **grid, int h)
{
	int	x;
	int	y;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == 'C' || grid[y][x] == 'E')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	check_path(t_game *g)
{
	char	**copy;
	int		ok;

	copy = dup_grid(g->map.grid, g->map.height);
	if (!copy)
		return (0);
	flood(copy, g->map.player_x, g->map.player_y, &g->map);
	ok = !has_unreached(copy, g->map.height);
	free_array(copy);
	return (ok);
}
