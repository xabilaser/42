#include "libft.h"

int	ft_isspace(char c)
{
	if (c != '\0')
		if ((c >= 9 && c <=13) || c == 32)
			return (1);
	return (0);
}

int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	dest;
	int	i;

	i = 0;
	dest = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (ft_issign(nptr[i]))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) && nptr[i])
	{
		dest *= 10;
		dest += nptr[i] - '0';
		i++;
	}
	return (dest * sign);
}
