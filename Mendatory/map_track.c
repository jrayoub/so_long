/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_track.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 02:35:25 by aaitouna          #+#    #+#             */
/*   Updated: 2022/11/28 02:35:26 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_valide_path	*is_valide_path(int x, int y, char **map_l,
	t_valide_path *valide_path)
{
	if (x <= 0 && y <= 0)
		return (valide_path);
	if (map_l[y][x] == '*')
		return (valide_path);
	if (map_l[y][x] == 'C')
		valide_path->eaten_c++;
	else if (map_l[y][x] == 'E')
	{
		valide_path->is_valide = 1;
		return (valide_path);
	}
	map_l[y][x] = '*';
	if (map_l[y - 1][x] != '1')
		is_valide_path(x, y - 1, map_l, valide_path);
	if (map_l[y + 1][x] != '1')
		is_valide_path(x, y + 1, map_l, valide_path);
	if (map_l[y][x - 1] != '1')
		is_valide_path(x - 1, y, map_l, valide_path);
	if (map_l[y][x + 1] != '1')
		is_valide_path(x + 1, y, map_l, valide_path);
	return (valide_path);
}

int	check_walls(t_map *map)
{
	int		not_valide;
	int		i;
	size_t	j;

	not_valide = 0;
	i = 0;
	j = 0;
	while (map->map_l[i])
	{
		j = 0;
		while (map->map_l[i][j])
		{
			if (i == 0 || j == 0 || j == ft_strlen(map->map_l[i]) - 1
				|| i == (map->h - (2 * BLOCK_SIZE)) / BLOCK_SIZE)
			{
				if (map->map_l[i][j] != '1')
					not_valide++;
			}	
			j++;
		}
		i++;
	}
	return (not_valide);
}

int	obj_number(t_map *map, char c)
{
	int	i;
	int	j;
	int	o_count;

	j = 0;
	i = 0;
	o_count = 0;
	while (map->map_l[i])
	{
		j = 0;
		while (map->map_l[i][j])
		{
			if (map->map_l[i][j] == c)
				o_count++;
			j++;
		}
		i++;
	}
	return (o_count);
}

void	strip_nl(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			line[i] = 0;
		i++;
	}
}

int	check_map_formate(t_map *map)
{
	int	p_count;
	int	e_count;
	int	not_valide;
	int	i;

	i = 0;
	while (map->map_l[i + 1])
	{
		strip_nl(map->map_l[i]);
		strip_nl(map->map_l[i + 1]);
		if (ft_strlen(map->map_l[i]) != ft_strlen(map->map_l[i + 1]))
			return (0);
		i++;
	}
	p_count = obj_number(map, 'P');
	e_count = obj_number(map, 'E');
	not_valide = check_walls(map);
	if (e_count != 1 || p_count != 1 || not_valide != 0)
		return (0);
	return (1);
}
