/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	set_dimensions(t_map *m)
{
	int	i;
	int	w;

	w = (int)ft_strlen(m->grid[0]);
	if (w < 3)
		return (0);
	i = 0;
	while (m->grid[i])
	{
		if ((int)ft_strlen(m->grid[i]) != w)
			return (0);
		i++;
	}
	m->width = w;
	m->height = i;
	if (m->height < 3)
		return (0);
	return (1);
}

static int	check_borders(t_map *m)
{
	int	i;

	i = 0;
	while (i < m->width)
	{
		if (m->grid[0][i] != '1' || m->grid[m->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < m->height)
	{
		if (m->grid[i][0] != '1' || m->grid[i][m->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	count_cell(t_map *m, char c, int x, int y)
{
	if (c == '0' || c == '1')
		return (1);
	if (c == 'P')
	{
		m->starts++;
		m->player_x = x;
		m->player_y = y;
		return (1);
	}
	if (c == 'E')
	{
		m->exits++;
		return (1);
	}
	if (c == 'C')
	{
		m->collectibles++;
		return (1);
	}
	return (0);
}

static int	scan_chars(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (!count_cell(m, m->grid[y][x], x, y))
				return (0);
			x++;
		}
		y++;
	}
	if (m->starts != 1 || m->exits != 1 || m->collectibles < 1)
		return (0);
	return (1);
}

int	validate_map(t_game *g)
{
	if (!set_dimensions(&g->map))
		return (0);
	if (!check_borders(&g->map))
		return (0);
	if (!scan_chars(&g->map))
		return (0);
	return (1);
}
