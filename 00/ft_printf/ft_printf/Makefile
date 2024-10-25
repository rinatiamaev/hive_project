# Makefile for ft_printf
NAME = libftprintf.a
# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directories
LIBFT_DIR = libft
SRC_DIR = srcs

# Source files for ft_printf
SRC_FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putpointer.c ft_putui.c ft_puthex.c
OBJS = $(SRC_FILES:.c=.o)

# Library
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_SRC = $(LIBFT_DIR)

# Default target
all: $(LIBFT_LIB) $(OBJS) ft_printf

# Build the libft library
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Create the static library for ft_printf
ft_printf: $(OBJS)
	ar rcs libftprintf.a $(OBJS) $(LIBFT_LIB)

# Compile the source files
%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f libftprintf.a
	rm -f $(LIBFT_LIB)

re: fclean all

