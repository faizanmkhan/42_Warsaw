/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flood_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:57:51 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 22:00:05 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

int	allocate_vstack(t_data *data, t_vstack *s)
{
	int	rows;
	int	cols;

	rows = data->rows;
	cols = data->cols;
	s->visited = calloc(rows * cols, 1);
	if (!s->visited)
		return (-1);
	s->stx = malloc(sizeof(int) * rows * cols);
	s->sty = malloc(sizeof(int) * rows * cols);
	if (!s->stx || !s->sty)
	{
		free(s->visited);
		free(s->stx);
		free(s->sty);
		return (-1);
	}
	return (0);
}

static void	print_map_error(t_data *data, int ox, int oy)
{
	ft_putstr_fd("Error: map is not closed", 2);
	ft_putnbr_fd(ox, 2);
	ft_putstr_fd(",", 2);
	ft_putnbr_fd(oy, 2);
	ft_putstr_fd(") char='", 2);
	ft_putchar_fd(data->map[ox][oy], 2);
	ft_putstr_fd("'\n", 2);
}

void	print_map_open_region(t_data *data, int ox, int oy)
{
	int	rows;
	int	start;
	int	end;
	int	r;

	print_map_error(data, ox, oy);
	rows = data->rows;
	start = ox - 3;
	if (start < 0)
		start = 0;
	end = ox + 3;
	if (end >= rows)
		end = rows - 1;
	r = start;
	while (r <= end)
	{
		ft_putnbr_fd(r, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(data->map[r], 2);
		ft_putstr_fd("\n", 2);
		r++;
	}
}
