/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:35:29 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/10/21 17:23:28 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_pdefine(va_list ap, char *str, int count)
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
	if (c== 'x' || c == 'X')
		count += ft_puthex(va_arg(ap, unsigned int), c);
	if (c == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	ap;
	int	count;
	char	c;

	count = 0;
	va_start(ap, input);
	while (*input)
	{
		if (c == "%")
			count += ft_pdefine(c);
		else
			count += ft_putchar(input);
		input++;
	}
	va_end(ap);
	return (count);
}
