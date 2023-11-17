NAME = libftprintf.a

SRC = ft_printf.c print_formats.c print_unsigned.c ft_itoa.c

# SRC_BONUS = ft_bonus.c ft_bonus2.c */

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

# OBJ_BONUS = $(SRC_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

# bonus : $(OBJ) $(OBJ_BONUS)
#		ar rcs $(NAME) $(OBJ) $(OBJ_BONUS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re