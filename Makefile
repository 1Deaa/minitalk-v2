#FILES

CLIENT	= client.c
SERVER	= server.c
UTIL	= utilites.c

#VARIABLES

RM	= rm -rf

NAME	= server
NAME2	= client

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME) $(NAME2)

$(NAME):
	@$(CC) $(SERVER) $(UTIL) -o server
	@echo "Compiling Server!"
$(NAME2):
	@$(CC) $(CLIENT) $(UTIL) -o client
	@echo "Compiling Client!"


.PHONY: all clean re
