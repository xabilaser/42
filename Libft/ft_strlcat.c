/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 10:23:09 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/15 10:55:05 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	if (n <= ft_strlen(s1))
		return (n + ft_strlen(s2));
	i = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\0' && i + 1 < n)
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (ft_strlen(s1) + ft_strlen(&s2[j]));
}
