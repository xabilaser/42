# get-next-line

Función para checkear memoria. Si es negativa, no existe y se libera el puntero del buffer. (Se saca de la ppal para ahorrar líneas).

<b>void	ft_check_filebt(int filebt, char *bffr)</b>

		if (filebt == -1)
			free(bffr);


Strlen (como en libft, sin modificaciones)

<b>size_t	ft_strlen(char *s)</b>

		size_t	i;

		i = 0;
		if (!s)
			return(0);
		while (s[i] != '\0')
			i++;
		return (i);

Función para encontrar el siguiente caracter de fin de linea (dado) dentro de *str. (como la del libft). 
El salto de línea se recibe desde ft_gnl para conservar la condición cuando termina el texto (cierre de linea = NULL)

<b>char	*ft_strchr(const char *s, int c)</b>

		int	i;

		i = 0;
		if (!s)
			return (0);
		if (c == '\0')
			return ((char *)&s[ft_strlen(s)]);
		while (s[i] != '\0')
		{
			if (s[i] == (char)c)
				return ((char *)&s[i]);
			i++;
		}
		return (0);

Strjoin modificado sobre el del Libft, tal como se comenta

<b>char	*ft_strjoin(char *s1, char *s2)</b>

		size_t	i;
		size_t	j;
		char	*dest;

		if (!s1)
		{
			s1 = (char *)malloc(1 * sizeof(char));
			s1[0] = '\0';

Si no existe línea previa (s1), escribimos null en el primer caracter para 
poder comprobarlo al hacer join y empezar a escribir sobre ella en el dest
	
		if (!s1 || !s2)
			return (NULL);
		s1 = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
		if (!dest)
			return (NULL);
		i = -1;
		j = 0;
	
Con i = -1 comprueba si hay alguna línea anterior y se hace el sumatorio desde el while
para sumar antes de copiar y escribir en dest desde (sobre) el null de la cadena previa.
	
		if (s1)
			while (s1[++i] != '\0')
				dest[i] = s1[i];
		while (s2[j] != '\0')
			dest[i++] = s2[j++];
		dest[ft_strlen(s1) + ft_strlen(s2)] = '\0';
		free(s1);
		return (dest);

Función para copiar la primera línea

<b>char	*ft_get_line(char *file)</b>

		char	*line;
		size_t	i;

		i = 0;
	
Se checkea que exista texto a copiar y se cuentan los chars hasta el salto de línea o final de string

		if (!file)
			return (NULL);
		while (file[i] != '\n' || file[i])
			i++;
		
Se reserva la memoria con dos chars más. Uno para el salto de línea que hay que devolver en todas las líneas y el otro para cerrar el string. Se vuelve a checkear.

		line = (char *)malloc(sizeof(char) * (i + 2))
		if (!line)
			return (NULL);
		i = 0;
	
Se reinicia el contador para proceder a la copia. Se tiene en cuenta cómo tiene que terminar la línea (y el string) {...'\n''\0'}.

		while (file[i] != '\n' || file[i])
			line[i++] = file[i++];
		if (file[i] == '\n')
		{
			line[i] = file [i];
			i++;
		}
		line[i] = '\0';
		return (line);

Función para conservar el resto del texto leido (se entrega en un puntero file) en una variable estática 

<b>char	*next_text(char *file, size_t lines)</b>

		char	*dest;
		size_t	i;
		size_t	j;

		dest = (char *)malloc((sizeof(char) * (BUFFER_SIZE + 1));
		if (!dest)
			return (NULL);
		i = 0;
		while (dest[i] != '\n' || dest[i])
			i++;
		
Condición importante para cuando termina el texto: se libera la memoria del puntero y no se devuelve nada (se ha terminado, no hay txt sobrante)

		if (!file[i])
		{
			free(file);
			return (NULL);
		}
		else 
			i++;
		j = 0;
		while (file[i])
			dest[j++] = file[i++];
		dest[j + 1] = '\0';
		return (dest);

<b>char	*get_next_line(int fd)</b>

Variables:
filebt para memoria destinada al file, 
holder para texto sobrante. Es estática para que se pueda reutilizar la función en bucle.
bffr, para el buffer donde se va a almacenar lo leido desde el FD al hacer read.
dest devuelve la primera línea leída.

		int		filebt;
		char		*bffr;
		char		*dest;
	
0.IMPORTANTE: teniendo en cuenta que la cabecera sobreescribe las funciones cuando se invocan y la variable estática aunque no es global
si permanece, es recomendable que su nombre sea único en esta función para evitar posibles malfuncionamientos.
	
		static char	*holder;
	
1. se le da un valor mínimo al filebt y se checkea que exista FD y que el BUFFER tenga memoria (el 0 ya tendría un puntero disponible)

		filebt = 1;
		if (fd < 0 || BUFFER_SIZE <= 0)
			return (NULL);
		
2. se reserva la memoria para el buffer. Si la memoria falla, se sale de la función.

		bffr = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!bffr)
			return (NULL);
		
3. Si no existe puntero al salto de línea del leftxt (es la primera línea del FD o la 1ª vez que se usa la función), se lee el archivo y se copia a la memoria
reservada para ello. De no existir, se sale de la función. Se limpia el buffer pasando el texto a la variable estática.
	
		while (!ft_strchr(leftxt, '\n') && filebt != 0)
		{
			filebt = read(fd, bffr, BUFFER_SIZE);
			ft_check_filebt(filebt, bffr);
			if (filebt == -1)
				return (NULL);
			bffr[filebt] = '\0';
			lefttxt = ft_strjoin(leftxt, bffr);
		}

4.Llegados aquí, tenemos el texto en la variable estática en todos los casos en que exista (si no se ha extraido línea o si se ha hecho una o más veces).
Se copia la primera línea con la función get_line y se almacena el resto en la variable estática para un posible uso posterior con next_text.
	
		free(bffr);
		dest = ft_get_line(leftxt);
		leftxt = ft_next_text(leftxt);
	
EL APORTE DE AINGERU (comprueba los leaks de memoria al compilar y te dice donde estan si los vas checkeando de uno en uno:
	
		system("leaks a.out");

Se sale de la función devolviendo la línea.

		return (dest);

