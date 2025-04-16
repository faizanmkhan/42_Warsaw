/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:06:39 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/04 15:49:11 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_atoi(t_stack *ptr, char **argv)
{
	free(ptr->a);
	free(ptr->b);
	write(2, "Error\n", 6);
	if (ptr->arg_flag)
		free_array(argv);
	exit(1);
}

void	check_error(int *pile_a, int *pile_b)
{
	free(pile_a);
	free(pile_b);
	write(2, "Error\n", 6);
	exit (1);
}

int	push_swap_len(char **argv)
{
	int	i;

	i = 0;
	while (*argv)
	{
		argv++;
		i++;
	}
	return (i);
}

void	check_double(int *ptr, int *ptr2, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (ptr[i] == ptr[j])
				check_error(ptr, ptr2);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	check_sorted(int *ptr, int size, int order)
{
	int	i;

	i = 1;
	if (order == 0)
	{
		while (i < size)
		{
			if (ptr[i - 1] > ptr[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		while (i < size)
		{
			if (ptr[i - 1] < ptr[i])
				return (0);
			i++;
		}
		return (1);
	}
}
