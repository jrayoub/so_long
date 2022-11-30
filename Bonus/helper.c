/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 05:14:48 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/29 05:14:50 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
		free(map[i++]);
	free(map);
}

void	navigate_hero(t_map *map, int keycode)
{
	if (keycode == LEFT
		&& check_path(map, map->cords->x - 1, map->cords->y))
	{
		map->cords->x--;
		map->game->hero_moves++;
	}
	else if (keycode == UP
		&& check_path(map, map->cords->x, map->cords->y - 1))
	{
		map->cords->y--;
		map->game->hero_moves++;
	}
	else if (keycode == RIGHT
		&& check_path(map, map->cords->x + 1, map->cords->y))
	{
		map->cords->x++;
		map->game->hero_moves++;
	}
	else if (keycode == DOWN
		&& check_path(map, map->cords->x, map->cords->y + 1))
	{
		map->cords->y++;
		map->game->hero_moves++;
	}
}

void	exite(t_map *map, char *msg)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	ft_printf("Error : %s\n", msg);
	exit(0);
}

char	**map_l_cpy(t_map *map)
{
	char	**n_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	n_map = malloc((((map->h - BLOCK_SIZE) / BLOCK_SIZE) + 1) * sizeof(void *));
	while (map->map_l[i])
	{
		n_map[i] = malloc(strlen(map->map_l[i]) + 1);
		j = 0;
		while (map->map_l[i][j])
		{
			n_map[i][j] = map->map_l[i][j];
			j++;
		}
		n_map[i][j] = 0;
		i++;
	}
	n_map[i] = 0;
	return (n_map);
}

void	invalide_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("map path is incorrect please try again with valide path");
		exit(0);
	}
}
