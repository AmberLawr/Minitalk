/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 20:04:54 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/15 14:39:01 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	if (!s)
		return ;
	while (s[c])
	{
		ft_putchar_fd(s[c], fd);
		c++;
	}
}

int	ft_check_biggest(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (n);
	}
	if (n == 2147483647)
	{
		ft_putstr_fd("2147483647", fd);
		return (n);
	}
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	t;
	char			c;

	t = 0;
	c = n + 48;
	if (!ft_check_biggest(n, fd))
	{
		if (n < 0)
		{
			ft_putstr_fd("-", fd);
			n = -n;
		}
		if (n > 9)
		{
			t = n % 10;
			n /= 10;
			c = t + 48;
			ft_putnbr_fd(n, fd);
		}
		else
		{
			c = n + 48;
		}
		write(fd, &c, 1);
	}
}
