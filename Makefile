NAME = push_swap

FUNC = \
	index.c \
	push_swap.c \
	push.c \
	rev_rotate.c \
	rotate.c \
	small_sort.c \
	stack_analysis.c \
	swap.c \
	utils.c \
	validity_of_args.c \
	radix_sort.c

INC = includes

LIBFT = libfta/libft.a

PSNAME = push_swap

OBJ = $(FUNC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I $(INC) $(OBJ) $(LIBFT) -o $(PSNAME)
	chmod +x $(PSNAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	cd libfta && $(MAKE)

clean:
	rm -f $(OBJ)
	cd libfta && $(MAKE) clean

fclean: clean
	rm -f $(PSNAME)
	cd libfta && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re