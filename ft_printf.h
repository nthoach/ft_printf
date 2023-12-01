/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:59:02 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 19:56:53 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
/* In standard C lib., used inside: printf, scanf
providing va_list type and macros: va_start, 
va_list, va_arg, va_end*/
# include <unistd.h>
/* in libc for UNIX standard - POSIX input/ouput, file...
read, write, close, lseek, , access, unlink, chdir, 
fork, exec, getpid, exit, STDIN_FILENO, STDOU_FILENO, 
STDERR_FILENO, getcwd, sleep, alarm */
# include <stddef.h>
/* for NULL */
# include "libft/libft.h"
//# include <stdio.h>

typedef struct s_formats
{
	int	minus;
	int	zero;
	int	dot;
	int	sharp;
	int	space;
	int	plus;
	int	width;
	int	precision;
	int	sign;
}	t_formats;

/* "cspdiuxX%" flags for mandatory */
/* "-0.# +" flags for bonus */
/* two numbers for length-width */

int		ft_printf(const	char *s_in, ...);
int		print_c(char c, t_formats formats);
int		ft_putxstr(char *s, int len);
int		ft_putnchar(char c, int n);
int		print_s(char *s, t_formats formats);
int		print_p(unsigned long p, t_formats formats);
int		print_d_i(int n, t_formats formats);
int		print_u(unsigned int u, t_formats formats);
int		print_x(unsigned int x, t_formats formats, char c);
int		print_precision(t_formats formats, int no_digit);
int		print_width(t_formats formats, int len_total, char c);
int		len_s_base(long long n, int base);
int		len_x(unsigned int n, t_formats formats);
int		totalize_len(int n, int no_digit, t_formats *p);
int		print_sign(t_formats formats, int n);
void	ft_putnbr(int n, int *p_np);
void	print_hex(unsigned long n, char x, t_formats formats, int *np);
int		print_0x(t_formats formats, char c, unsigned int x);
#endif