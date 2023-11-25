/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:34:21 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/25 23:21:31 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static	char	*ft_utoa(unsigned int n)
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

int	print_u(va_list ap)
{
	char	*str;
	int		np;
	int		u;

	u = va_arg(ap, unsigned int);
	np = 0;
	str = ft_utoa(u);
	ft_putstr_fd(str, 1);
	np = ft_strlen(str);
	free(str);
	return (np);
}
