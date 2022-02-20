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

int	number_sz(char *str, size_t i)
{
	int j;

    j = 0;
    if (str[i] == '-')
    {
        i++;
        j++;
    } 
    if (!(str[i] > 47 && str[i] < 58))
        return (0);
	while (str[i] > 47 && str[i] < 58)
	{
		j++;
		i++;
	}
	return (j);
}

int	*rec_stack(char	*str, int *stack, int i)
{
	size_t	j;
	size_t	k;
	char	*num;

	j = 0;
	k = 0;
	while (str[i])
	{
		if ((str[i] > 47 && str[i] < 58) || str[i] == '-')
		{
			num = malloc(sizeof(char) * number_sz(str, i) + 1);
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
    }
	return (*stack);
}

int	main(int argc, char **argv)
{
	int	*num_stack;

	if (argc != 2)
		return (cd_noargs(argc)); 
	else if (argc == 2)
	{
        num_stack = malloc(sizeof(int) * arr_length(*argv[1]));
        if (rec_stack(*argv[1], num_stack, 0))
            rec_stack(*argv[1], num_stack, 0);
        else
            return (stack_error(num_stack));
    }
    return ;
}
