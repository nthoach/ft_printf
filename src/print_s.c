/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:42:47 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 10:14:23 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putxstr(char *s, int len)
{
	write(1, s, len);
	return (len);
}

int	ft_putnchar(char c, int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		return (0);
	else
	{
		while (i < n)
		{
			write(1, &c, 1);
			i++;
		}
	}
	return (n);
}

static void	print_s_blanks(char *s, t_formats formats, int *np)
{
	int	len;
	int	n_blanks;

	len = (int) ft_strlen(s);
	if (formats.dot == 1 && formats.precision < len)
		len = formats.precision;
	n_blanks = formats.width - len;
	if (formats.minus == 1)
	{
		*np += ft_putxstr(s, len);
		*np += ft_putnchar(' ', n_blanks);
	}
	else
	{
		if (formats.zero == 1)
			*np += ft_putnchar('0', n_blanks);
		else if (formats.zero == 0)
			*np += ft_putnchar(' ', n_blanks);
		*np += ft_putxstr(s, len);
	}
}

/* print_s:
	Cases:
	1) %.s <-> %.0s -> print: "" (empty string)				
	2) width < len(s)-> whole string print
	3) width > len(s) -> (width - precsion/len) of blanks
	4) %0 -> underfined
	5) %- -> ignore 0 (left-justified): %-5.1, "Hi" [Hi   ]
	6) s = NULL -> print "(null)"
	7) empty string (*s = '\0') -> print ""
	8) '\0' in the string, printing s is stopped.
*/
int	print_s(char *s, t_formats formats)
{
	int	np;
	int	flag;

	flag = 0;
	if (!s)
	{
		s = ft_strdup("(null)");
		if (!s)
			return (-1);
		flag = 1;
	}
	print_s_blanks(s, formats, &np);
	if (flag == 1)
		free(s);
	return (np);
}
