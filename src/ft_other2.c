/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_other2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:33:10 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/19 16:23:45 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_reset(void)
{
	g_minfd = 0;
	g_noprec = '\0';
	g_prec = '\0';
	g_p = 0;
	g_zero = '\0';
}

int				ft_signed_char(int n)
{
	while (n < -128)
	{
		n = 128 - ((n + 128) * (-1));
		if (n > -128)
			return (n);
	}
	while (n > 127)
	{
		n = (128 - (n - 128)) * (-1);
		if (n < 127)
			return (n);
	}
	return (n);
}

int				ft_unsigned_char(unsigned int n)
{
	n = n & 0xFF;
	return (n);
}

int				ft_len_ret2(int nbflags)
{
	if (g_p != 0 && g_minfd == 0)
		return (g_p);
	else if (g_p > g_minfd)
		return (g_p);
	else if (g_p < g_minfd)
		return (g_minfd);
	else if ((nbflags == 2 || nbflags == 1) && g_p == 0 && g_minfd == 0)
		return (1);
	return (0);
}

char			ft_l_nbr(char *arg, char car, char flags)
{
	int i;

	i = 0;
	if (flags != 'l' && flags != 'L')
	{
		while (arg[i])
		{
			if (arg[i] == 'l')
			{
				if (car == 'd')
				{
					car = 'D';
					return (car);
				}
			}
			i++;
		}
	}
	return (car);
}
