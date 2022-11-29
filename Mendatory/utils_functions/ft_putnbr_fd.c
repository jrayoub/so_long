/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:02:21 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/14 16:02:23 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	print_number(int fd, unsigned long int num)
{
	char	c;

	if (num >= 10)
		print_number(fd, num / 10);
	c = '0' + num % 10;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long int	nc;

	if (n < 0)
	{
		write(fd, "-", 1);
		nc = (unsigned long)n * -1;
	}
	else
		nc = (unsigned long)n;
	print_number(fd, nc);
}
