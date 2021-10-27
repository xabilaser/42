/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:40:47 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/10/27 11:26:42 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(size_t num, char c)
{
	size_t	count;

	count = 0;
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
