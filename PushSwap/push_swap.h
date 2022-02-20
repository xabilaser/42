/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:19:07 by xlasa-ol          #+#    #+#             */
/*   Updated: 2022/02/17 14:49:56 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "./libft/libft.h"
#include <unistd.h>
#include <stdio.h>

/*typedef struct s_list
{
	int				*content;
	struct s_list	*next;
}	t_list; */

int     main(int argc, char **argv);
int	    number_sz(char *str, size_t i);
int     *rec_stack(char *str, int *stack);
int     cd_noargs(int num);
void	chk_numerrors(char *str, int num);
void    stack_error(void);
int     stack_size(int *stack);
int     **stack_indexer(int *stack);
int     order_checker(int *stack);
int     replace_i(int *stack, size_t j, size_t i);
int     stack_order(int **stack);
int 	show_results(int moves);
int 	main_game(int *numbers);

#endif
