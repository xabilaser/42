CC = gcc

CFLAGS = -Werror -Wall -Wextra

SERVER_NAME = server
SERVER_SRCS = server.c

CLIENT_NAME = client
CLIENT_SRCS = client.c

UTILS_NAME = utils
UTILS_SRCS = utils.c

all : $(SERVER) $(CLIENT) $(UTILS)

$(CLIENT_NAME) : $(CLIENT_SRCS)
	@$(CC) $(CLIENT_SRCS) -o $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_SRCS)
	@$(CC) $(SERVER_SRCS) -o $(SERVER_NAME)

$(UTILS_NAME)  : $(UTILS_SRCS)
	@$(CC) $(UTILS_SRCS) -o $(UTILS_NAME)

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@rm -f client.o server.o
	@printf "\e[31mclean done\e[0m\n"

fclean : clean
	@rm -f $(SERVER_NAME) $(CLIENT_NAME)
	@printf "\e[31mfclean done\e[0m\n"

re : fclean all

.PHONY: all clean fclean re
