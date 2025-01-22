CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libft.a

SRCS = ft_atoi.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c\
	ft_putpointer.c ft_putui.c ft_puthex.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
