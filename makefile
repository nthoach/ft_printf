# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/01 16:58:20 by honguyen          #+#    #+#              #
#    Updated: 2023/12/01 18:00:52 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC= src/ft_printf.c src/printf_blank_utils.c src/printf_c_utils.c \
	src/printf_c.c src/printf_d_i.c src/printf_p.c src/printf_s.c \
	src/printf_sign_utils.c src/printf_u.c src/printf_x.c
OBJ=$(SRC:.c=.o)
LIB_PATH= ./libft
NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) bonus -C $(LIB_PATH)
		ar rcs $(NAME) $(OBJ) $(LIB_PATH)/*.o

bonus: fclean $(OBJ)
		$(MAKE) bonus -C $(LIB_PATH)
		ar rcs $(NAME) $(OBJ) $(LIB_PATH)/*.o

%.o: %.c
		gcc -Wall -Werror -Wextra -c $< -o $@

clean:
		$(MAKE) clean -C $(LIB_PATH)
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C $(LIB_PATH)
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus