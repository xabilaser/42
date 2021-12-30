CC = gcc

CFLAGS = -Werror -Wall -Wextra

SERVER = server
SERVER_SRCS = server.o

CLIENT = client
CLIENT_SRCS = client.o

UTILS = utils
UTILS_SRCS = utils.o

all : $(SERVER) $(CLIENT) $(UTILS)

$(CLIENT_NAME) : $(CLIENT_SRCS)
	@$(CC) $(CLIENT_SRCS) -o $(CLIENT)

$(SERVER_NAME) : $(SERVER_SRCS)
	@$(CC) $(SERVER_SRCS) -o $(SERVER)

$(UTILS_NAME)  : $(UTILS_SRCS)
	@$(CC) $(UTILS_SRCS) -o $(UTILS)

%.o : %.c
	@$(CC) $(FLAGS) $< -c

clean :
	@rm -f client.o server.o
	@printf "\e[31mclean done\e[0m\n"

fclean : clean
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[31mfclean done\e[0m\n"

re : fclean all

.PHONY: all clean fclean re
