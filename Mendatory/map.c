/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:35:33 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/28 02:35:35 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	draw_element(t_map *map, void *block, int x, int y)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->block->grass_block, (x * BLOCK_SIZE), (y * BLOCK_SIZE));
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		block, (x * BLOCK_SIZE), (y * BLOCK_SIZE));
}

void	draw_block(t_map *map, char block, int x, int y)
{
	if (block == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->brick_block, (x * BLOCK_SIZE), (y * BLOCK_SIZE));
	else if (block == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->grass_block, (x * BLOCK_SIZE), (y * BLOCK_SIZE));
	else if (block == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->block->door_block, (x * BLOCK_SIZE), (y * BLOCK_SIZE));
	else if (block == 'C')
		draw_element(map, map->block->foor_block, x, y);
	else if (block == 'P')
		draw_element(map, map->block->hero_block, x, y);
	else if (block != '\n')
		exite(map, "Error Element Doesn't Exits");
}

void	check_map(t_map *map)
{
	t_valide_path	*valide_path;
	char			**burt_map;

	if (!check_map_formate(map))
		exite(map, "Map is not valid ..");
	valide_path = malloc(sizeof(t_valide_path));
	valide_path->is_valide = 0;
	valide_path->eaten_c = 0;
	burt_map = map_l_cpy(map);
	valide_path = is_valide_path(map->cords->x, map->cords->y,
			burt_map, valide_path);
	free_map(burt_map);
	free(valide_path);
	if (valide_path->is_valide == 0
		|| valide_path->eaten_c != map->game->availables_c)
		exite(map, "Map has no valide path");
}

void	draw_line(char *line, t_map *map, int y)
{
	int	i;

	i = 0;
	if (!line)
		return ;
	while (line[i])
	{
		draw_block(map, line[i], i, y);
		if (line[i] == 'P')
		{
			map->cords->x = i;
			map->cords->y = y;
		}
		i++;
	}
}

void	draw_map(t_map *map, char *level)
{
	int	fd;
	int	y;

	y = 0;
	fd = open(level, O_RDONLY);
	map->map_l[y] = get_next_line(fd);
	draw_line(map->map_l[y], map, 0);
	while (map->map_l[y] != NULL)
	{
		y++;
		map->map_l[y] = get_next_line(fd);
		draw_line(map->map_l[y], map, y);
	}
	close(fd);
	map->map_l[y] = 0;
	check_map(map);
}
