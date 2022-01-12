#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "./libft/libft.h"

static int	send_signal(int clientpid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill (clientpid, SIGUSR1);
		else
			kill (clientpid, SIGUSR2);
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
	// CREAR VARIABLE STRING Y SEPARAR PID (NUMEROS DEL FINAL 5?). DESPUÉS ESCRIBIR STRING (MENSAJE)
	//¿METER CARACTER SEPARADOR PARA DIFERENCIAR Y SEPARAR CON SUBSTRING O SPLIT?
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
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
	// FALTA PROCESAR LA SEÑAL PARA EXTRAER EL PID DEL CLIENTE Y ENVIARLO CON SEND_SIGNAL
	send_signal(clientpid, );
	return (0);
}
