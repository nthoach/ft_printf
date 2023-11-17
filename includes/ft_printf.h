/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:35:25 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/16 18:47:39 by nthoach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define SPECIFIER "cspdiuxX%"
# define FLAGS "-0.# +"
/*
typedef struct s_printf
{
	va_list	args;
	char	*str_ip;
	char	flags;
	int		wdth;
	int		precn;
	char	specf;
	int		len_th;
	int		poi_nt;
	int		das_h;
	int		tl;
	int		sign;
	int		is_zero;
	int		perc;
	int		sp;
}	t_printf;
*/

int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_hex(uintptr_t n, char format);
int	ft_print_ptr(unsigned long long ptr);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);

#endif