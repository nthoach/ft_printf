# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:58:20 by honguyen          #+#    #+#              #
#    Updated: 2023/12/01 17:11:44 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = src

SRCS = $(addprefix $(SRC_DIR)/, \
ft_printf.c \
printf_blank_utils.c \
printf_c.c \
printf_s.c \
printf_sign_utils.c \
printf_d_i.c \
printf_p.c \
printf_u.c \
printf_x.c)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	make -C libft
	mv libft/libft.a libftprintf.a
	ar rcs $(NAME) $(OBJS)
	
$(addprefix $(SRC_DIR), $(OBJS)) : $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

bonus : all
	
clean :
	make -C libft fclean
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re