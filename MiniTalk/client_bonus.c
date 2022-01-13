/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:47:22 by xlasa-ol          #+#    #+#             */
/*   Updated: 2022/01/13 18:02:32 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

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

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		c = (char)i;
		bit = 0;
		i = 0;
	}
	return (c);
}

int	pid_checker(int pid)
{
	char	*str;

	str = itoa(pid);
	while (str[i])
	{
		signal(SIGUSR1, signal_holder);
		signal(SIGUSR2, signal_holder);
		pause();
	}
}

int	main(int argc, char **argv)
{
	int		servpid;
	int		clientpid;
	size_t	i;

	i = 0;
	clientpid = getpid();
	ft_putnbr_fd(clientpid);
	if (argc == 3)
	{
		argc += 1;
		servpid = ft_atoi(argv[1]);
		sig_sender(servpid, *argv[2]);
		argv[3][] = itoa(clientpid);
		sig_sender(clientpid, *argv[3]);		
		ft_putstr_fd("\033[92mSignal correctly sended\033[0m\n", 1);
	}
	else
	{
		ft_putstr_fd("\033[97mUse 3 arguments including:\033[0m", 1);
		ft_putstr_fd("\033[93m./client [PID] [String_to_send]\033[0m\n", 1);
		exit(EXIT_FAILURE);
		return (1);
	}
	if (clientpid == pid_checker(clientpid));
		ft_putstr_fd("\033[96mMessage correctly received from server\033[om", 1);
	return (0);
}
