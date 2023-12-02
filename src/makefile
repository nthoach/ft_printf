# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:58:20 by honguyen          #+#    #+#              #
#    Updated: 2023/12/02 12:12:19 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = blank_utils.c \
	ft_memset.c \
	ft_printf.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlen.c \
	printf_c.c \
	printf_d_i.c \
	printf_p.c \
	printf_s.c \
	printf_u.c \
	printf_x.c \
	sign_utils.c 
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

bonus: fclean $(OBJ)
		ar rc $(NAME) $(OBJ)

%.o: %.c
		cc -Wall -Werror -Wextra -c $< -o $@

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus