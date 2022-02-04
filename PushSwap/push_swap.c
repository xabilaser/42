/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:04:35 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/12/14 19:00:00 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main con va_list

int main(int argc, char **argv)
{
	t_list  stack_a;
	t_list  stack_b;

	if (argc < 2)
		return (NULL);
	stack_a = NULL;
	stack_b = NULL;

}

// main con arrays

int main(int argc, char **argv)
{
	int i;
	int *fst_stack;

	i = 0;
	if (argc < 2)
		return (cd_noargs(argc)); // error de less arguments. Pasa el int de args
	else if (argc == 2)
 
	/* 
	 Pseudo:
	 Si hay dos argumentos
	 	si el segundo arg primer *char no es " atoi y a la pila. El resto también y ordenar
		else
		haz split y sacame solo los números (atoi)
		copia uno a uno a la pila
	 */
