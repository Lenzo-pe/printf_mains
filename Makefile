NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
		\
		utils_put.c utils_len.c \
		utils_conv.c utils_isa.c \
		utils_ism.c utils_util.c \
		utils_alloc.c \
		\
		ft_whatisnext.c ft_settings.c\
		\
		ft_integer.c ft_unsignedint.c \
		ft_hexadecimal.c ft_pointer.c \
		ft_string.c ft_character.c \
		ft_porcent.c \
		\
		ft_mathlab.c \
		\

OBS = $(SRC:.c=.o)

$(NAME): ft_printf.h $(OBS)
	$(CC) $(CFLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBS)

.PHONY: all clean fclean

all: $(NAME)

bonus: all

clean:
	rm -rf $(OBS)

fclean:
	rm -rf $(OBS) $(NAME)