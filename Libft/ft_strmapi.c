/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 21:53:27 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/15 15:28:18 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				j;
	char			*dest;

	i = 0;
	j = 0;
	dest = (char *)malloc((ft_strlen((char *)s) + 1) * sizeof(char));
	if (!s || !f || !dest)
		return (0);
	while (s[j] != '\0')
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	while (dest[i])
	{
		dest[i] = f(i, dest[i]);
		i++;
	}
	return (dest);
}
