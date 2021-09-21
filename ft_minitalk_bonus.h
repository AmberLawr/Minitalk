/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jzhou <jzhou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 11:39:38 by jzhou             #+#    #+#             */
/*   Updated: 2021/09/20 18:08:11 by jzhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_BONUS_H
# define FT_MINITALK_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_itoa(int n);
int		ft_strlen(char const *str);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itobase(unsigned long n, int base);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif
