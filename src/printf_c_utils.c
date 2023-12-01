/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:39:12 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 17:36:08 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
