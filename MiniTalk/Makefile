# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 11:58:27 by xlasa-ol          #+#    #+#              #
#    Updated: 2022/01/10 18:38:09 by xlasa-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER		= server
SERVER_BONUS	= server_bonus
SERVER_SRC	= server.c
SERVER_OBJ	= $(SERVER_SRC:.c=.o)
SERV_BONUS_SRC	= server_bonus.c 

CLIENT		= client
CLIENT_BONUS	= client_bonus
CLIENT_SRC	= client.c
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)
CLI_BONUS_SRC	= client_bonus.c 

LIBFT		= ./libft/libft.a

CC		= gcc

CFLAGS		= -Wall -Werror -Wextra

RM		= rm -rf

all:		$(LIBFT) $(CLIENT) $(SERVER)

$(CLIENT):  $(LIBFT) $(CLIENT_SRC) 
	$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) -o $(CLIENT)
	@echo "\033[92mCliente compilado\033[0m"

$(SERVER): $(LIBFT) $(SERVER_SRC) 
	$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT) -o $(SERVER)
	@echo "\033[92mServidor compilado\033[0m"
	
bonus : $(LIBFT) $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : $(LIBFT) $(CLI_BONUS_SRC)
	$(CC) $(CFLAGS) $(CLI_BONUS_SRC) $(LIBFT) -O $(CLIENT_BONUS)
	@echo "\033[95mClient_bonus compilado\033[0m"
	
$(SERVER_BONUS) : $(LIBFT) $(SERV_BONUS_SRC)
	$(CC) $(CFLAGS) $(SERV_BONUS_SRC) $(LIBFT) -O $(SERVER_BONUS)
	@echo "\033[95mServer_bonus compilado\033[0m"	
	
$(LIBFT): libft/*.c libft/*.h
	$(MAKE) -C libft/

clean: 
	make -C  libft/ clean

fclean: clean
	make -C libft/ clean
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re : fclean all

.PHONY: all clean fclean re bonus
