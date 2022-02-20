# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 18:23:55 by xlasa-ol          #+#    #+#              #
#    Updated: 2021/12/14 18:30:00 by xlasa-ol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap.a

SRCS	= push_swap.h\
		  push_swap_utils.c\
		  ps_actions.c\
		  ps_errors.c\
		  push_swap.c

OBJS	= $(SRCS:.c=.o)

LIBC	= ar rcs

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

INCS	= push_swap.h

$(NAME): $(OBJS) $(INCS)
	$(LIBC) $(NAME) $(OBJS)

all: 	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fcleank re .c .o
