/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:43:30 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/11/02 14:47:14 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_putnbr((n / 10) + 48);
	else
		count += ft_putdigit((n / 10) + 48);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n *= -1;
		count += ft_putchar('-');
	}
	if (n >= 0 && n <= 9)
		count += ft_putdigit(n);
	if (n > 9)
		count += ft_putnbr((n / 10) + 48);
	else
		count += ft_putdigit((n % 10) + 48);
	return (count);
}

int	ft_puthex(size_t num, char c)
{
	size_t	count;

	count = 0;
	if (c == 'x' || c == 'p')
	{
		if (num >= 16)
			count = count + ft_puthex((HEXMIN[num / 16]), c);
		else
			count = count + ft_putchar(HEXMIN[num % 16]);
	}
	if (c == 'X' || c == 'P')
	{
		if (num >= 16)
			count = count + ft_puthex((HEXMAX[num / 16]), c);
		else
			count = count + ft_putchar(HEXMAX[num % 16]);
	}
	return (count);
}
