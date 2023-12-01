/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:58 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 17:36:12 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/* print_c:
rules:
// Test cases:
// printf("[%%]\n");					[%]					
// printf("[%2%]\n");					[ %]
// printf("[%-2%]\n");					[% ]
// printf("[%02%]\n");					[0%]
// printf("[%-02%]\n");					[% ]
*/
int	print_c(char c, t_formats formats)
{
	int	n_blank;
	int	np;

	np = 0;
	n_blank = formats.width - 1;
	if (formats.minus == 1)
	{
		np += ft_putnchar(c, 1);
		np += ft_putnchar(' ', n_blank);
	}
	else
	{
		if (formats.zero == 1)
			np += ft_putnchar('0', n_blank);
		else if (formats.zero == 0)
			np += ft_putnchar(' ', n_blank);
		np += ft_putnchar(c, 1);
	}
	return (np);
}
