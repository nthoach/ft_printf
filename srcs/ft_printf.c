/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:29:46 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/16 15:00:09 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

// int	ft_put_char(int c)
// {
// 	write(1, &c, 1);
// 	return (1);
// }

// int	ft_put_str(char *str)
// {
// 	int	len_str;

// 	if (!str)
// 		return (0);
// 	len_str = 0;
// 	while (*str)
// 		len_str += write(1, str, 1);
// 	return (len_str);
// }

// int	ft_put_hex(uintptr_t n, char format)
// {
// 	int	len_ptr;

// 	len_ptr = 0;
// 	if (n > 15)
// 	{
// 		len_ptr += ft_putptr(n / 16);
// 		len_ptr += ft_putptr(n % 16);
// 	}
// 	else
// 	{
// 		if (n <= 9)
// 			ft_put_char(n + '0');
// 		else
// 		{
// 			if (format == 'x')
// 				ft_put_char(n - 10 + 'a');
// 			else if (format == 'X')
// 				ft_put_char((n - 10 + 'A'), 1);
// 		}
// 		len_ptr = 1;
// 	}
// 	return (len_ptr);
// }

static int	ft_printformat(va_list args, const char format_type)
{
	int	printed_byte;

	printed_byte = 0;
	if (format_type == 'c')
		printed_byte += ft_print_char(va_arg(args, int));
	else if (format_type == 's')
		printed_byte += ft_print_str(va_arg(args, char *));
	else if (format_type == 'p')
		printed_byte += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format_type == 'd' || format_type == 'i' )
		printed_byte += ft_print_nbr(va_arg(args, int));
	else if (format_type == 'u')
		printed_byte += ft_print_usg(va_arg(args, unsigned int));
	else if (format_type == 'x' || format_type == 'X')
		printed_byte += ft_print_hex(va_arg(args, unsigned int), format_type);
	else if (format_type == '%')
		printed_byte += ft_print_char('%');
	return (printed_byte);
}

int	ft_printf(const char *str_ip, ...)
{
	va_list	args;
	int		i;
	int		printed_byte;

	va_start(args, str_ip);
	i = 0;
	printed_byte = 0;
	while (str_ip[i])
	{
		if (str_ip[i] == '%')
		{
			printed_byte += ft_printformat(args, str_ip[i + 1]);
			i++;
		}
		else
			printed_byte += ft_printchar(str_ip[i]);
		i++;
	}
	va_end(args);
	return (printed_byte);
}
