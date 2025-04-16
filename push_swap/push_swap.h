/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:13:35 by faikhan           #+#    #+#             */
/*   Updated: 2025/02/04 19:02:04 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef MAX_FD
#  define MAX_FD 4096
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
	int	arg_flag;
}	t_stack;

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*extract_line(char *read_line);
char	*search_for_line(int fd, char *for_read, char *for_storing);
void	push_swap(char **argv, int flag);
void	push_a(t_stack *ptr, int print);
void	push_b(t_stack *ptr, int print);
void	swap_a(t_stack *ptr, int print);
void	swap_b(t_stack *ptr, int print);
void	swap_s(t_stack *ptr, int print);
void	rotate_a(t_stack *ptr, int print);
void	rotate_b(t_stack *ptr, int print);
void	rotate_r(t_stack *ptr, int print);
void	rev_rot_a(t_stack *ptr, int print);
void	rev_rot_b(t_stack *ptr, int print);
void	rev_rot_r(t_stack *ptr, int print);
void	error_atoi(t_stack *ptr, char **argv);
void	check_error(int *pile_a, int *pile_b);
void	check_double(int *ptr, int *ptr2, int size);
void	three_numbers_stack_a(t_stack *three);
void	temporary_sort(int *array, int size);
void	quicksort_three_a_and_b(t_stack *pile, int len);
void	free_pile(int *pile_a, int *pile_b);
void	free_array(char **ptr);
int		ft_isdigit(char c);
int		ft_push(t_stack *pile, int len, int push);
int		push_swap_len(char **argv);
int		check_sorted(int *ptr, int size, int order);
int		p_s_atoi(char *str, t_stack *ptr, char **argv);
int		sort(t_stack *pile, int size);
int		median_of_numbers(int *pivot, int *pile, int size);
int		quicksort_stack_a(t_stack *pile, int len, int count_r);
int		three_numbers_stack_b(t_stack *pile, int len);
int		quicksort_stack_b(t_stack *pile, int len, int count_r);
int		ft_strcmp(char *s1, char *s2);

#endif
