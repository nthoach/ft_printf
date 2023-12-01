/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sign_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:54:04 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 14:02:43 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_num_str(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	totalize_len(int n, int no_digit, t_formats *p)
{
	int	len_total;

	len_total = no_digit;
	if (n < 0 || (n >= 0 && (*p).plus == 1)
		|| (n >= 0 && (*p).space == 1))
		(*p).sign = 1;
	if ((*p).precision > no_digit)
		len_total = (*p).precision;
	len_total += (*p).sign;
	//printf("%d\n", len_total);
	return (len_total);
}

int	print_sign(t_formats formats, int n)
{
	int	np;

	np = 0;
	if (n >= 0 && formats.plus == 1)
	{
		np += ft_putnchar('+', 1);
		return (np);
	}
	else if (n >= 0 && formats.space == 1)
	{
		np += ft_putnchar(' ', 1);
		return (np);
	}
	else if (n < 0)
		np += ft_putnchar('-', 1);
	return (np);
}
