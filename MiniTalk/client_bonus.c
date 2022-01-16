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

static int	cd_send_signal(int pidnum, char c)
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

// En el cliente usamos la misma función que en el servidor, con el mismo prototipo pero diferenete mensaje.
// Solamente necesitamos recibir la señal desde el servidor y mostramos el emnsaje.

void	cd_sig_checker(int sig, siginfo_t *info, void *ucontest_t)
{
	(void)ucontest_t;
	(void)info;
	if (signal == SIGUSR1)
		ft_putstr_fd("\033[96mMessage correctly received from server\033[om", 1);
	//No estoy muy seguro de que sea necesario comprobar SIGUSR2 porque desde el servidor solo se devuelve SIGUSR1, pero por si acaso...
	if (signal == SIGUSR2)
		ft_putstr_fd("\033[96mMessage correctly received from server\033[om", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;
	int			servpid;
	int			x;

	x = 0;
	// se declara el handler con la función que recoge la señal
	sig.sa_handler = (void (*)(int))cd_sig_checker;
	// 
	sigemptyset(&sig.sa_mask);
	//Se identifican las señales recibidas (NULL o 0 porque no hace falta procesarlas.
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	if (argc == 3)
	{
		servpid = ft_atoi(*argv[1]);
		while (argv[2][i] != '\0')
		{
			cd_send_signal(servpid, argv[2][i]);
			i++;
		}
		ft_putstr_fd("\033[92mSignal correctly sended\033[0m\n", 1);
	}
	else
	{
		ft_putstr_fd("\033[97mUse 3 arguments including:\033[0m", 1);
		ft_putstr_fd("\033[93m./client [PID] [String_to_send]\033[0m\n", 1);
		exit(EXIT_FAILURE);
	}
	return (0);
}
