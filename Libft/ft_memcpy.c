/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:00:35 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/23 11:00:10 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;

	if (dst == src || !n)
		return (dst);
	count = 0;
	while (count < n)
	{
		*((char *)dst + count) = *((char *)src + count);
		count++;
	}
	return (dst);
}
