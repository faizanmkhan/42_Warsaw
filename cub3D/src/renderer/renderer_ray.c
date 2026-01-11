/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:58:54 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:22:50 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/renderer.h"

void	init_ray_direction(t_data *data, t_ray *r, double camera_x)
{
	r->raydir_x = data->dir.x + data->plane.x * camera_x;
	r->raydir_y = data->dir.y + data->plane.y * camera_x;
	r->map_x = (int)data->player.x;
	r->map_y = (int)data->player.y;
	if (r->raydir_x == 0)
		r->delta_dist_x = 1e30;
	else
		r->delta_dist_x = fabs(1.0 / r->raydir_x);
	if (r->raydir_y == 0)
		r->delta_dist_y = 1e30;
	else
		r->delta_dist_y = fabs(1.0 / r->raydir_y);
}

void	init_ray_steps(t_data *data, t_ray *r)
{
	if (r->raydir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (data->player.x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - data->player.x) * r->delta_dist_x;
	}
	if (r->raydir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (data->player.y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - data->player.y) * r->delta_dist_y;
	}
}

void	init_ray(t_data *data, t_ray *r, double camera_x)
{
	init_ray_direction(data, r, camera_x);
	init_ray_steps(data, r);
}

void	perform_dda(t_data *data, t_ray *r)
{
	while (1)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_x < 0 || r->map_y < 0 || r->map_x >= data->rows
			|| r->map_y >= data->cols)
			break ;
		if (data->map[r->map_x][r->map_y] == '1')
			break ;
	}
}
