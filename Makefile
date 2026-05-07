NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

RM      = rm -f

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS    = src/main.c \
          src/stack_utils.c \
          src/parse_args.c \
          src/sort/sort.c \
          src/ops/swap.c \
          src/ops/push.c \
          src/ops/rotate.c \
          src/ops/reverse_rotate.c \
          src/sort/compute_disorder.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
