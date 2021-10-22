/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 18:21:09 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/23 13:30:48 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*s2)
		return ((char *)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] == s2[j] && n > (i + j))
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
