/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:04:27 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/04 23:08:32 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	is_walkable(t_data *d, double nx, double ny)
{
	int	mx;
	int	my;

	mx = (int)nx;
	my = (int)ny;
	if (mx < 0 || my < 0 || mx >= d->rows || my >= d->cols)
		return (0);
	return (d->map[mx][my] == '0');
}

void	min_move_forward(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.x + data->dir.x * data->movespeed;
	ny = data->player.y + data->dir.y * data->movespeed;
	if (is_walkable(data, nx, data->player.y))
		data->player.x = nx;
	if (is_walkable(data, data->player.x, ny))
		data->player.y = ny;
	fprintf(stderr, "[move] forward -> player=(%.3f, %.3f) dir=(%.3f, %.3f)\n",
		data->player.x, data->player.y, data->dir.x, data->dir.y);
}

void	min_move_back(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.x - data->dir.x * data->movespeed;
	ny = data->player.y - data->dir.y * data->movespeed;
	if (is_walkable(data, nx, data->player.y))
		data->player.x = nx;
	if (is_walkable(data, data->player.x, ny))
		data->player.y = ny;
	fprintf(stderr, "[move] back -> player=(%.3f, %.3f) dir=(%.3f, %.3f)\n",
		data->player.x, data->player.y, data->dir.x, data->dir.y);
}

void	min_move_left(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.x - data->plane.x * data->movespeed;
	ny = data->player.y - data->plane.y * data->movespeed;
	if (is_walkable(data, nx, data->player.y))
		data->player.x = nx;
	if (is_walkable(data, data->player.x, ny))
		data->player.y = ny;
	fprintf(stderr, "[move] left -> player=(%.3f, %.3f) plane=(%.3f, %.3f)\n",
		data->player.x, data->player.y, data->plane.x, data->plane.y);
}

void	min_move_right(t_data *data)
{
	double	nx;
	double	ny;

	nx = data->player.x + data->plane.x * data->movespeed;
	ny = data->player.y + data->plane.y * data->movespeed;
	if (is_walkable(data, nx, data->player.y))
		data->player.x = nx;
	if (is_walkable(data, data->player.x, ny))
		data->player.y = ny;
	fprintf(stderr, "[move] right -> player=(%.3f, %.3f) plane=(%.3f, %.3f)\n",
		data->player.x, data->player.y, data->plane.x, data->plane.y);
}
