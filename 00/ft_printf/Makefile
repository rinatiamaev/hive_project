NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
SRC_DIR = srcs

SRC_FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putpointer.c ft_putui.c ft_puthex.c
OBJS = $(SRC_FILES:.c=.o)

LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_SRC = $(LIBFT_DIR)

all: $(LIBFT_LIB) $(OBJS) ft_printf

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

ft_printf: $(OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_LIB)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)

re: fclean all

