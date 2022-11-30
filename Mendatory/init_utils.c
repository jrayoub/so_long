/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:35:05 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/28 02:35:07 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_coordinations	*new_cords(int x, int y)
{
	t_coordinations	*cords;

	cords = malloc(sizeof(t_coordinations));
	cords->x = x;
	cords->y = y;
	cords->orientation = 0;
	return (cords);
}

t_game_satate	*init_game_satate(void)
{
	t_game_satate	*game_state;

	game_state = malloc(sizeof(t_game_satate));
	game_state->availables_c = 0;
	game_state->eaten_c = 0;
	game_state->hero_moves = 0;
	return (game_state);
}

void	init_map(t_map *map, int width, int i, void *mlx)
{
	map->mlx = mlx;
	map->h = (i) * BLOCK_SIZE;
	map->w = width;
	map->mlx_win = mlx_new_window(mlx, width, map->h - BLOCK_SIZE, "SO_LONG");
	map->map_l = malloc(i * sizeof(char *));
	map->is_game_over = 0;
	map->cords = new_cords(0, 0);
}

void	init_blocks(t_map *map)
{
	int	h;
	int	w;

	h = 0;
	w = 0;
	map->block = malloc(sizeof(t_blockes));
	map->block->brick_block = mlx_xpm_file_to_image(map->mlx,
			"./textures/blocks/brick.xpm", &h, &w);
	map->block->grass_block = mlx_xpm_file_to_image(map->mlx,
			"./textures/blocks/grass.xpm", &h, &w);
	map->block->door_block = mlx_xpm_file_to_image(map->mlx,
			"./textures/blocks/door.xpm", &h, &w);
	map->block->foor_block = mlx_xpm_file_to_image(map->mlx,
			"./textures/blocks/food.xpm", &h, &w);
	map->block->hero_block_1 = mlx_xpm_file_to_image(map->mlx,
			"./textures/characters/hero/__1.xpm", &h, &w);
}

t_map	*init_window(void *mlx, char *level)
{
	int		i;
	char	*line;
	int		fd;
	int		width;
	t_map	*map;

	i = 1;
	map = malloc(sizeof(t_map));
	map->game = init_game_satate();
	fd = open(level, O_RDONLY);
	invalide_fd(fd);
	line = get_next_line(fd);
	width = (ft_strlen(line) - 1) * BLOCK_SIZE;
	while (line != NULL)
	{
		map->game->availables_c += obj_on_map_chr(line, 'C');
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	close(fd);
	init_map(map, width, i, mlx);
	init_blocks(map);
	return (map);
}
