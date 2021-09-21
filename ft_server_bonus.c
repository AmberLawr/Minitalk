/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:38:25 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/21 14:41:51 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"
#include <stdio.h>

void	ft_bitoa(char *str)
{
	int			i;
	int			sum;
	char		sum_char;
	static int	binaryary[] = {128, 64, 32, 16, 8, 4, 2, 1};

	i = 0;
	sum = 0;
	while (i < 8)
	{
		sum = sum + (str[i] - '0') * binaryary[i];
		i++;
	}
	sum_char = (char)sum;
	write(1, &sum_char, 1);
}

void	ft_convertmsg(int signal, siginfo_t *siginfo, void *context)
{
	static char	str[9];
	static int	i;

	(void)context;
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
	usleep(30);
	kill(siginfo->si_pid, SIGUSR2);
}

int	main(void)
{
	pid_t				pid_server;
	struct sigaction	sa;

	pid_server = getpid();
	write(1, "Server pid: ", 12);
	ft_putnbr_fd((int)pid_server, 1);
	write(1, "\n", 1);
	sa.sa_sigaction = &ft_convertmsg;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
