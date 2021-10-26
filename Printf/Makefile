// Variables para directorios. objs/ no existe pero será creado y eliminado para mantener organizados los .o

O = objs/
I = incs/
S = srcs/

// Variable para el nombre de archivo de salida (NAME), para almacenar los nombres de los archivos .c(SRCS) y para la creación de los .o (OBJS)

NAME = libftprintf.a

SRCS = $Sft_printf.c\
       $Sft_putlchar.c\
       $Sft_putlhex.c\
       $Sft_putlnbr.c\
       $Sft_putlstr.c\
       $Sft_putlunbr.c\
       $Sft_strlen.c\
       
OBJS = $(SRCS:$S%=$O%.o)

// Variables para compilador, flags y libc.

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

// Variable para los parámetros de remove

RM = -rm -r

// funciones no invocadas

all: $(NAME)

// Creación del directorio objects/ y de los .o

$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created.

$(OBJS): | $O
	@echo "Declaring folder as "order-only prerequisite"

$(OBJS): $O%.o: $S%
	@echo "Compiling: $<"
	$(CC) -c $< -o $@
	@echo "Successful compiling!"
  
// compilando librerías

$(NAME): $(OBJS)
	@echo "Compiling library:"
	$(LIBC) $@ $^
	@echo "Successful compiling!"

//Subfunciones de limpieza de objetos

clean:
	$(RM) $O
	@echo "Objects and directory cleaned!"


fclean: clean
	$(RM) $(NAME)
	@echo "Executable cleaned!"

re: fclean all

//Cerrando subfunciones no declaradas para salir del make

.PHONY: all clean fclean re
