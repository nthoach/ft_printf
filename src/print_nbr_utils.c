/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:54:04 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 13:01:23 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_num_str(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	totalize_len(int n, int no_digit, t_formats *p)
{
	int	len_total;

	len_total = no_digit;
	if (n < 0 || (n >= 0 && (*p).plus == 1)
		|| (n >= 0 && (*p).space == 1))
		(*p).sign = 1;
	if ((*p).precision > no_digit)
		len_total = (*p).precision;
	len_total += (*p).sign;
	return (len_total);
}

int	print_sign(t_formats formats, int n)
	{
		int	np;
				
		np = 0;
		return (np);
	}
	
int	print_precision(t_formats formats, int no_digit)
	{
		int	np;
				
		np = 0;
		return (np);
	}

int print_width(t_formats formats, int len_total)	
	{
		int	np;
				
		np = 0;
		return (np);
	}

void	ft_putnbr(int n, int *p_np)
{
	
}
