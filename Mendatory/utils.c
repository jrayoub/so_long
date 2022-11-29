/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:35:42 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/28 02:35:44 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	obj_on_map_chr(const char *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	set_eaten_c(t_map *map)
{
	map->map_l[map->cords->y][map->cords->x] = '0';
	map->game->eaten_c++;
}

void	refresh_out_put(t_map *map)
{
	int		i;
	char	*eaten;
	char	*moves;

	eaten = ft_itoa(map->game->eaten_c);
	moves = ft_itoa(map->game->hero_moves);
	i = 0;
	while (i < (map->w - BLOCK_SIZE) / BLOCK_SIZE)
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->brick_block, i * BLOCK_SIZE, map->h - BLOCK_SIZE);
		i++;
	}
	mlx_string_put(map->mlx, map->mlx_win, BLOCK_SIZE,
		map->h - BLOCK_SIZE, 0xffffff, eaten);
	mlx_string_put(map->mlx, map->mlx_win, BLOCK_SIZE * 3,
		map->h - BLOCK_SIZE, 0xffffff, moves);
	free(eaten);
	free(moves);
}