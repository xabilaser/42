/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:43:30 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/11/10 12:57:20 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return  (ft_putchar('0'));
	count += ft_itoa(n, "0123456789");
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
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
	ft_putchar(base[n % i]);
	while (n != 0)
	{
		n = n / i;
		count++;
	}
	return (count);
}

int	ft_puthex(size_t num, char c)
{
	size_t	count;

	count = 0;
	if (num == 0)
		return (ft_putchar('0'));
	if (num < -2147483648 || num > 2147483647)
		return (-1);
	if (num < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	if (c == 'x' || c == 'p')
		return (ft_itoa(num, HEXMIN));
	if (c == 'X')
		return (ft_itoa(num, HEXMAX));
	return (0);
}
