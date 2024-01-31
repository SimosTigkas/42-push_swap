NAME= push_swap.a

FUNC= \
	index.c \
	push_swap.c \
	push.c \
	rev_rotate.c \
	rotate.c \
	small_sort.c \
	stack_analysis.c \
	swap.c \
	utils.c \
	validity_of_args.c

INC = includes

OBJ = $(FUNC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(LIBFT):
	cd libfta && $(MAKE) && $(MAKE) bonus

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c $? -o $@

clean:
	rm -f $(OBJ)
	cd libfta && $(MAKE) clean

fclean:	clean
	rm -f $(NAME) 
	cd libfta && $(MAKE) fclean

re: fclean all

.PHONY all clean fclean re