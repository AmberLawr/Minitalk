/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:04:54 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/20 18:07:28 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	mod;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd((n = n * (-1)), fd);
	}
	else if (n >= 0 && n <= 9)
	{
		n = n + '0';
		write(fd, &n, 1);
	}
	else
	{
		mod = n % 10 + '0';
		ft_putnbr_fd(n / 10, fd);
		write(1, &mod, fd);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	index;

	index = 0;
	if (s == 0)
		return ;
	while (s[index] != '\0')
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}
