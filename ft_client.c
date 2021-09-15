/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:38:21 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/15 17:43:50 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <stdio.h>

void	ft_sendmsg(char *str, int pid)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '0')
		{
			kill(pid, SIGUSR1);
			usleep(30);
		}
		else if (str[i] == '1')
		{
			kill(pid, SIGUSR2);
			usleep(30);
		}
		i++;
	}
}

int	 main(int argc, char **argv)
{
	char	*bi_str;
	int		argcounter;
	int		pid;

	if (argc != 3)
		return (0);
	else
	{
		pid = ft_atoi(argv[1]);
		argcounter = 0;
		while (argv[2][argcounter] != '\0')
		{
			bi_str = ft_itobase(argv[2][argcounter], 2);
			ft_sendmsg(bi_str, pid);
			argcounter++;
			free (bi_str);
		}
	}
}
