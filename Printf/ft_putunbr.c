/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:17:42 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/10/27 11:33:25 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count = count + ft_putunbr(n / 10);
		count = count + ft_putchar((n % 10) + 48);
	}
	return (count);
}
