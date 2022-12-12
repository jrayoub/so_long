/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:34:56 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/28 02:34:58 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



void	move_enemy(t_map *map, t_coordinations *cords)
{
	remove_enemy(map, cords);
	if (cords->orientation == 0)
	{
		if (check_enemy_path(map, (cords->x + 1), cords->y))
			cords->x++;
		else
			cords->orientation = 1;
	}
	if (cords->orientation == 1)
	{
		if (check_enemy_path(map, (cords->x - 1), cords->y))
			cords->x--;
		else
			cords->orientation = 0;
	}
	remove_enemy(map, cords);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->block->enemy_block_1,
		(cords->x * BLOCK_SIZE), (cords->y * BLOCK_SIZE));
}

int	enemy_pos_iter(void *content, t_map *map, int sec_counter)
{
	t_coordinations	*cords;

	cords = (t_coordinations *)content;
	render_enemy(map, sec_counter, cords);
	if (sec_counter == 5550)
		move_enemy(map, cords);
	if (map->cords->x == cords->x && map->cords->y == cords->y)
	{
		end_game(map, "GAME OVER!");
		return (-1);
	}
	return (0);
}

void	move_enemies(t_map *map, int sec_counter)
{
	ft_lstiter(&map->game->enemies_pos, enemy_pos_iter, map, sec_counter);
}

void	enemies_pos(const char *s, t_map *map, int y)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == 'N')
			ft_lstadd_back(&map->game->enemies_pos, ft_lstnew(new_cords(i, y)));
		i++;
	}
}

void	remove_enemy(t_map *map, t_coordinations *cords)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->block->grass_block,
		(cords->x * BLOCK_SIZE), (cords->y * BLOCK_SIZE));
	if (map->map_l[cords->y][cords->x] == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->block->foor_block,
			(cords->x * BLOCK_SIZE), (cords->y * BLOCK_SIZE));
}
