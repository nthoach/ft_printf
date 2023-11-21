/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:29:46 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/17 16:07:07 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_print_format(va_list args, const char chr)
{
	int	n_p;

	n_p = 0;
	if (chr == 'c')
		n_p += ft_print_char(va_arg(args, int));
	else if (chr == 's')
		n_p += ft_print_str(va_arg(args, char *));
	else if (chr == 'p')
		n_p += ft_print_ptr(va_arg(args, unsigned long long));
	else if (chr == 'd' || chr == 'i' )
		n_p += ft_print_nbr(va_arg(args, int));
	else if (chr == 'u')
		n_p += ft_print_unsigned(va_arg(args, unsigned int));
	else if (chr == 'x' || chr == 'X')
		n_p += ft_print_hex(va_arg(args, unsigned int), chr);
	else if (chr == '%')
		n_p += ft_print_char('%');
	return (n_p);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		n_p;

	if (!s || !*s)
		return (0);
	va_start(ap, s);
	i = 0;
	n_p = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			n_p += ft_print_format(ap, s[i]);
		}
		else
			n_p += ft_print_char(s[i]);
		i++;
	}
	va_end(ap);
	return (n_p);
}
