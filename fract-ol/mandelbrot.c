/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:44:58 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/22 22:40:03 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_mandelbrot(t_fractal *ptr)
{
	ptr->iteration = 0;
	ptr->x_min = -2;
	ptr->x_max = 2;
	ptr->y_min = -2;
	ptr->y_max = 2;
	ptr->z_real = 0;
	ptr->z_im = 0;
	ptr->ppu_x = 100;
	ptr->ppu_y = 100;
	ptr->c_real = ptr->p_x / ptr->ppu_x + ptr->x_min;
	ptr->c_im = ptr->p_y / ptr->ppu_y + ptr->y_max;
	ptr->img_x = ptr->win_w;
	ptr->img_y = ptr->win_h;
	ptr->max_iteration = 200;
	ptr->colour = 0x4670b9;
}

void	reset_mandel(t_fractal *ptr)
{
	ptr->iteration = 0;
	ptr->c_real = ptr->p_x / ptr->ppu_x + ptr->x_min;
	ptr->c_im = ptr->p_y / ptr->ppu_y + ptr->y_min;
	ptr->z_real = 0;
	ptr->z_im = 0;
}

void	launch_mandelbrot(t_fractal *ptr)
{
	ptr->p_x = 0;
	while (ptr->p_x < ptr->img_x)
	{
		ptr->p_y = 0;
		while (ptr->p_y < ptr->img_y)
		{
			reset_mandel(ptr);
			while ((ptr->z_real * ptr->z_real) + (ptr->z_im * ptr->z_im) < 4
				&& ptr->iteration < ptr->max_iteration)
			{
				ptr->temp = ptr->z_real;
				ptr->z_real = ptr->z_real * ptr->z_real - ptr->z_im * ptr->z_im
					+ ptr->c_real;
				ptr->z_im = 2 * ptr->temp * ptr->z_im + ptr->c_im;
				ptr->iteration++;
			}
			my_mlx_pixel_put(ptr, ptr->p_x, ptr->p_y,
				ptr->iteration * ptr->colour / ptr->max_iteration);
			ptr->p_y++;
		}
		ptr->p_x++;
	}
}
