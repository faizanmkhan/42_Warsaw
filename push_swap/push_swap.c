/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:10:30 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/04 19:27:42 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **argv, int flag)
{
	t_stack	pile;
	int		size;
	int		i;

	i = -1;
	pile.arg_flag = flag;
	size = push_swap_len(argv);
	pile.a = malloc(size * sizeof(int));
	if (!pile.a)
		return ;
	pile.size_a = size;
	pile.b = malloc(size * sizeof(int));
	if (!pile.b)
	{
		free(pile.a);
		return ;
	}
	pile.size_b = 0;
	while (++i < size)
		pile.a[i] = p_s_atoi(argv[i], &pile, argv);
	if (pile.arg_flag)
		free_array(argv);
	check_double(pile.a, pile.b, size);
	sort(&pile, size);
	free_pile(pile.a, pile.b);
}

int	main(int argc, char **argv)
{
	char	**split_argv;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			split_argv = ft_split(*argv, 32);
			push_swap(split_argv, 1);
		}
		else
			push_swap(argv, 0);
		return (0);
	}
	return (0);
}
