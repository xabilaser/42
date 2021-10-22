/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 17:04:13 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/23 12:35:28 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*dest;

	i = ft_strlen(s) + 1;
	dest = (char *)s;
	while (i--)
	{
		if ((dest)[i] == (char)c)
			return (&dest[i]);
	}
	return (NULL);
}
