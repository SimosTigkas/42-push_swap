NAME= push_swap.a

FUNC= \
	push.c \
	rev_rotate.c \
	rotate.c \
	swap.c

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