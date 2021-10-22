# printf

<b>Parte obligatoria</b>

        Nombre de programa:       libftprintf.a
        Archivos a entregar:      *.c, */*.c, *.h, */*.h, 
        Makefile:                 Makefile all, clean, fclean, re, bonus
        Funciones autorizadas:    malloc, free, write, va_start, va_arg, va_copy, va_end
        Se permite usar libft:    sí
        Descripción:              Escribe una librería que contenga la función ft_printf, que imite el printf real

<ul>• El prototipo del ft_printf deberá ser int ft_printf(const char *, ...);</ul>
<ul>• Debes programar la función printf de libc.</ul>
<ul>• No tiene por qué gestionar el buffer como lo hace el printf real.</ul>
<ul>• Deberá implementar las siguientes conversiones: cspdiuxX %.</ul>
<ul>• Su funcionamiento se contrastará con el printf original.</ul>
<ul>• Debes utilizar el comando ar para crear tu librería, el uso del comando libtool se prohibe.</ul>

Una pequeña y simple descripción de las conversiones que se te piden:

<ul>• %c para imprimir un solo carácter.</ul>
<ul>• %s para imprimir una string.</ul>
<ul>• %p el puntero void * dado como argumento se imprimirá en hexadecimal.</ul>
<ul>• %d para imprimir un número decimal (de base 10).</ul>
<ul>• %i para imprimir un entero en base 10.</ul>
<ul>• %u para imprimir un número decimal (de base 10) sin signo.</ul>
<ul>• %x para imprimir un número hexadecimal (de base 16), en minúscula.</ul>
<ul>• %X para imprimir un número hexadecimal (de base 16), en mayúscula.</ul>
<ul>• % % para imprimir el signo del porcentaje.</ul>

        Para una referencia completa: man 3 printf / man 3 stdarg

<b>Parte bonus</b>

<ul>• Si la parte obligatoria no está perfecta, no pienses en los bonus.</ul>
<ul>• No tienes por qué hacer todos los bonus.</ul></ul>
<ul>• Gestiona todas las combinaciones de las siguientes flags para todas las conversiones: “-0.” y el flag de longitud mínima (minimum field width).</ul>
<ul>• Gestiona todas las combinaciones de las siguientes flags para todas las conversiones: “# +” (sí, una es un espacio).</ul>
  
        Si tienes intención de hacer los bonus, deberías pensar en cómo
        hacerlos desde el principio para evitar enfocar el proyecto
        incorrectamente.
