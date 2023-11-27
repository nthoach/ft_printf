/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:29:46 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/27 14:29:13 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(va_list ap)
{
	int	c;

	c = va_arg(ap, int);
	return (write(1, &c, 1));
}

int	print_s(va_list ap)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len += write(1, &str[len], 1);
	return (len);
}

int	print_d_i(va_list ap)
{
	int		n;
	char	*str;
	int		len;

	n = va_arg(ap, int);
	str = ft_itoa(n);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

static int	print_formats(va_list ap, char chr)
{
	int	np;

	np = 1;
	if (chr == '%')
		write(1, "%", 1);
	else if (chr == 'c')
		np = print_c(ap);
	else if (chr == 's')
		np = print_s(ap);
	else if (chr == 'p')
		np = print_p(ap);
	else if (chr == 'd' || chr == 'i' )
		np = print_d_i(ap);
	else if (chr == 'u')
		np = print_u(ap);
	else if (chr == 'x')
		np = print_x(ap);
	else if (chr == 'X')
		np = print_xx(ap);
	return (np);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		np;

	if (!s || !*s)
		return (0);
	va_start(ap, (char *)s);
	i = 0;
	np = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			np += print_formats(ap, s[i]);
		}
		else
			np += write(1, &s[i], 1);
		i++;
	}
	va_end(ap);
	return (np);
}
