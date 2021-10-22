/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:36:26 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/15 15:21:23 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*dest;

	size = ft_strlen(s) + 1;
	dest = (char *)malloc(sizeof(char) * (size));
	if (!dest)
		return (0);
	ft_memcpy(dest, s, size);
	return (dest);
}
