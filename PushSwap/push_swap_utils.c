/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:14:17 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/12/14 18:20:35 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int show_results(int moves)
{
    
}

int main_game(int *numbers)
{
    int     *stack_a;
    int     *stack_b;
    float   average;

    while (!order_checker(numbers))
    {
        average = stack_size(numbers) / 2;
    }
}

// Orders *stack[0] hanging *stack[1]'s disorder. This reordering prepares stack with indexes for game movements before converting stack in linked list.
// Aux is used twice as an unconstant auxiliar var and j is used decrecent for ordering each element in its correct position
void    stack_order(int **stack)
{
    size_t  i;
    size_t  j;
    int     aux;

    i = 1;
    while (stack[1][i])
    {
        if (stack[1][i] < stack[1][i - 1])
        {
            j = 1;
            while (j > 0)
            {
                if (stack[1][j] < stack[1][j - 1])
                {
                    aux = stack[0][j - 1];
                    stack[0][j - 1] = stack[0][j];
                    stack[0][j] = aux;
                    aux = stack[1][j - 1];
                    stack[1][j - 1] = stack[1][j];
                    stack[1][j] = aux;
                }
                j--;
            }
        }
        i++;
    }
}
