#include "ft_printf.h"

int	ft_define(const char *input, int i, va_list ap)
{
	int	count;

	count = 0;
	i += 1;
	if (input[i] == 's')
		count = ft_putstr(va_arg(ap, char *));
	if (input[i] == 'd')
		count = ft_putnbr(va_arg(ap, int));
	if (input[i] == 'x')
		count = ft_puthex(va_arg(ap, unsigned int), input[i]);
	if (input[i] == '%')
	{
		count = 1;
		write(1, "%", 1);
	}
	return (count);
}

int	ft_putstr(char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count])
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (write(1, "0", 1);
	if (n < 0)
	{
		n *= -1;
		count += write(1, "-", 1);
	}
	count += ft_itoa(n, "0123456789");
	return (count);
}

int	ft_itoa(size_t n, char *base)
{
	size_t	i;
	int	count;

	i = 0;
	count = 0;
	while (base[i] != '\0')
		i++;
	if (n / i != 0)
		ft_itoa(n / i, base);
	    write(1, &base[n % i], 1);
	while (n != 0)
	{
		n = n / i;
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned int num, char c)
{
	int	count;

	count = 0;
	if (num == 0)
		return (write(1, "0", 1));
    ft_itoa(num, HEXMIN);

	return (0);
}

int	ft_printstr(const char *input, va_list ap)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] != '%')
		{
			write(1, &input[i], 1);
			count++;
			i++;
		}
		else
		{
			count += ft_define(input, i, ap);
			i += 2;
		}
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		len;

	if (!input)
		return (0);
	va_start(ap, input);
	len = ft_printstr(input, ap);
	va_end(ap);
	return (len);
}
