/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hoach Nguyen <honguyenn@student.42abudhabi.ae>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:11:41 by marvin            #+#    #+#             */
/*   Updated: 2023/11/21 16:11:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONNUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct s_flags
{
	va_list	arg;
	char		letter;
	int		minus;
	int		plus;
	int		point;
	int		precision;	
	int		width;
	int		space;	
	int		hashtag;
	int		zero;
	int		size;		

}	t_flags;

int	ft_printf(const char *s, ...);
int	get_flags(const char *s, t_flags *inf);
int	use_flags(t_flags *inf);
int	print_c(t_flags *inf);
int	print_i_or_d(t_flags *inf);
int	print_s(t_flags *inf);
int	print_u(t_flags *inf);
int	print_x(t_flags *inf);
int	print_x2(t_flags *inf);
int	print_p(t_flags *inf);
char	*convert_hex(unsigned int x);
char	*convert_hex2(unsigned int x2);
char	*convert_hex3(unsigned long p);
char	*ft_utoa(unsigned int n);
void	initialize_flags(t_flags *inf);

#endif