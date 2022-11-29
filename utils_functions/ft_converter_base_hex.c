/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter_base_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:26:23 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/17 02:04:27 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_converter_base_hex(unsigned long int n, char format, int *size)
{
	int	base_char;

	if (n >= 16)
		ft_converter_base_hex(n / 16, format, size);
	if (n % 16 < 10)
		ft_putchar_fd(48 + (n % 16), 1);
	else
	{
		if (format == 120)
			base_char = 87;
		else
			base_char = 55;
		ft_putchar_fd(base_char + (n % 16), 1);
	}
	(*size)++;
}
