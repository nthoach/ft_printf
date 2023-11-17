/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   *ft_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:34:21 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/04 16:34:21 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int n)
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

static	char	*ft_uitoa(unsigned int n)
{
	char		*str;
	int			len;

	len = ft_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n && len >= 0)
	{
		len--;
		str[len] = '0' + n % 10;
		n /= 10;
	}
	return (str);
}

int	ft_print_unsigned(unsigned int n)
{
	int		printed_byte;
	char	*str;

	printed_byte = 0;
	str = ft_uitoa(n);
	printed_byte += ft_print_str(str);
	free(n);
}
