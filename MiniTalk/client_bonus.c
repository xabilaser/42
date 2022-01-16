/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:47:22 by xlasa-ol          #+#    #+#             */
/*   Updated: 2022/01/14 19:39:24 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
char	*g_checker;

static int	send_signal(int pidnum, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill (pidnum, SIGUSR1);
		else
			kill (pidnum, SIGUSR2);
		usleep(100);
		bit++;
	}
	return (0);
}

void	sig_sender(char *str, pid)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		send_signal(pid, str[i]);
		i++;
	}
}

char	signal_holder(int signal)
{
	static int	bit;
	static int	i;
	char		c;
	size_t		j;

	j = 0;
	while (g_checker[j] != '\0')
	{
		if (signal == SIGUSR1)
			i |= (0x01 << bit);
			bit++;
		if (bit == 8)
		{
			g_checker[j] = c;
			bit = 0;
			i = 0;
		}
		j++;
	}
	return (c);
}

int	main(int argc, char **argv)
{
	int	servpid;

	if (argc == 3)
	{
		servpid = ft_atoi(*argv[1]);
		sig_sender(servpid, to_send);	
		ft_putstr_fd("\033[92mSignal correctly sended\033[0m\n", 1);
	}
	else
	{
		ft_putstr_fd("\033[97mUse 3 arguments including:\033[0m", 1);
		ft_putstr_fd("\033[93m./client [PID] [String_to_send]\033[0m\n", 1);
		return (1);
	}
	if (//recibe la señal de sigaction)
		ft_putstr_fd("\033[96mMessage correctly received from server\033[om", 1);
	return (0);
}
