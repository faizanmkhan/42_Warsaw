/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_draw_helper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:44:28 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:07:18 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/renderer.h"

/* texture selection */
struct s_tex	*select_texture(t_data *d, t_ray *r)
{
	if (r->side == 0)
	{
		if (r->raydir_x > 0)
			return (&d->so);
		else
			return (&d->no);
	}
	else
	{
		if (r->raydir_y > 0)
			return (&d->ea);
		else
			return (&d->we);
	}
}

double	calc_wall_x(t_data *d, t_ray *r, double perp_wall_dist)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = d->player.y + perp_wall_dist * r->raydir_y;
	else
		wall_x = d->player.x + perp_wall_dist * r->raydir_x;
	return (wall_x - floor(wall_x));
}

int	calc_tex_x(struct s_tex *tex, t_ray *r, double wall_x)
{
	int	tx;

	tx = (int)(wall_x * (double)tex->width);
	if ((r->side == 0 && r->raydir_x > 0) || (r->side == 1 && r->raydir_y < 0))
		tx = tex->width - tx - 1;
	if (tx < 0)
		tx = 0;
	if (tx >= tex->width)
		tx = tex->width - 1;
	return (tx);
}

unsigned int	sample_tex(struct s_tex *tex, int tx, int ty, int side)
{
	unsigned int	color;

	color = *(unsigned int *)(tex->addr + ty * tex->line_length + tx
			* (tex->bits_per_pixel / 8));
	if (side == 1)
		color = (color >> 1) & 0x7F7F7F;
	return (color);
}

void	min_put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= data->screen_x || y < 0 || y >= data->screen_y)
		return ;
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
