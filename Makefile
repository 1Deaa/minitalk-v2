#FILS

SERVER	= server.c
CLIENT	= client.c
ATOI	= ft_atoi.c
UTIL	= utilites.c
OBJ_server = $(SERVER:.c=.o) 
#VARS

CC = cc
RM = rm -rf
CFLAGS = -Werror -Wextra -Wall

#COMS

all: server client

bonus: server client

server: $(OBJ_server) ft_printf
	$(CC) -o $@ $< -L/ftprintf -libftprintf.a

client: client ft_printf
	$(CC) $(CFLAGS) $(CLIENT) $(ATOI) $(UTIL) -o $< -Lftprintf -lftprintf

ft_printf:
	make -C ./ftprintf

clean:
	$(RM) $(OBJECTS)
	make -C clean  /ftprintf

fclean: clean
	$(RM) server client /ftprintf/libftprintf.a

re: fclean all

.PHONY: all bonus libft clean fclean re
