/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	print_moves(int n)
{
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

void	move_player(t_game *g, int dx, int dy)
{
	int		nx;
	int		ny;
	char	t;

	nx = g->map.player_x + dx;
	ny = g->map.player_y + dy;
	t = g->map.grid[ny][nx];
	if (t == '1')
		return ;
	if (t == 'C')
	{
		g->map.grid[ny][nx] = '0';
		g->collected++;
	}
	g->map.player_x = nx;
	g->map.player_y = ny;
	g->moves++;
	print_moves(g->moves);
	render_frame(g);
	if (t == 'E' && g->collected == g->map.collectibles)
		on_close(g);
}
