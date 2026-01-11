/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_draw_helper2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:01:50 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:07:41 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/renderer.h"

void	draw_wall_pixel_no_tex(t_data *d, t_draw_params *p, int y)
{
	int	color;

	color = 0xAA0000;
	if (p->r->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	min_put_pixel(d, p->x, y, color);
}

void	draw_wall_pixel_tex(t_data *d, t_draw_params *p, t_wall_vars *wv,
		int y)
{
	int				dtex;
	int				tex_y;
	unsigned int	color;

	dtex = (y * 256 - d->screen_y * 128 + p->line_height * 128);
	tex_y = ((dtex * wv->tex->height) / p->line_height) / 256;
	if (tex_y < 0)
		tex_y = 0;
	if (tex_y >= wv->tex->height)
		tex_y = wv->tex->height - 1;
	color = sample_tex(wv->tex, wv->tex_x, tex_y, p->r->side);
	min_put_pixel(d, p->x, y, color);
}
