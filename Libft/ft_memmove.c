/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:09:08 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/23 11:57:46 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!src && !dest)
		return (NULL);
	if (dest > src)
	{
		while (len--)
			*(char *)(dest + len) = *(char *)(src + len);
	}
	else
	{
		while (len--)
			((char *)dest)[++i] = *(char *)src++;
	}
	return ((char *)dest);
}
