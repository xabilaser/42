#include <unistd.h>

// Check the same char in the same Strin for previus chars (using len) and in the second string.
int	ft_checksamec(char *str, char c, int len)
{
	int	i;

	i = 0;
  //In this loop len is used for check previous chars before the char checked in
	while (str[i] && i < len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
  //Two counters, one for each string.
	int	i;
	int	idx;

	i = 0;
	idx = 0;
  //Check that the number of arguments are three (program and both strings).
	if (argc == 3)
	{
    //Size the length of the second String for compare.
		while (argv[2][idx])
			idx++;
		while (argv[1][i])
		{//If the char of the first string is not repeated in its String (is unique) it will be written.
			if (ft_checksamec(argv[1], argv[1][i], i) == 0)
				write(1, &argv[1][i], 1);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{ //Check that the char is not checked in previous position of the other string and the same String until it. If both false, write the char.
			if ((ft_checksamec(argv[1], argv[2][i], idx) == 0) && (ft_checksamec(argv[2], argv[2][i], i) == 0))
				write(1, &argv[2][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
/*
Pseudocódigo:
Función checkeo. Recibe una cadena, un char y una longitud en entero.
	- Variables: un contador
	- Bucle para recorrer la cadena hasta la posición dada
		o Si el carácter de la cadena es igual al carácter, se sale de la función y devuelve 1.
	- Si sale del bucle devuelve 0.

Función main con número de argumentos y array de argumentos.
	- Variables: dos contadores
	- Se comprueba que entran los tres argumentos (programa y dos cadenas)
		o Se recorre el segundo string para poner su contador al tamaño de la longitud.
		o Se recorre el primer string  con el primer contador
			 Se comprueba si cada carácter del primer String no se repite su string. Si  no se repite, se imprime.
		o Se reinicia el primer contador a cero y se recorre el segundo string con él.
			 Se comprueba que cada carácter del segundo String no se repite en el primero hasta la longitud del segundo 
			contador y que el mismo carácter no se repite en su string hasta el char anterior. Si no se repite en ninguno 
			de los dos, se imprime.
	- Se imprime el salto de línea y se abandona el programa con return (0). 
*/
