/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:47:11 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/11/10 11:42:47 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_define(const char *input, int i, va_list ap)
{
	int	count;

	count = 0;
	i += 1;
	if (input[i] == 'c')
		count = ft_putchar(va_arg(ap, int));
	if (input[i] == 's')
		count = ft_putstr(va_arg(ap, char *));
	if (input[i] == 'p')
		count = ft_putstr("0x") + ft_puthex(va_arg(ap, unsigned int), input[i]);
	if (input[i] == 'd' || input[i] == 'i')
		count = ft_putnbr(va_arg(ap, int));
	if (input[i] == 'u')
		count = ft_putunbr(va_arg(ap, unsigned int));
	if (input[i] == 'x' || input[i] == 'X')
		count = ft_puthex(va_arg(ap, unsigned int), input[i]);
	if (input[i] == '%')
	{
		count = 1;
		write(1, "%", 1);
	}
	return (count);
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
