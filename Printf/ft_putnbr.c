/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:49:43 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/10/27 12:17:30 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		count = ft_putchar('-');
	}
	if (n >= 0 && n <= 9)
		count += ft_putchar(n);
	if (n > 9)
	{
		count = count + ft_putnbr(n / 10);
		count = count + ft_putchar((n % 10) + 48);
	}
	return (count);
}
