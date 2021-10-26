// Variables para la ubicación de los archivos

S = srcs/
I = includes/

// Variable para el nombre de archivo de salida (NAME), para almacenar los nombres de los archivos .c(SRCS) y para la creación de los .o (OBJS)

NAME = libftprintf.a

SRCS = $Sft_printf.c\
       $Sft_putchar.c\
       $Sft_puthex.c\
       $Sft_putnbr.c\
       $Sft_putstr.c\
       $Sft_putunbr.c\
       $Sft_strlen.c\
       
OBJS = $(SRCS:$S%=$O%.o)

// Variables para compilador y remove para cleans

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = -rm -r

// funciones no invocadas

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

//Subfunciones de limpieza de objetos

clean:	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

//Cerrando subfunciones no declaradas para salir del make

.PHONY: all clean fclean re
