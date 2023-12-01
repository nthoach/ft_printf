/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:18:01 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 19:57:32 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
	3 cases:
	(1) (prc-zero)(1234)(width-blank) for "%-. "
	(2) (width-blank)(prc-zero)(1234) for ".0" no "-"
	(3) (width-blank)(1234) for " no 0" "no ." no "-"
	(4) (wdt-zero)(1234) for "0" no "-" no "."
*/

static int	total_len(int precision, int len_u)
{
	int	len_total;

	len_total = len_u;
	if (precision > len_total)
		len_total = precision;
	return (len_total);
}

static int	ft_putpnbr(unsigned int n, t_formats formats)
{
	char	c;
	int		np;

	np = 0;
	if (n == 0 && formats.dot == 1 && formats.precision == 0)
		return (0);
	else
	{
		if (n >= 10)
			ft_putpnbr(n / 10, formats);
		c = n % 10 + '0';
		np += ft_putnchar(c, 1);
	}
	return (np);
}

int	print_u(unsigned int u, t_formats formats)
{
	int	np;
	int	len_u;
	int	len_total;

	np = 0;
	len_u = len_x(u, formats);
	len_total = total_len(formats.precision, len_u);
	if (formats.minus == 0 && formats.dot == 0)
	{
		if (formats.zero == 0)
			np += print_width(formats, len_total, ' ');
		else
			np += print_width(formats, len_total, '0');
		np += ft_putpnbr(u, formats);
	}
	else
	{
		if (formats.minus == 0 && formats.dot == 1)
			np += print_width(formats, len_total, ' ');
		np += print_precision(formats, len_u);
		np += ft_putpnbr(u, formats);
		if (formats.minus == 1)
			np += print_width(formats, len_total, ' ');
	}
	return (np);
}
