#include "ft_printf.h"

int ft_putnbr(int n)
{
  int count;

  count = 0;
  if (n == -2147483648)
		return (ft_putlstr("-2147483648"));
  if (n < 0)
  {
    n = n * -1;
    count = ft_putchar('-');
  }
  if (n >= 0 && n <= 9)
	  count = count + ft_putchar(n);
  if (n > 9)
  {
    count = count + ft_putnbr(n / 10);
    count = count + ft_putchar((nbr % 10) + 48)
  }
  return (count);
}
