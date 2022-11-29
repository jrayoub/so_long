/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:34:41 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/28 02:34:47 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_hero(t_map *map, int sec_counter)
{
	if (sec_counter == 2550 || sec_counter == 5500)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->grass_block, (map->cords->x * BLOCK_SIZE),
			(map->cords->y * BLOCK_SIZE));
	if (sec_counter == 2550)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->hero_block_1, (map->cords->x * BLOCK_SIZE),
			(map->cords->y * BLOCK_SIZE));
	else if (sec_counter % 5500 == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->hero_block_2, (map->cords->x * BLOCK_SIZE),
			(map->cords->y * BLOCK_SIZE));
}

void	render_enemy(t_map *map, int sec_counter, t_coordinations *enemy_cords)
{
	if (sec_counter == 1550 || sec_counter == 3500 || sec_counter == 4500)
		remove_enemy(map, enemy_cords);
	if (sec_counter == 1550)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->enemy_block_1, (enemy_cords->x * BLOCK_SIZE),
			(enemy_cords->y * BLOCK_SIZE));
	else if (sec_counter % 3500 == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->enemy_block_2, (enemy_cords->x * BLOCK_SIZE),
			(enemy_cords->y * BLOCK_SIZE));
	else if (sec_counter % 4500 == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->enemy_block_3, (enemy_cords->x * BLOCK_SIZE),
			(enemy_cords->y * BLOCK_SIZE));
}

int	animate(t_map *map)
{
	static int	sec_counter;
	static int	delay;

	if (map->is_game_over)
	{
		if (delay == 5500)
		{
			mlx_destroy_window(map->mlx, map->mlx_win);
			exit(0);
		}
		delay++;
	}
	else
	{
		render_hero(map, sec_counter);
		sec_counter++;
		move_enemies(map, sec_counter);
		if (sec_counter == 5550)
			sec_counter = 0;
	}
	return (0);
}
