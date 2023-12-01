/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:25:32 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 10:34:12 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(unsigned int x, t_formats formats, char c)
{
	int	np;

	formats.precision = 0;
	c = 'x';
	np = printf("%x", x);
	return (np);
}
