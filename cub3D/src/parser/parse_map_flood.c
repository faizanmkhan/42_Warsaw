/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_flood.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:46:41 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 22:01:57 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

void	vstack_free(t_vstack *s)
{
	free(s->visited);
	free(s->stx);
	free(s->sty);
}

int	vstack_push(t_vstack *s, int *top, int x, int y)
{
	++(*top);
	s->stx[*top] = x;
	s->sty[*top] = y;
	return (0);
}

int	flood_process_neighbors(t_data *data, t_vstack *s, int *top, int idx)
{
	int			k;
	int			nx;
	int			ny;
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

	k = 0;
	while (k < 4)
	{
		nx = s->stx[idx] + dx[k];
		ny = s->sty[idx] + dy[k];
		if (nx < 0 || ny < 0 || nx >= data->rows || ny >= data->cols)
		{
			vstack_free(s);
			return (1);
		}
		if (!s->visited[nx * data->cols + ny] && data->map[nx][ny] != '1')
		{
			s->visited[nx * data->cols + ny] = 1;
			vstack_push(s, top, nx, ny);
		}
		k++;
	}
	return (0);
}

int	flood_fill_run(t_data *data, t_vstack *s, int *top, int out[2])
{
	int	idx;

	while (*top >= 0)
	{
		idx = *top;
		(*top)--;
		if (s->stx[idx] == 0 || s->sty[idx] == 0 || s->stx[idx] == data->rows
			- 1 || s->sty[idx] == data->cols - 1)
		{
			if (data->map[s->stx[idx]][s->sty[idx]] != '1')
			{
				out[0] = s->stx[idx];
				out[1] = s->sty[idx];
				vstack_free(s);
				return (1);
			}
		}
		if (flood_process_neighbors(data, s, top, idx) != 0)
		{
			return (1);
		}
	}
	return (0);
}

int	flood_fill_check(t_data *data, int *ox, int *oy)
{
	int			sx;
	int			sy;
	t_vstack	s;
	int			top;
	int			out[2];

	sx = (int)data->player.x;
	sy = (int)data->player.y;
	if (sx < 0 || sy < 0 || sx >= data->rows || sy >= data->cols)
		return (-1);
	if (allocate_vstack(data, &s) != 0)
		return (-1);
	top = 0;
	s.stx[top] = sx;
	s.sty[top] = sy;
	s.visited[sx * data->cols + sy] = 1;
	if (flood_fill_run(data, &s, &top, out) != 0)
	{
		*ox = out[0];
		*oy = out[1];
		return (1);
	}
	vstack_free(&s);
	return (0);
}
