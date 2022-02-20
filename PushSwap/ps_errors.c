/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:43:17 by xlasa-ol          #+#    #+#             */
/*   Updated: 2022/02/17 14:49:47 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	cd_noargs(int num)
{
	if (num == 1)
	{
		write(1, "No arguments. Ensure your keyboard knowlegment", 46);
		return(0);
	} 
	else if (num > 2)
	{
		write(1, "More enough arguments than needed. Try again.", 31);
		return (0);
	}
}

// Error de stack inválida

void	chk_numerrors(char *str, int num)
{
	if (ft_atoi(str))
		num = ft_atoi(str);
	else
	{
		write (1, "Error", 5);
		return (0);
	}
}
