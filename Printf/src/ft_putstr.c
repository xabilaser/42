#include <unistd.h>

int *ft_putstr(char *str)
{
  int count;

  count = 0;
  if (!str)
    return (write(1, "(null)", 6));
  while (str[count])
  {
    write(1, str[count], 1);
    count++;
  }
  return (count);
}
