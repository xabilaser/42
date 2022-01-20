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
