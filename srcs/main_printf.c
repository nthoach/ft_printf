/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:30 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/17 15:38:11 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	s[30] = "Done with string printing!";
	char	s1[30] = "String2\0";
	int		n_p = 0;
	
	n_p = printf("Printing a string:%c:%s:%s:%p:%p:%d:%i:%u:%x:%X:%%:\n",'\t', s, NULL, s, s1, -2147483647, INT_MAX, UINT_MAX, 14, UINT_MAX);
	printf(":printed length = %i:\n", n_p);
	n_p = ft_printf("Printing a string:%c:%s:%s:%p:%p:%d:%i:%u:%x:%X:%%:\n",'\t', s, NULL, s, s1, -2147483647, INT_MAX, UINT_MAX, 14, UINT_MAX);
	ft_printf(":printed length = %i:\n", n_p);
	printf("%u%5%\n", 0);
	ft_printf("%u%5%\n", 0);
	return (0);
}