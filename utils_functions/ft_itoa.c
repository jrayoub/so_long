/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:40:10 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/14 14:40:12 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
* @brief recursive function divedes number and reducing from the index then
	call it self untile number has no more then one number
		the start on adding it to string
 * @param s {Char *} emty string to hold the final result
 * @param n {Int} number to be converted
 * @param index {Int} str index
 */
static void	ft_converter(char *s, long int n, int index)
{
	if (n >= 10)
		ft_converter(s, n / 10, index - 1);
	s[index] = '0' + n % 10;
}

/**
 * @brief get the Absolute value of number
 *
 * @param v {Int} given number
 * @return long int always positive
 */
static long int	ft_abs(long int v)
{
	if (v < 0)
		return (v * -1);
	return (v);
}

/**
 * @brief  calculat how many caracter in given number
	+ 1 byte for endofline '/0'
 * @param n {Int} the Given Number.
 * @return {Int} the size of the string to be Allocated
 */
static int	calculat_number_lenght(long int n)
{
	int			buff;
	long int	num_counter;

	buff = 0;
	if (n < 0)
	{
		num_counter = (long)n * -1;
		buff++;
	}
	else
		num_counter = n;
	while (num_counter >= 10)
	{
		num_counter /= 10;
		buff++;
	}
	buff++;
	return (buff);
}

/**
 * @brief Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled.
 *
 * @param n {Int} the integer to convert.
 * @return {Char *} The string representing the integer.
NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	long int	nc;
	int			buff;
	char		*str;

	buff = calculat_number_lenght(n);
	nc = ft_abs(n);
	str = (char *)malloc((sizeof(char) * buff) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	ft_converter(str, nc, buff - 1);
	str[buff] = '\0';
	return (str);
}
