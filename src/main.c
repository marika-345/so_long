/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgumberi <mgumberi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 12:00:00 by mgumberi          #+#    #+#             */
/*   Updated: 2026/05/07 12:00:00 by mgumberi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	parse_phase(t_game *g, char *path)
{
	if (!has_extension(path, ".ber"))
		error_exit(g, "Map file must have .ber extension");
	if (!load_map(g, path))
		error_exit(g, "Could not read or parse map file");
	if (!validate_map(g))
		error_exit(g, "Invalid map (chars, dimensions, walls or counts)");
	if (!check_path(g))
		error_exit(g, "No valid path from player to exit and collectibles");
	g->map.grid[g->map.player_y][g->map.player_x] = '0';
}

static void	graphics_phase(t_game *g)
{
	if (!init_mlx(g))
		error_exit(g, "Failed to initialize MiniLibX");
	render_frame(g);
	setup_hooks(g);
	mlx_loop(g->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc != 2)
		error_exit(&game, "Usage: ./so_long <map.ber>");
	parse_phase(&game, argv[1]);
	graphics_phase(&game);
	cleanup(&game);
	return (0);
}
