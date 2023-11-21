/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hoach Nguyen <honguyenn@student.42abudhabi.ae>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:40:11 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 16:40:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printf(const char *str, ...)
{
	int		count;
	t_flags	*inf;
	int		size;

	count = 0;
	size = 0;
	inf = (t_flags *) malloc(sizeof(t_flags));
	if (!inf)
		return (-1);
	va_start(inf->arg, (char *)str);
	while (str[count])
	{
		initialize_flags(inf);
		if (str[count] == '%')
		{
			count += get_flags(&str[count + 1], inf);
			size += use_flags(inf);
		}
		else
			size += write(1, &str[count], 1);
		count++;
	}
	va_end(inf->arg);
	free(inf);
	return (size);
}

void	initialize_flags(t_flags *inf)
{
	inf->letter = '\0';
	inf->minus = 0;
	inf->plus = 0;
	inf->point = 0;
	inf->precision = 0;	
	inf->width = 0;
	inf->space= 0;	
	inf->hashtag = 0;
	inf->zero = 0;	
	inf->size = 0;
}

int	get_flags(const char *s, t_flags *inf)
{
	int	count;

	count = 0;
	while (s[count] == '+' || s[count] == '-'
		|| s[count] == '0' || s[count] == '#'
		|| s[count] == ' ')
	{
		if (s[count] == '+')
			inf->plus = 1;
		if (s[count] == '-')
			inf->minus = 1;
		if (s[count] == '0')
			inf->zero = 1;
		if (s[count] == '#')
			inf->hashtag = 1;
		if (s[count] == ' ')
			inf->space = 1;	
		count++;
	}
	count = get_flags2(s, inf, count);
	inf->letter = s[count];
	return (count + 1);
}

int	get_flags2(char *s, t_flags *inf, int count)
{
	if (s[count] >= '1' && s[count] <= '9')
	{
		inf->width = ft_atoi(s + count);
		while (s[count] >= '0' && s[count] <= '9')
			count++;
	}
	if (s[count] == '.')
	{
		count++;
		inf->point = 1;
		inf->precision = ft_atoi(s + count);
		while (s[count] >= '0' && s[count] <= '9')
			count++;
	}
	return (count);
}

int	use_flags(t_flags *inf)
{
	int	size;

	size = 1;
	if (inf->letter == '%')
		write(1, "%%", 1);
	if (inf->letter == 'c')
		size = print_c(inf);
	if (inf->letter == 's')
		size = print_s(inf);
	if (inf->letter == 'p')
		size = print_p(inf);
	if (inf->letter == 'i' || inf->letter == 'd' )
		size = print_i_or_d(inf);
	if (inf->letter == 'u')
		size = print_u(inf);
	if (inf->letter == 'x')
		size = print_x(inf);
	if (inf->letter == 'X')
		size = print_x2(inf);
}