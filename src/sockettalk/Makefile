SNAME=server
CNAME=client
CC=gcc
CFLAGS=-Wall -Werror --pedantic -I../../include 
LFLAGS=-L../../lib -lmy -llist
SRC=server.c client.c
OBJS= $(SRC:.c=.o)

all: server client
clean:
	rm -f $(OBJS)
	rm -f *.c~
fclean: clean
	rm -f $(SNAME)
	rm -f $(CNAME)
re: fclean all
server: server.o
	$(CC) server.o -o server $(CFLAGS) $(LFLAGS)
client: client.o
	$(CC) client.o -o client $(CFLAGS) $(LFLAGS)