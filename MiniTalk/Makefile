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
SERVER_SRC	= server.c
SERVER_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT		= client
CLIENT_SRC	= client.c
CLIENT_OBJ	= $(CLIENT_SRC:.c=.o)

LIBFT		= ./libft/libft.a

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

all:		$(LIBFT) $(CLIENT) $(SERVER)

$(CLIENT):  $(LIBFT) $(CLIENT_SRC) 
			$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT) -o $(CLIENT)
			@echo "\033[92mCliente compilado\033[0m"

$(SERVER):	$(LIBFT) $(SERVER_SRC) 
			$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT) -o $(SERVER)
			@echo "\033[92mServidor compilado\033[0m"

$(LIBFT):	libft/*.c libft/*.h
			$(MAKE) -C libft/

clean: 
			make -C  libft/ clean

fclean:		clean
			make -C libft/ clean
			$(RM) $(CLIENT) $(SERVER)

re:			fclean all

.PHONY: 	all clean fclean re
