/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formats.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:48:20 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/16 18:40:58 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	int	len_str;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len_str = 0;
	while (*str)
		len_str += write(1, str, 1);
	return (len_str);
}

int	ft_print_hex(uintptr_t n, char format)
{
	int	len;

	len = 0;
	if (n > 15)
	{
		len += ft_put_hex(n / 16, format);
		len += ft_put_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_put_char(n + '0');
		else
		{
			if (format == 'x')
				len += ft_put_char(n - 10 + 'a');
			else if (format == 'X')
				len += ft_put_char((n - 10 + 'A'));
		}
	}
	return (len);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	printed_byte;

	printed_byte = 0;
	printed_byte += write(1, "0x", 2);
	if (!ptr)
		printed_byte += write(1, "0", 1);
	else
	{
		printed_byte += ft_put_hex(ptr, 'x');
	}
}

int	ft_print_nbr(int n)
{
	int		len_n;
	char	*str_n;

	str_n = ft_itoa(n);
	len_n = ft_print_str(str_n);
	free(str_n);
	return (len_n);
}
