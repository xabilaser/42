#include <unistd.h>

int	ft_putlchar(char c)
{
	write(1, &c, 1));
	return (1);
}
