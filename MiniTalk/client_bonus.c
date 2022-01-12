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

void	signal_holder(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}

void	message_received(int servpid, int clientpid)
{
	while (argc == 1)
	{
		signal(SIGUSR1, signal_holder);
		signal(SIGUSR2, signal_holder);
		pause ();
	}
	if (servpid == clilentpid)
		ft_putstr_fd("\033[92mSignal correctly received by server\033[0m\n", 1);
}

int	main(int argc, char **argv)
{
	int	servpid;
	int	clientpid;
	size_t	i;

	i = 0;
	clientpid = getpid();
	if (argc == 3)
	{
		servpid = ft_atoi(argv[1]);
		while (argv[2][i++] != '\0')
			send_signal(servpid, argv[2][i]);
		send_signal(servpid, clientpid);
		ft_putstr_fd("\033[92mSignal correctly sended\033[0m\n", 1);
	}
	else
	{
		ft_putstr_fd("\033[97mUse 3 arguments including:\033[0m", 1);
		ft_putstr_fd("\033[93m./client [PID] [String_to_send]\033[0m\n", 1);
		exit(EXIT_FAILURE);
		return (1);
	}
	message_received(clientpid);
	return (0);
}
