/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:48:44 by xlasa-ol          #+#    #+#             */
/*   Updated: 2022/01/14 19:24:03 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
char	*g_message;

char	signal_holder(int signal)
{
	static int	bit;
	static int	i;
	char		c;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		c = i;
		bit = 0;
		i = 0;
	}
	return (c);
}

static int	send_sigserv(int pid, char c)
{
	int	bit;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
		{
			kill (pid, SIGUSR1);
			if (kill == -1)
				ft_putstr_fd("exit\n", 1);
		}
		else
		{
			kill (pid, SIGUSR2);
			if (kill == -1)
				ft_putstr_fd("exit\n", 1);
		}
		usleep(500);
		bit++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Invalid number of arguments\n", 1);
		ft_putstr_fd("Correct format: \033[98m ./server\033[0m\n", 1);
	}
	pid = getpid();
	ft_putstr_fd("This is your pid:\n ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for message...\n", 1);
	while (argc == 1)
	{
		signal(SIGUSR1, signal_holder);
		signal(SIGUSR2, signal_holder);
		pause ();
	}
	return (0);
}
