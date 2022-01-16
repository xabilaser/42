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

/* Estructura de sigaction
struct sigaction {
    void    (*sa_handler)(int);    addr of signal handler, or SIG_IGN, or SIG_DFL 
    sigset_t    sa_mask;           additional signals to block 
    int    sa_flags;               signal options
};
*/

void	cd_sig_handler(int signal)
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

int	main(int argc, char **argv)
{
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
	sig.sa_handler = (void(*)(int))cd_sig_handler;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
		while (argc == 1)
	{
		signal(SIGUSR1, signal_holder);
		signal(SIGUSR2, signal_holder);
		pause ();
	}
	return (0);
}
