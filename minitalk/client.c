/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:48:49 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/03 17:19:45 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm_msg(int signum)
{
	if (signum == SIGUSR2)
		write(1, "~* Message Received! *~\n", 24);
}

void	send_signal(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		bit++;
	}
}

static int	mt_atoi(char *str)
{
	unsigned int	i;
	unsigned int	res;

	i = 0;
	res = 0;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10;
		res = res + str[i] - 48;
		i++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = mt_atoi(av[1]);
		while (av[2][i])
		{
			send_signal(pid, av[2][i]);
			i++;
		}
		signal(SIGUSR2, confirm_msg);
		send_signal(pid, '\0');
	}
	else
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
