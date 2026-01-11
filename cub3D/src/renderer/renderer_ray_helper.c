/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_ray_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:22:53 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:27:08 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/renderer.h"

static double	compute_perp_dist(t_ray *r)
{
	double	dist;

	if (r->side == 0)
		dist = r->side_dist_x - r->delta_dist_x;
	else
		dist = r->side_dist_y - r->delta_dist_y;
	if (dist <= 0.0)
		return (1e-6);
	return (dist);
}

static void	set_draw_limits(t_data *data, int lh, int *ds, int *de)
{
	*ds = -lh / 2 + data->screen_y / 2;
	if (*ds < 0)
		*ds = 0;
	*de = lh / 2 + data->screen_y / 2;
	if (*de >= data->screen_y)
		*de = data->screen_y - 1;
}

void	compute_and_draw(t_data *data, t_ray *r, int x)
{
	t_draw_params	p;

	p.perp_wall_dist = compute_perp_dist(r);
	p.line_height = (int)(data->screen_y / p.perp_wall_dist);
	set_draw_limits(data, p.line_height, &p.draw_start, &p.draw_end);
	p.x = x;
	p.r = r;
	draw_vertical_textured(data, &p);
}
