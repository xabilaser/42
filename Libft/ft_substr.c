/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 19:32:14 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/09/02 20:34:51 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *dest;
    size_t  i;
    size_t  count;

    i = 0;
    count = 0;
    if (!s)
        return (0);
    if (start < ft_strlen(s))
        count = ft_strlen(s) - (size_t)start;
    if (len < count)
        count = len;
    dest = (char *)malloc((count + 1) * sizeof(char));
    if (!dest)
        return (0);
    while (count && start < ft_strlen(s))
    {
        dest[i] = ((char *)s)[start + i];
        i++;
        count--;
    }
    dest[i] = '\0';
    return (dest);
}
