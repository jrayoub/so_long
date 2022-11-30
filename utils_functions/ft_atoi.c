/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:38:16 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/14 14:38:18 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_atoi(const char *nptr)
{
	int					i;
	unsigned long int	nmbr;
	int					sign;

	i = 0;
	nmbr = 0;
	sign = 1;
	while (nptr[i] && ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign *= -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nmbr *= 10;
		nmbr += nptr[i++] - '0';
		if (nmbr >= LLONG_MAX)
		{
			if (sign < 0)
				return (0);
			else
				return (-1);
		}
	}
	return (sign * nmbr);
}
