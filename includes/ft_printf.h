/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:35:25 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/15 15:45:17 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define SPECIFIER "cspdiuxX%"
# define FLAGS "-0.# +"

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

char	*ft_function1(char *s, int i);
void	ft_function2(int a, char b);

#endif