/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:34 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/20 14:28:45 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int				ft_print_char(va_list ap, char car)
{
	char	c;
	int		b;

	b = 0;
	if (car == 'c')
		c = va_arg(ap, int);
	else
		c = va_arg(ap, wint_t);
	ft_prec_min_str(1, "\0");
	ft_putchar(c);
	if (g_noprec == '-')
	{
		if (g_prec == '.')
		{
			if (g_p >= 1)
				b = g_p - 1;
		}
		else if (g_minfd >= 1)
			b = g_minfd - 1;
		while (b--)
			ft_putchar(' ');
	}
	b = ft_len_ret_nbr(8, 1, 0);
	return (1 + b);
}

static void		ft_print_perc_s(int tmp, char g)
{
	if (g_zero == '0' && g_p != 0 && g_prec == '.')
	{
		tmp = g_p-- - 1;
		while (g_p--)
			ft_putchar(g);
	}
	if (g_noprec != '-' && g_prec != '.')
	{
		while (g_minfd-- >= 0)
			ft_putchar(g);
	}
}

int				ft_print_perc(char c)
{
	int		tmp;
	char	g;

	if (g_zero == '0' && g_noprec != '-')
		g = '0';
	else
		g = ' ';
	tmp = 0;
	if (g_minfd >= 1 && g_prec != '.')
		tmp = g_minfd - 1;
	if (g_prec == '.' && g_minfd < 1 && g_p >= 1)
		tmp = g_p - 1;
	g_minfd -= 2;
	ft_print_perc_s(tmp, g);
	ft_putchar(c);
	if (g_noprec == '-' && g_prec != '.')
	{
		while (g_minfd-- >= 0)
			ft_putchar(g);
	}
	return (tmp + 1);
}
