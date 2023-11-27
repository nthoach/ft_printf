/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:48:20 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/27 14:32:56 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long n, char format)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += print_hex(n / 16, format);
		len += print_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + '0', 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd(n - 10 + 'a', 1);
			else if (format == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
		len = 1;
	}
	return (len);
}

int	print_p(va_list ap)
{
	int				np;
	unsigned long	p;

	p = va_arg(ap, unsigned long);
	write(1, "0x", 2);
	np = 2;
	np += print_hex(p, 'x');
	return (np);
}

int	print_x(va_list ap)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	return (print_hex(x, 'x'));
}

int	print_xx(va_list ap)
{
	unsigned int	x;

	x = va_arg(ap, unsigned int);
	return (print_hex(x, 'X'));
}
