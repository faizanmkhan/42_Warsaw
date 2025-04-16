/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:49:12 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/05 00:25:37 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_error(t_stack *ptr, int print, char *gln)
{
	free(ptr->a);
	free(ptr->b);
	if (print)
		write(2, "Error\n", 6);
	if (gln)
		free(gln);
	exit (1);
}

void	execute_instruction(t_stack *ptr, char *inst)
{
	if (!ft_strcmp(inst, "pa\n"))
		push_a(ptr, 1);
	else if (!ft_strcmp(inst, "pb\n"))
		push_b(ptr, 1);
	else if (!ft_strcmp(inst, "sa\n"))
		swap_a(ptr, 1);
	else if (!ft_strcmp(inst, "sb\n"))
		swap_b(ptr, 1);
	else if (!ft_strcmp(inst, "ss\n"))
		swap_s(ptr, 1);
	else if (!ft_strcmp(inst, "ra\n"))
		rotate_a(ptr, 1);
	else if (!ft_strcmp(inst, "rb\n"))
		rotate_b(ptr, 1);
	else if (!ft_strcmp(inst, "rr\n"))
		rotate_r(ptr, 1);
	else if (!ft_strcmp(inst, "rra\n"))
		rev_rot_a(ptr, 1);
	else if (!ft_strcmp(inst, "rrb\n"))
		rev_rot_b(ptr, 1);
	else if (!ft_strcmp(inst, "rrr\n"))
		rev_rot_r(ptr, 1);
	else
		free_error(ptr, 1, inst);
}

void	read_input(t_stack *ptr)
{
	char	*instuction;

	instuction = get_next_line(0);
	while (instuction)
	{
		execute_instruction(ptr, instuction);
		free (instuction);
		instuction = get_next_line(0);
	}
	if (check_sorted(ptr->a, ptr->size_a, 0) && ptr->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_error(ptr, 0, NULL);
}

void	checker_func(char **argv, int flag)
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
	read_input(&pile);
	free_pile(pile.a, pile.b);
}

int	main(int ac, char **av)
{
	char	**split_av;

	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			split_av = ft_split(*av, 32);
			checker_func(split_av, 1);
		}
		else
			checker_func(av, 0);
		return (0);
	}
	return (0);
}
