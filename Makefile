NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= src/main.c \
		  src/stack_utils.c \
		  src/input.c \
		  src/sort.c \
		  src/ops/swap.c \
		  src/ops/push.c \
		  src/ops/rotate.c \
		  src/ops/reverse_rotate.c \
		  src/compute_disorder.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
