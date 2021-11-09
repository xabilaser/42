/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:43:30 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/11/09 12:47:24 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putunbr((n / 10) + 48);
	else
		count += ft_putdigit((n % 10) + 48);
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
	count += ft_itoa(n, "0123456789") ;
	return (count);
}

int	ft_itoa(int n, char *base)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while(base[i] != '\0')
		i++;
	if (n / i != 0)
		ft_itoa(n / i, base);
	ft_putchar(base[n % i]);
	while (n != 0)
	{
		n = n / i;
		len++;
	}
	return (len);
}

int	ft_puthex(size_t num, char c)
{
	size_t	count;

	count = 0;
	if (c == 'x' || c == 'p')
			return (ft_itoa(num, HEXMIN));
	if (c == 'X')
		return (ft_itoa(num, HEXMAX));
	return (0);
}
