CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

NAME = philo
SRCS = actions.c utils.c main.c time.c init.c sim.c

OBJSDIR = objects
OBJS = $(addprefix $(OBJSDIR)/,$(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		
$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJSDIR)
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all
	
.PHONY: all clean fclean re

