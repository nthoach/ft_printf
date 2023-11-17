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

#include "ft_printf.h"

static int	ft_len(int long n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		len = 1;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int long	temp_n;

	temp_n = n;
	len = ft_len(temp_n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		temp_n *= -1;
	}
	if (n == 0)
		str[0] = '0';
	while (temp_n && len >= 0)
	{
		len--;
		str[len] = '0' + temp_n % 10;
		temp_n /= 10;
	}
	return (str);
}
