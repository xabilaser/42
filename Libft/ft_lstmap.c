/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 13:05:06 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/08/27 11:18:17 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),	void (*del)(void *))
{
	t_list	*ini;
	t_list	*add;

	if (!lst || !f)
		return (0);
	ini = NULL;
	while (lst)
	{
		add = ft_lstnew((*f)(lst->content));
		if (!add)
		{
			ft_lstclear(&ini, del);
			return (0);
		}
		ft_lstadd_back(&ini, add);
		lst = lst->next;
	}
	return (ini);
}
