#include <unistd.h>

// Check a char into a string. A length is given for check by position and not return duplicates.
int	ft_checksamechar(char *str, char c, int len)
{
	int	i;

	i = 0;
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
  //Two counter, one for each String
	int	i;
	int	len;

	i = 0;
	len = 0;
  //Check the number of arguments: program and two strings. In other case, program exits.
	if (argc == 3)
	{
    //Count second string´s length
		while (argv[2][len])
			len++;
    //Moving along the first string for doing checks
		while (argv[1][i])
		{
      //Check that the char is not checked in previous position of the same String it is (not repeated) and check the same char ib the other string. If both true, write the char.
			if ((ft_checksamechar(argv[1], argv[1][i], i) == 0) && (ft_checksamechar(argv[2], argv[1][i], len) == 1))
				write(1, &argv[1][i], 1);
			i++;
		}
	}
  //Write a line break until finish.
	write(1, "\n", 1);
	return (0);
}
