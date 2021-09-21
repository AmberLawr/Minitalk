/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:13:09 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/20 17:49:38 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

static char	*compare(unsigned long n, char *result, int base)
{
	int	i;

	if (result == 0)
		return (0);
	if (n == 0)
		result[0] = '0';
	i = 8;
	while (n || i > 0)
	{
		result[--i] = ((n % base) + '0');
		n = n / base;
	}
	return (result);
}

char	*ft_itobase(unsigned long n, int base)
{
	char	*result;

	result = (char *)malloc(9 * sizeof(char));
	if (result == 0)
		return (0);
	result = compare(n, result, base);
	result[8] = '\0';
	return (result);
}

static int	is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\r')
		return (1);
	else if (c == '\f' || c == '\v' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	while (is_space(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + ((int)*str - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
		str++;
	}
	return (sign * result);
}
