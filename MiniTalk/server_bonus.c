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
#include "libft/libft.h"

/* Estructura propia de la función sigaction:

struct sigaction {
    void    (*sa_handler)(int);    addr of signal handler, or SIG_IGN, or SIG_DFL 
    sigset_t    sa_mask;           additional signals to block 
    int    sa_flags;               signal options
};

*/

// Según el man de sigaction, el handler tiene que tener el siguiente prototipo:

void	cd_sig_handler(int signal, siginfo_t *info, void *ucontest_t)
{
	static int	bit;
	static int	i;

	//como solo necesitamos el tipo de variable, las vaciamos por si tuvieran contenido de algún otro proceso:
	(void)ucontest_t;
	(void)info;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
	// enviar la señal al emisor del mensaje utilizando su pid (si_pid).
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	//Declaramos la estructura de la función sigaction que está comentada arriba
	struct sigaction	sig;
	int			pid;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Invalid number of arguments\n", 1);
		ft_putstr_fd("Correct format: \033[98m ./server\033[0m\n", 1);
		return (1);
	}
	pid = getpid();
	ft_putstr_fd("This is your pid:\n ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\nWaiting for message...\n", 1);
	//Enviamos la subrutina handler a la función que recoge la señal:
	sig.sa_handler = (void(*)(int))cd_sig_handler;
	//se inicializa la máscara de la señal hacia el puntero de la máscara de sigaction:
	sigemptyset(&sig.sa_mask);
	//No hay flags para sigaction (no son necesarios):
	sig.sa_flags = 0;
		while (argc == 1)
	{
		signal(SIGUSR1, signal_holder);
		signal(SIGUSR2, signal_holder);
		pause ();
	}
	return (0);
}
