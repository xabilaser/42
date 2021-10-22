/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 10:33:07 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/09/02 20:55:24 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list  *pos;
    if (lst && del)
    {
        while (*lst)
        {
            pos = (*lst)->next;
            del((*lst)->content);
            free(*lst);
            *lst = pos;
        }
    *lst = NULL;        
    }
}
