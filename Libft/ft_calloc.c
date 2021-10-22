/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 20:09:57 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/10 18:32:46 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	total;
	void	*dest;

	total = nelem * elsize;
	dest = malloc(total);
	if (!dest)
		return (0);
	ft_memset(dest, 0, total);
	return (dest);
}
