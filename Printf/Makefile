# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 10:17:26 by xlasa-ol          #+#    #+#              #
#    Updated: 2021/10/27 11:04:51 by xlasa-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= ft_printf.c\
		  ft_putchar.c\
		  ft_putnbr.c\
		  ft_putstr.c\
		  ft_putunbr.c\
		  ft_puthex.c\
	  
OBJS	= $(SRCS:.c=.o)

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

INCS	= ft_printf.h

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .c .o
