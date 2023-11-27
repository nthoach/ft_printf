/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:59:58 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/27 19:13:43 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* print_s:
	Cases:
	1) %.s <-> %.0s -> print: "" (empty string)				
	2) width < len(s)-> whole string print
	3) width > len(s) -> (width - precsion/len) of blanks
	4) %0 -> underfined
	5) %- -> ignore 0 (left-justified)
	6) s = NULL -> print "(null)"
	7) empty string (*s = '\0') -> print ""
	8) '\0' in the string, printing s is stopped.
*/
int	print_s(char *s, t_formats formats)
{
	int	n_blank;
	int	np;
	int	flag;

	np = 0;
	if(is_null(&s, &flag) == 0)
		return (-1);
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
}
