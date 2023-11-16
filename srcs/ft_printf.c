/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:29:46 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/16 14:06:14 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_putptr(uintptr_t n)
{
	int	len_ptr;

	len_ptr = 0;
	if (n > 16)
	{
		len_ptr += ft_putptr(n / 16);
		len_ptr += ft_putputr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
	}
}

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
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
		printed_byte += ft_putptr(ptr);		
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

int ft_print_usg(unsigned int u)
{
	
}

int ft_print_hex(unsigned int i,  char format_type)
{
	
}

int ft_print_per()
{
	
}

static int ft_printformat(va_list args, const char format_type)
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
