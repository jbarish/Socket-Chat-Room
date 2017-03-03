NAME = liblist.a
CC=gcc
CFLAGS=-Wall -Werror --pedantic -I ../../include -c
SRC= new_node.c add_node.c add_elem.c append.c add_node_at.c remove_node.c remove_node_at.c remove_last.c \
count_s_nodes.c  empty_list.c node_at.c print_int.c print_string.c print_char.c traverse_int.c elem_at.c \
traverse_char.c traverse_string.c node_at.c debug_int.c debug_char.c  debug_string

OBJS= $(SRC:.c=.o)

all:$(OBJS) 
	ar -rc $(NAME) $(OBJS)
	ranlib $(NAME)
	mv $(NAME) ../../lib
clean:
	rm -f $(OBJS)
	rm -f *.c~
fclean: clean
	rm -f ../../lib/$(NAME)
re: fclean all

