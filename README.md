# Socket-Chat-Room
A text-based TCP Chat Room with an infinite possible number of clients

Run from inside src/sockettalk
Uses custom-built string libraries and linked-list libraries
Uses select() to manage an infinite number of clients

Run the server first, passing in a port as a command argument
Then run the client, with the ip address of the server and server port as arguments 1 and 2, respectively

The following special commands exist on the client end:
/nick [username] - changes your username
/exit - disconnects the user
/me [text] - sends the text to the clients in the following format (note the missing colon): [username] [message]
