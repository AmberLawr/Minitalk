/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:38:25 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/15 17:44:34 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <stdio.h>

void	ft_bitoa(char *str)
{
	int		i;
	int		sum;
	char	sum_char;

	i = 0;
	int	binaryary[] = {128, 64 , 32, 16, 8, 4, 2, 1};
	sum = 0;
	while (i < 8)
	{
		sum = sum + (str[i] - '0') * binaryary[i];
		i++;
	}
	sum_char = (char)sum;
	write(1, &sum_char, 1);
}

void	ft_convertmsg(int signal)
{
	static char	str[9];
	static int	i;

	if (signal == SIGUSR1)
	{
		str[i] = '0';
		i++;
	}
	else if (signal == SIGUSR2)
	{
		str[i] = '1';
		i++;
	}
	if (i == 8)
	{
		str[8] = '\0';
		ft_bitoa(str);
		i = 0;
	}
}

int	 main()
{
	pid_t processid;
	struct sigaction sa;

	processid = getpid();
	write(1, "Server pid: ", 12);
	ft_putnbr_fd((int)processid, 1);
	write(1, "\n", 1);
	sa.sa_handler = &ft_convertmsg;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;

	sigaction(SIGUSR2, &sa, NULL);

	sigaction(SIGUSR1, &sa, NULL);

	while (1)
	{
		pause();
	}
}
