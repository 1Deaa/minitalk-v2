#REGULAR FILES

SERVER	= src/server.c
CLIENT	= src/client.c
UTIL	= src/utilites.c
SERVER_OBJ	= $(SERVER:.c=.o)
CLIENT_OBJ	= $(CLIENT:.c=.o)
UTIL_OBJ	= $(UTIL:.c=.o)

#BONUS FILES

SERVER_BON	= bonus_src/server_bonus.c
CLIENT_BON	= bonus_src/client_bonus.c
UTIL_BON	= bonus_src/utilites_bonus.c
SERVER_BON_OBJ	= $(SERVER_BON:.c=.o)
CLIENT_BON_OBJ	= $(CLIENT_BON:.c=.o)
UTIL_BON_OBJ	= $(UTIL_BON:.c=.o)

#VARS

NAME	= minitalk
RM	= rm -rf
MAKE	= make
CC	= cc
CFLAGS	= -Werror -Wextra -Wall

# COLORS

DEF_COLOR = \e[1;39m
RESET = \e[0m
GRAY = \e[1;90m
RED = \e[1;91m
YELLOW = \e[1;93m
GREEN = \e[1;92m
BLUE = \e[1;94m
MAGENTA = \e[1;95m
CYAN = \e[1;96m
WHITE = \e[1;97m
BLINK = \e[5m

#COMS

all: $(NAME)

$(NAME): server client

server: $(SERVER_OBJ) $(UTIL_OBJ) ft_printf/libftprintf.a
	@$(CC) $(CFLAGS) $(SERVER_OBJ) $(UTIL_OBJ) ft_printf/libftprintf.a -o server

client: $(CLIENT_OBJ) $(UTIL_OBJ) ft_printf/libftprintf.a
	@$(CC) $(CFLAGS) $(CLIENT_OBJ) $(UTIL_OBJ) ft_printf/libftprintf.a -o client

ft_printf/libftprintf.a:
	@$(MAKE) -C ft_printf

$(SERVER_OBJ): $(SERVER)
	@$(CC) $(CFLAGS) -c $(SERVER) -o $(SERVER_OBJ)

$(CLIENT_OBJ): $(CLIENT)
	@$(CC) $(CFLAGS) -c $(CLIENT) -o $(CLIENT_OBJ)

$(UTIL_OBJ): $(UTIL)
	@$(CC) $(CFLAGS) -c $(UTIL) -o $(UTIL_OBJ)

$(SERVER_BON_OBJ): $(SERVER_BON)
	@$(CC) $(CFLAGS) -c $(SERVER_BON) -o $(SERVER_BON_OBJ)

$(CLIENT_BON_OBJ): $(CLIENT_BON)
	@$(CC) $(CFLAGS) -c $(CLIENT_BON) -o $(CLIENT_BON_OBJ)

$(UTIL_BON_OBJ): $(UTIL_BON)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(SERVER_OBJ)
	@$(RM) $(CLIENT_OBJ)
	@$(RM) $(UTIL_OBJ)
	@$(RM) $(SERVER_BON_OBJ)
	@$(RM) $(CLIENT_BON_OBJ)
	@$(RM) $(UTIL_BON_OBJ)
	@echo "$(RED)"
	@$(MAKE) -C ft_printf clean

fclean: clean
	@$(RM) server client
	@$(MAKE) -C ft_printf fclean

re: fclean all

bonus: fclean $(SERVER_BON_OBJ) $(CLIENT_BON_OBJ) $(UTIL_BON_OBJ) ft_printf/libftprintf.a
	@$(CC) $(CFLAGS) $(SERVER_BON) $(UTIL_BON) ft_printf/libftprintf.a -o server
	@$(CC) $(CFLAGS) $(CLIENT_BON) $(UTIL_BON) ft_printf/libftprintf.a -o client

.PHONY: all clean fclean re bonus
