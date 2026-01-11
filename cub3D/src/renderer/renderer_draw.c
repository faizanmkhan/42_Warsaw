/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_draw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:58:32 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:07:11 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/renderer.h"

static void	draw_ceiling(t_data *d, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		min_put_pixel(d, x, y, d->ceiling_color);
		y++;
	}
}

static void	draw_floor(t_data *d, int x, int start_y)
{
	int	y;

	y = start_y;
	while (y < d->screen_y)
	{
		min_put_pixel(d, x, y, d->floor_color);
		y++;
	}
}

void	draw_wall_pixels(t_data *d, t_draw_params *p, t_wall_vars *wv)
{
	int	y;

	y = p->draw_start;
	while (y <= p->draw_end)
	{
		if (!wv->use_texture)
			draw_wall_pixel_no_tex(d, p, y);
		else
			draw_wall_pixel_tex(d, p, wv, y);
		y++;
	}
}

void	draw_wall_column(t_data *d, t_draw_params *p)
{
	t_wall_vars	wv;

	wv.tex = select_texture(d, p->r);
	wv.use_texture = (wv.tex && wv.tex->init && wv.tex->addr
			&& wv.tex->width > 0 && wv.tex->height > 0);
	wv.wall_x = calc_wall_x(d, p->r, p->perp_wall_dist);
	wv.tex_x = 0;
	if (wv.use_texture)
		wv.tex_x = calc_tex_x(wv.tex, p->r, wv.wall_x);
	draw_wall_pixels(d, p, &wv);
}

void	draw_vertical_textured(t_data *d, t_draw_params *p)
{
	draw_ceiling(d, p->x, p->draw_start);
	draw_wall_column(d, p);
	draw_floor(d, p->x, p->draw_end + 1);
}
