/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:26:23 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/17 02:04:27 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	calc_number_len(int num)
{
	int	i;

	i = ft_calc_num_base_size(num, 10);
	return (i);
}

int	print_and_calc_num(int num)
{
	int	printed_index;

	printed_index = calc_number_len(num);
	ft_putnbr_fd(num, 1);
	return (printed_index);
}

int	print_and_calc_str(char *str)
{
	int	printed_index;

	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	printed_index = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (printed_index);
}

int	print_by_format(va_list ap, char c)
{
	int	printed_index;

	printed_index = 0;
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		printed_index++;
	}
	else if (c == 's')
		printed_index += print_and_calc_str(va_arg(ap, char *));
	else if (c == 'p')
		printed_index += print_ptr_adress(va_arg(ap, size_t));
	else if ((c == 'd' || c == 'i'))
		printed_index += print_and_calc_num(va_arg(ap, int));
	else if (c == 'u')
		ft_put_unsigned(va_arg(ap, unsigned int), &printed_index);
	else if ((c == 'x' || c == 'X'))
		printed_index += print_hex(va_arg(ap, int), c);
	else if (c == '%')
	{
		ft_putchar_fd(c, 1);
		printed_index++;
	}
	return (printed_index);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed_index;
	int		i;

	va_start(ap, str);
	printed_index = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!str[i + 1])
				break ;
			printed_index += print_by_format(ap, str[++i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			printed_index++;
		}
		i++;
	}
	va_end(ap);
	return (printed_index);
}
