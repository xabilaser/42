  El bonus del GNL es sencillo: basta con anidar un límite alto a la variable estática (en mi caso, 4kb) para que interprete un 
  tamaño máximo arbitrario sopesando que nunca se va a recibir un archivo mayor. Una vez hecho el primer READ y conocido el tamaño
  exacto del archivo, se anidará el File Descriptor en su lugar proporcionando el límite exacto a la variable.
  
  	static char	*holder[4096];
  	{..}
  	dest = ft_get_line(holder[fd]);
	holder[fd] = ft_update_holder(holder[fd]);
  
  Para presentar el bonus se harán copias de los archivos get_next_line.c, get_next_line_utils.c y get_next_line.h renombrandolos a
  get_next_line_bonus.c, get_next_line_utils_bonus.c y get_next_line_bonus.h y reescribiendo las dependencias (includes) además de la 
  modificación arriba descrita en el get_next_line_bonus.c.
