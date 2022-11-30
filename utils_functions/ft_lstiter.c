/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:41:32 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/14 14:41:36 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_lstiter(t_list **lst, int (*f)(void *, t_map *, int),
	t_map *map, int sec_counter)
{
	int	i;

	while ((*lst))
	{
		i = (*f)((*lst)->content, map, sec_counter);
		if (i == -1)
			return ;
		lst = &(*lst)->next;
	}
}
