#include "../includes/ft_printf.h"

int ft_printhex(int num, char *c)
{
  int count;

  if (c == 'x' || c == 'p')
  {
    if (num >= 16)
    {
      count = count + ft_puthex((num / 16), c);
      count = count + ft_putchar(HEXMIN[num % 16]);
      return (count);
    }
  }
  if (c == 'X')
  {
    if (num >= 16)
    {
      count = count + ft_puthex((num / 16), c);
      count = count + ft_putchar(HEXMAX[num % 16]);
      return (count);
    }
  }
  return (0);
}
