/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:49:15 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/16 14:19:48 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int	ft_putptr(uintptr_t n)
{
	int	len_ptr;

	len_ptr = 0;
	if (n > 15)
	{
		len_ptr += ft_putptr(n / 16);
		len_ptr += ft_putptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
			ft_putchar_fd((n - 10 + 'a'), 1);
		len_ptr = 1;
	}
	return (len_ptr);
}

int	main(void)
{
	printf("\n\n size of pointer: %d\n\n", ft_putptr(4096));
	return (0);
}
