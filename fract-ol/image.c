/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:47:24 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/22 22:31:28 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_fractal *ptr, int x, int y, int colour)
{
	char	*pixel;

	if (x >= 0 && x < ptr->win_w && y >= 0 && y < ptr->win_h)
	{
		pixel = ptr->image->addrs + (y * ptr->image->scr_len
				+ x * (ptr->image->bpp / 8));
		*(unsigned int *)pixel = colour;
	}
}

int	render_window_image(t_fractal *ptr)
{
	if (ptr->image->img)
		mlx_destroy_image(ptr->head->ptr, ptr->image->img);
	ptr->image->img = mlx_new_image(ptr->head->ptr, ptr->win_w, ptr->win_h);
	if (!(ptr->image->img))
		error_occured();
	ptr->image->addrs = mlx_get_data_addr(ptr->image->img, &ptr->image->bpp,
			&ptr->image->scr_len, &ptr->image->endian);
	if (!(ptr->image->addrs))
		error_occured();
	launch_fractal(ptr);
	mlx_put_image_to_window(ptr->head->ptr, ptr->head->win,
		ptr->image->img, 0, 0);
	return (0);
}

void	launch_fractal(t_fractal *ptr)
{
	if (ptr->name == 1)
		launch_mandelbrot(ptr);
	else if (ptr->name == 2)
		launch_julia(ptr);
	else if (ptr->name == 3)
		launch_triangle(ptr);
	else
	{
		error_occured();
		error_free(ptr);
	}
}
