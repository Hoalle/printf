/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cperrard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:10:37 by cperrard          #+#    #+#             */
/*   Updated: 2018/09/20 14:28:59 by cperrard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static	char	*ft_s_hexa_2(va_list ap, char flags2, unsigned int **c, int nb)
{
	unsigned long int		lc;
	unsigned long long int	llc;
	char					*str;

	str = NULL;
	lc = 0;
	llc = 0;
	if (flags2 == 'l' || flags2 == 'j')
	{
		lc = va_arg(ap, unsigned long int);
		str = ft_long_htoa(lc, nb);
	}
	if (flags2 == 'L' || flags2 == 'z')
	{
		llc = va_arg(ap, unsigned long long int);
		str = ft_longlong_htoa(llc, nb);
	}
	if (llc != 0 || lc != 0)
		**c = 1;
	return (str);
}

static	char	*ft_s_hexa(va_list ap, char flags2, int nb, unsigned int *c)
{
	char					*str;

	str = NULL;
	if (flags2 == 'l' || flags2 == 'j' || flags2 == 'L' || flags2 == 'z')
		str = ft_s_hexa_2(ap, flags2, &c, nb);
	if (flags2 == 'H')
	{
		*c = va_arg(ap, unsigned int);
		str = ft_char_htoa(*c, nb);
	}
	else if (flags2 != 'H' && flags2 != 'j' && flags2 != 'z' && flags2 != 'l' &&
			flags2 != 'L')
	{
		*c = va_arg(ap, unsigned int);
		str = ft_htoa(*c, nb);
	}
	if (*c != 0)
		*c = 1;
	return (str);
}

static	void	ft_g_noprec(int len, int c)
{
	if (g_minfd > len && g_p > len)
	{
		c = g_p - g_minfd;
		while (c--)
			ft_putchar(' ');
	}
	else
	{
		c = g_minfd - len - c;
		while (c--)
			ft_putchar(' ');
	}
}

static	int		ft_s_p_hexa(unsigned int c, char *str, char *arg, char car)
{
	int				ret;
	int				flags;
	int				nb;

	flags = ft_check_flags_hexa(arg);
	if (ft_strcmp(str, "0") == 0 && flags == 4)
		flags = 0;
	ret = ft_prec_min_oxu(flags, ft_strlen(str), arg, car);
	if (c != 0 && ret != 1)
		c = ft_flags_hexa(arg, car);
	ft_putstr(str);
	if (g_noprec == '-' && g_minfd >= (int)ft_strlen(str))
		ft_g_noprec((int)ft_strlen(str), c);
	if (ft_strcmp(str, "0") == 0 && flags == 4)
		flags = 0;
	nb = ft_strlen(str) + ft_len_ret_nbr(flags, (int)ft_strlen(str), 0);
	if (flags == 4 && g_prec == '.' && g_minfd != 0 && g_p == 0)
		nb = nb + 2;
	return (nb);
}

int				ft_print_hexa(va_list ap, char car, char *arg, char flags2)
{
	char			*str;
	unsigned int	c;
	int				nb;

	if (car == 'x')
		nb = 97;
	if (car == 'X')
		nb = 65;
	c = 0;
	str = ft_s_hexa(ap, flags2, nb, &c);
	nb = 0;
	if (ft_strcmp(str, "0") == 0 && g_prec == '.' && (g_zero != '0' || (g_zero
					== '0' && g_minfd == 0)))
		nb = 1;
	if (nb != 1)
		nb = ft_s_p_hexa(c, str, arg, car);
	else if (nb == 1)
	{
		ft_prec_min_oxu(0, 0, NULL, car);
		nb = ft_len_ret2(0);
	}
	free(str);
	return (nb);
}
