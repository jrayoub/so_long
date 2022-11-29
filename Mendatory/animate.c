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
			map->block->hero_block, (map->cords->x * BLOCK_SIZE),
			(map->cords->y * BLOCK_SIZE));
	else if (sec_counter % 5500 == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->hero_block, (map->cords->x * BLOCK_SIZE),
			(map->cords->y * BLOCK_SIZE));
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
		if (sec_counter == 5550)
			sec_counter = 0;
	}
	return (0);
}
