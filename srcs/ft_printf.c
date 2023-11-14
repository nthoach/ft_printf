/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:29:46 by honguyen          #+#    #+#             */
/*   Updated: 2023/11/14 20:31:27 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

t_print	*ft_init_tab(t_print *tab)
{
	tab->wdt = 0;
	tab->prc = 0;
	tab->zero = 0;
	tab->pnt = 0;
	tab->dash = 0;
	tab->tl = 0;
	tab->sign = 0;
	tab->is_zero = 0;
	tab->perc = 0;
	tab->sp = 0;
	return (tab);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		output;
	t_print	*tab;

	tab = (t_print *)malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	ft_init_tab(tab);
	va_start(tab->args, format);
	i = -1;
	output = 0;
	while (format[++i])
	{
		if (*format == '%')
			i = ft_evaluate_format(tab, format, i + 1);
		else
			output += write(1, &format[i], 1);
	}
	va_end(tab->args);
	output += tab->tl;
	free(tab);
	return (output);
}

// PRINTF(3)                BSD Library Functions Manual                PRINTF(3)

// NAME
//      printf, fprintf, sprintf, snprintf, asprintf, dprintf, vprintf, vfprintf,
//      vsprintf, vsnprintf, vasprintf, vdprintf -- formatted output conversion

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS
//      #include <stdio.h>

//      int
//      printf(const char * restrict format, ...);

//      int
//      fprintf(FILE * restrict stream, const char * restrict format, ...);

//      int
//      sprintf(char * restrict str, const char * restrict format, ...);

//      int
//      snprintf(char * restrict str, size_t size, const char * restrict format,
//          ...);

//      int
//      asprintf(char **ret, const char *format, ...);

//      int
//      dprintf(int fd, const char * restrict format, ...);

//      #include <stdarg.h>

//      int
//      vprintf(const char * restrict format, va_list ap);

//      int
//      vfprintf(FILE * restrict stream, const char * restrict format,
//          va_list ap);

//      int
//      vsprintf(char * restrict str, const char * restrict format, va_list ap);

//      int
//      vsnprintf(char * restrict str, size_t size, const char * restrict format,
//          va_list ap);

//      int
//      vasprintf(char **ret, const char *format, va_list ap);

//      int
//      vdprintf(int fd, const char * restrict format, va_list ap);

// DESCRIPTION
//      The printf() family of functions produces output according to a format as
//      described below.  The printf() and vprintf() functions write output to
//      stdout, the standard output stream; fprintf() and vfprintf() write output
//      to the given output stream; dprintf() and vdprintf() write output to the
//      given file descriptor; sprintf(), snprintf(), vsprintf(), and vsnprintf()
//      write to the character string str; and asprintf() and vasprintf() dynami-
//      cally allocate a new string with malloc(3).
//  ßExtended locale versions of these functions are documented in
//      printf_l(3).  See xlocale(3) for more information.

//      These functions write the output under the control of a format string
//      that specifies how subsequent arguments (or arguments accessed via the
//      variable-length argument facilities of stdarg(3)) are converted for out-
//      put.

//      The asprintf() and vasprintf() functions set *ret to be a pointer to a
//      buffer sufficiently large to hold the formatted string.  This pointer
//      should be passed to free(3) to release the allocated storage when it is
//      no longer needed.  If sufficient space cannot be allocated, asprintf()
//      and vasprintf() will return -1 and set ret to be a NULL pointer.

//      The snprintf() and vsnprintf() functions will write at most size-1 of the
//      characters printed into the output string (the size'th character then
//      gets the terminating `\0'); if the return value is greater than or equal
//      to the size argument, the string was too short and some of the printed
//      characters were discarded.  The output is always null-terminated, unless
//      size is 0.

//      The sprintf() and vsprintf() functions effectively assume a size of
//      INT_MAX + 1.

//      For those routines that write to a user-provided character string, that
//      string and the format strings should not overlap, as the behavior is
//      undefined.

//      The format string is composed of zero or more directives: ordinary char-
//      acters (not %), which are copied unchanged to the output stream; and con-
//      version specifications, each of which results in fetching zero or more
//      subsequent arguments.  Each conversion specification is introduced by the
//      % character.  The arguments must correspond properly (after type promo-
//      tion) with the conversion specifier.  After the %, the following appear
//      in sequence:

//      o   An optional field, consisting of a decimal digit string followed by a
//          $, specifying the next argument to access.  If this field is not pro-
//          vided, the argument following the last argument accessed will be
//          used.  Arguments are numbered starting at 1.  If unaccessed arguments
//          in the format string are interspersed with ones that are accessed the
//          results will be indeterminate.

//      o   Zero or more of the following flags:

//          `#'          The value should be converted to an ``alternate form''.
//                       For c, d, i, n, p, s, and u conversions, this option has
//                       no effect.  For o conversions, the precision of the num-
//                       ber is increased to force the first character of the
//                       output string to a zero.  For x and X conversions, a
//                       non-zero result has the string `0x' (or `0X' for X con-
//                       versions) prepended to it.  For a, A, e, E, f, F, g, and
//                       G conversions, the result will always contain a decimal
//                       point, even if no digits follow it (normally, a decimal
//                       point appears in the results of those conversions only
//                       if a digit follows).  For g and G conversions, trailing
//                       zeros are not removed from the result as they would oth-
//                       erwise be.
















