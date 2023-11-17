/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:30 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/17 16:16:50 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	// char	s[30] = "Done with string printing!\n";
	// char	s1[30] = "String2\0";
	// int		n_p = 0;
	
	// n_p = printf("Printing a string:%c:%s:%s:%p:%p:%d:%i:%u:%x:%X:%%:\n",'\t', s, NULL, s, s1, -2147483647, INT_MAX, UINT_MAX, 14, UINT_MAX);
	// printf(":printed length = %i:\n", n_p);
	// n_p = ft_printf("Printing a string:%c:%s:%s:%p:%p:%d:%i:%u:%x:%X:%%:\n",'\t', s, NULL, s, s1, -2147483647, INT_MAX, UINT_MAX, 14, UINT_MAX);
	// ft_printf(":printed length = %i:\n", n_p);
	// printf("%u%5%\n", 0);
	// ft_printf("%u%5%\n", 0);
	printf("%%5\n");
	ft_printf("%%5\n");
	printf(":\001\002\007\v\010\f\r:\n");
	ft_printf(":\001\002\007\v\010\f\r:\n");
	return (0);
}
