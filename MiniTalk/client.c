#include <signal.h>
#include <unistd.h>
#include <libft.h>

static int	send_ascii(pid_t pid, char c)
{
	int	bit;

	bit = 7;
	while (--bit > -1)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
	}
	return (0);
}

static int	send_message(pid_t pid_server, char *str)
{
	int i;

	i = 0;
	while (str[i] >= 32 && str[i] <= 126)
	{
		if (send_ascii(pid_server, str[i]))
			return (1);
		++i;
	}
	i = 0;
	while (i < 7)
	{
		kill(pid_server, SIGUSR1);
		usleep(1000);
		i++;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	int pid_server;

	if (argc < 3)
	{
		write(2, "usage: ./client [pid server] [message]\n", 39);
		return (1);
	}
	if ((pid_server = ft_atoi(argv[1])) == 0)
	{
		write(2, "Unknow PID.\n", 32);
		return (1);
	}
	send_message(pid_server, argv[2]);
	return (0);
}
