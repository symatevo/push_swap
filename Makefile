NAME = push_swap

SRC = push_swap_files/push_swap.c\
		push_swap_files/sort_three.c push_swap_files/sort_five.c \
		push_swap_files/sort_main.c

OBJ = *.o

HEADERS = includes/push_swap.h

LIBFT = libft/libft.a
LIBRARY = library/library.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@${MAKE} -C libft
	@${MAKE} -C library
	@$(CC) $(FLAGS) -c $(SRC) -I$(HEADERS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LIBRARY)
	@mkdir obj
	@mv $(OBJ) ./obj

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -Rf obj
	@${MAKE} -C libft clean
	@${MAKE} -C library clean

fclean: clean
	@/bin/rm -f $(NAME)
	@${MAKE} -C libft fclean
	@${MAKE} -C library fclean

re: fclean all

.PHONY: all clean fclean re
