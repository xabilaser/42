/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:04:35 by xlasa-ol          #+#    #+#             */
/*   Updated: 2022/02/08 17:45:17 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// main con va_list

int	main(int argc, char **argv)
{
	t_list	stack_a;
	t_list	stack_b;

	if (argc < 2)
		return (NULL);
	stack_a = NULL;
	stack_b = NULL;
	
}

int	search_sz(char *str, size_t i)
{
	int j;

	j = 0;
	while (str[i] > 47 && str[i] < 58)
	{
		j++;
		i++;
	}
	return (j);
}

int	rec_stack(char	*str, int *stack)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*num;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] > 47 && str[i] < 58)
		{
			num = malloc(sizeof(char) * search_sz(str, i) + 1);
			while (str[i] > 47 && str[i] < 58)
				num[j++] = str[i++];
			stack[k] = ft_atoi(num);
			free(*num);
			k++;
		}
		else
		{
			j = 0;
			i++;
		}
	return (*stack);
}

int	main(int argc, char **argv)
{
	int	i;
	int	*fst_stack;

	i = 0;
	if (argc < 2)
		return (cd_noargs(argc)); // error de less arguments. Pasa el int de args
	else if (argc == 2)
	{
		if (argv[1])
