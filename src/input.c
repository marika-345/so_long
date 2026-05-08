/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_close(t_game *g)
{
	cleanup(g);
	exit(0);
	return (0);
}

static int	dispatch_move(int kc, t_game *g)
{
	if (kc == KEY_W || kc == KEY_W_UP || kc == KEY_UP)
		move_player(g, 0, -1);
	else if (kc == KEY_S || kc == KEY_S_UP || kc == KEY_DOWN)
		move_player(g, 0, 1);
	else if (kc == KEY_A || kc == KEY_A_UP || kc == KEY_LEFT)
		move_player(g, -1, 0);
	else if (kc == KEY_D || kc == KEY_D_UP || kc == KEY_RIGHT)
		move_player(g, 1, 0);
	return (0);
}

int	on_keypress(int kc, t_game *g)
{
	if (kc == KEY_ESC)
		on_close(g);
	return (dispatch_move(kc, g));
}

void	setup_hooks(t_game *g)
{
	mlx_hook(g->win, EV_KEYPRESS, MASK_KEYPRESS, on_keypress, g);
	mlx_hook(g->win, EV_DESTROY, MASK_NONE, on_close, g);
}
