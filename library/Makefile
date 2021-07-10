NAME = library.a

SRC = actions_a.c actions_b.c linked_lst.c midpoint.c stacks.c

HEADERS = library.h

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

CC = gcc

all: $(NAME)

$(NAME):
	@$(CC) $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJECTS)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
