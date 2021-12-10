#include <unistd.h>
#include <signal.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	interpreter(int signo)
{
	static size_t	i;
	static int	bit;
	static char	buf[100];

	if (--bit == -1)
	{
		bit = 6;
		++i;
	}
	buf[i] &= ~(1 << 7);
	if (signo == SIGUSR1)
		buf[i] |= (1 << bit);
	else if (signo == SIGUSR2)
		buf[i] &= ~(1 << bit);
	if (i == 99 || buf[i] == 127)
	{
		buf[i] = 0;
		write(STDOUT_FILENO, buf, i + 1);
		ft_memset(buf, '\0', 99);
		i = 0;
		bit = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t pid;

	(void)argv;
	if (argc != 1)
	{
		write(STDERR_FILENO, "usage: ./server\n", 16);
		return (1);
	}
	else
	{
		pid = getpid();
		ft_putnbr_fd(pid, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
		while (42)
		{
			signal(SIGUSR1, interpreter);
			signal(SIGUSR2, interpreter);
		}
	}
}
