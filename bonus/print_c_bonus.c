/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hoach Nguyen <honguyen@student.42abudhabi.ac>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:43:57 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 17:43:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	print_c(t_flags *inf)
{
	char	c;

	c = va_arg(inf->arg, int);
	if (inf->width && inf->minus == 1)
		print_c1(inf, c);
	else if (inf->width && inf->minus == 0)
		print_c2(inf, c);
	else
	{
		write(1, &c, 1);
		inf->size++;
	}
	return (inf->size);
}

static void print_c1(t_flags *inf, char c)
{
	write(1, &c, 1);
	inf->width--;
	inf->size++;
	while (inf->width > 0)
	{
		write(1, " ", 1);
		inf->width--;
		inf->size++;
	}
}

static void print_c2(t_flags *inf, char c)
{
	inf->width--;
	while (inf->width)
	{
		write(1, " ", 1);
		inf->width--;
		inf->size++;
	}
	write(1, &c, 1);
	inf->size++;
}
