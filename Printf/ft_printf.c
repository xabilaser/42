/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:35:29 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/10/27 12:35:23 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_pdefine(va_list ap, int count, char c)
{
	if (c == 'c')
		count += ft_putchar(va_arg(ap, int));
	if (c == 's')
		count += ft_putstr(va_arg(ap, char *));
	if (c == 'p')
		count += ft_putstr("0x") + ft_puthex(va_arg(ap, size_t), c);
	if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	if (c == 'u')
		count += ft_putunbr(va_arg(ap, unsigned int));
	if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(ap, size_t), c);
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int		count;
	size_t	i;

	count = 0;
	va_start(ap, input);
	i = 0;
	while (input[i])
	{
		if (input[i] == '%')
			count = ft_pdefine(ap, count, input[i++]);	
		else
			count += ft_putchar(input[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
