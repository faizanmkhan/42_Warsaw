/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:49:58 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/03 19:51:04 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decode_signal(int signum, siginfo_t *info, void *m_info)
{
	static int	bit;
	static int	symbol;

	(void)m_info;
	if (signum == SIGUSR1)
		symbol = symbol | (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		if (symbol == 0)
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR2);
		}
		write(1, &symbol, 1);
		bit = 0;
		symbol = 0;
	}
}

void	mt_putnbr(int nb)
{
	int	digit;

	if (nb > 9)
		mt_putnbr(nb / 10);
	digit = (nb % 10) + 48;
	write(1, &digit, 1);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	sa;

	(void)av;
	if (ac != 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	pid = getpid();
	mt_putnbr(pid);
	write(1, "\n", 1);
	sa.sa_sigaction = decode_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
