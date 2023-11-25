NAME=libftprintf.a
SRC= printf/ft_printf.c printf/print_types.c printf/print_u.c
SRC_BONUS= bonus/ft_printf_bonus.c bonus/print_c_bonus.c bonus/print_i_or_d_bonus.c bonus/print_s_bonus.c bonus/print_u_bonus.c \
bonus/print_x_bonus.c bonus/print_x2_bonus.c bonus/print_p_bonus.c bonus/convert_hex_bonus.c bonus/ft_utoa_bonus.c
OBJ=$(SRC:.c=.o)
OBJ_BONUS=$(SRC_BONUS:.c=.o)
LIB_PATH= ./libft


all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) bonus -C $(LIB_PATH)
		ar rcs $(NAME) $(OBJ) $(LIB_PATH)/*.o

bonus: fclean $(OBJ_BONUS)
		$(MAKE) bonus -C $(LIB_PATH)
		ar rcs $(NAME) $(OBJ_BONUS) $(LIB_PATH)/*.o

%.o: %.c
		gcc -Wall -Werror -Wextra -c $< -o $@

clean:
		$(MAKE) clean -C $(LIB_PATH)
		rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
		$(MAKE) fclean -C $(LIB_PATH)
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus