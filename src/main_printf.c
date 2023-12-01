/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:21:30 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 16:57:22 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *s = "ABC";
	printf("[This is a test string %%:%15.d:%5c:%-20p:%-5.3x:%-#12X:%-15.10u]\n", 357, 'X', s, 255, 255, UINT32_MAX);
	ft_printf("[This is a test string %%:%15.d:%5c:%-20p:%-5.3x:%-#12X:%-15.10u]\n", 357, 'X', s, 255, 255, UINT32_MAX);
	// printf("%%5%s\n", "Hello");
	// ft_printf("%%5%s\n\n", "Hello");
	// printf(":\001\002\007\v\010\f\r:\n");
	// ft_printf(":\001\002\007\v\010\f\r:\n\n");
	// printf("%u%%\n", 0);
	// ft_printf("%u%%\n\n", 0);
	
	// char	s[5] = "OK!";
	// char	s1[5] = "~";
	// int		np = 0;
	
	// np = printf("%c:\n",'\t');
	// printf("%i:\n", np);
	
	// np = ft_printf("%c:\n",'\t');
	// printf("%i:\n", np);

	// np = printf("%d:\n",100);
	// printf("%i:\n", np);
	
	// np = ft_printf("%d:\n",100);
	// printf("%i:\n", np);
	
	// np = printf("%s:%d:%s\n", s, 100, s1);
	// printf("%i:\n", np);
	// np = ft_printf("%s:%d:%s\n", s, 100, s1);
	// printf("%i:\n", np);
	
	// np = printf("%p:%p:\n", s, s1);
	// printf("%i:\n", np);
	// np = ft_printf("%p:%p:\n", s, s1);;
	// printf("%i:\n", np);
	
	// //n_p = ft_printf("Printing a string:%c:%s:%s:%p:%p:%d:%i:%u:%x:%X:%%:\n",'\t', s,"", s, s1, -2147483647, INT_MAX, UINT_MAX, 14, UINT_MAX);
	return (0);
}
