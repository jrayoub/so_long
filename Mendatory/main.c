/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:35:14 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/28 02:35:15 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_map *map, char *msg)
{
	mlx_clear_window(map->mlx, map->mlx_win);
	mlx_string_put(map->mlx, map->mlx_win,
		(map->w / 2), (map->h / 2), 0xffffff, msg);
	map->is_game_over = -1;
}

int	check_path(t_map *map, int x, int y)
{
	if (map->map_l[y][x] == 'E'
			&& map->game->eaten_c == map->game->availables_c)
		end_game(map, "YOU WON CONGRATULATIONS!");
	else if (map->map_l[y][x] == '1' || (map->map_l[y][x] == 'E'
				&& map->game->eaten_c != map->game->availables_c))
		return (0);
	return (1);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == ESC)
		exite(map, "ESC Clicked");
	if (map->is_game_over)
		return (0);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->block->grass_block,
		(map->cords->x * BLOCK_SIZE), (map->cords->y * BLOCK_SIZE));
	navigate_hero(map, keycode);
	if (!map->is_game_over)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->hero_block_1, (map->cords->x * BLOCK_SIZE),
			(map->cords->y * BLOCK_SIZE));
		if (map->map_l[map->cords->y][map->cords->x] == 'C')
			set_eaten_c(map);
		ft_printf("Moves %d \n", map->game->hero_moves);
	}
	return (0);
}

int	end_program(t_map *game)
{
	free_map(game->map_l);
	game->map_l = NULL;
	exit(0);
}

int	main(int ac, char **av)
{
	t_map	*map;
	void	*mlx;

	if (ac != 2)
	{
		ft_printf("Error : no Map");
		return (0);
	}
	mlx = mlx_init();
	map = init_window(mlx, av[1]);
	draw_map(map, av[1]);
	mlx_key_hook(map->mlx_win, key_hook, map);
	mlx_loop_hook(map->mlx, animate, map);
	mlx_hook(map->mlx_win, 17, 0l, end_program, map);
	mlx_loop(mlx);
}
