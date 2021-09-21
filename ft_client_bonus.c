/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:38:21 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/21 14:43:09 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"
#include <stdio.h>

void	ft_sendmsg(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			usleep(100);
			kill(pid, SIGUSR1);
			pause();
		}
		else if (str[i] == '1')
		{
			usleep(100);
			kill(pid, SIGUSR2);
			pause();
		}
		i++;
	}
}

void	ft_handlesig(int signal)
{
	(void)signal;
}

int	main(int argc, char **argv)
{
	char				*bi_str;
	int					argcounter;
	int					pid;
	struct sigaction	sa;

	if (argc != 3)
		return (0);
	else
	{
		pid = ft_atoi(argv[1]);
		argcounter = 0;
		sa.sa_handler = &ft_handlesig;
		sa.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR2, &sa, NULL);
		while (argv[2][argcounter] != '\0')
		{
			bi_str = ft_itobase(argv[2][argcounter], 2);
			if (bi_str == NULL)
				return (0);
			ft_sendmsg(bi_str, pid);
			argcounter++;
			free (bi_str);
		}
	}
	return (0);
}
