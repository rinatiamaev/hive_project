# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Name of the binary
NAME = ft_display_file

# Source files
SRC = ft_display_file.c

# Object files
OBJ = $(SRC:.c=.o)

# Default rule
all: $(NAME)

# Link the object file to create the binary
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Rule to clean object files
clean:
	rm -f $(OBJ)

# Rule to clean object files and the binary
fclean: clean
	rm -f $(NAME)

# Rule to recompile everything
re: fclean all
