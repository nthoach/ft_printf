/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:35:25 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/25 23:59:43 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

int	ft_printf(const char *s, ...);
int	print_c(va_list ap);
int	print_s(va_list ap);
int	print_d_i(va_list ap);
int	print_u(va_list ap);
int	print_hex(unsigned long n, char format);
int	print_p(va_list ap);
int	print_x(va_list ap);
int	print_xx(va_list ap);

#endif