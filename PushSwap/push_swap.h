/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:19:07 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/12/14 18:53:51 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}	t_list;

int	main(int argc, char **argv);

#endif
