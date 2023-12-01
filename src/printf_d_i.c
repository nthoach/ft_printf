/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:22:56 by honguyen          #+#    #+#             */
/*   Updated: 2023/12/01 11:27:00 by honguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	(1) printing signed integer numbers with %d and %i
	[%#d] [%#i] has no effective of # because there is no
	alternative ways to present d or i
	(2) range is singed integer typeof(int)
	(3) Blanks and justify flags printed if width > len(itoa(d_i))
	(4) width < len: no justify, print the whole length
	(5) if .prcn, with precision > len, [000ddd] printed
	(6) [+000dd] [-00dd] [ 00dd], [ ] is only when no -(left justified), 
	and for positive number only
	(7) precision < len -> ignore precison, print whole len
	(8) prescision = 0 && di = 0, no print
	(9) if having "w.p" (having precision), ignore flag "0"
	(10) "+"" will disable " ", and "-" will disable "0"
	exmaples:
	left_justified with "-":
	[(+/-/ )(prc-000)(123)(   )] with "-" left-justified
	right_justified and .precision
	[(  )((+/-/ )(prc-000)(123))] right-justified if width > len
	[(+/-/ )(123)] right-justified if width < len
	right_justified && no .precision and width > len
	no "0": (  )(+- )(123)
	yes "0": (+- )(000-width)(123)
*/

int	print_d_i(unsigned int n, t_formats formats)
{
	int	np;
	int	no_digit;
	
	np = 0;
	no_digit = len_num_str(n);
	
	
	formats.precision = 0;
	np = printf("%d", n);
	return (np);
}
