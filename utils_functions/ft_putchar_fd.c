/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaitouna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:43:59 by aaitouna          #+#    #+#             */
/*   Updated: 2022/10/14 16:07:33 by aaitouna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/**
 * @brief Outputs the character ’c’ to the given file
descriptor.
 *
 * @param c The character to output.
 * @param fd  The file descriptor on which to write.
 * @return None
 *
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
