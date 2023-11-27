/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:59:02 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/27 16:29:12 by honguyen         ###   ########.fr       */
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
# include "../libft/libft.h"

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
}	t_formats;

/* "cspdiuxX%" flags for mandatory */
/* "-0.# +" flags for bonus */
/* two numbers for length-width */

int	ft_printf(const char *s, ...);


#endif