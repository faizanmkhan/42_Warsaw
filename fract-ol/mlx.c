/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 17:47:15 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/23 22:38:03 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	initialize_fractal(t_fractal *ptr)
{
	initialize_mlx(ptr);
	mlx_key_hook(ptr->head->win, key_hook, ptr);
	mlx_mouse_hook(ptr->head->win, zoom_hook, ptr);
	mlx_hook(ptr->head->win, 17, 0, close_window, ptr);
	mlx_loop(ptr->head->ptr);
	return (0);
}

int	initialize_mlx(t_fractal *ptr)
{
	ptr->head->ptr = mlx_init();
	if (!ptr->head->ptr)
		error_occured();
	ptr->head->win = mlx_new_window(ptr->head->ptr, ptr->win_w,
			ptr->win_h, "~* fract-ol *~");
	if (!ptr->head->win)
		error_occured();
	render_window_image(ptr);
	return (0);
}

int	zoom_hook(int button, int x, int y, t_fractal *ptr)
{
	double	temp_x;
	double	temp_y;

	temp_x = x / ptr->ppu_x + ptr->x_min;
	temp_y = y / ptr->ppu_y + ptr->y_min;
	if (button == 4)
	{
		ptr->ppu_x *= 1.1;
		ptr->ppu_y *= 1.1;
		ptr->f_vision /= 1.1;
	}
	if (button == 5)
	{
		ptr->ppu_x /= 1.1;
		ptr->ppu_y /= 1.1;
		ptr->f_vision *= 1.1;
	}
	ptr->x_min = temp_x - (x / ptr->ppu_x);
	ptr->y_min = temp_y - (y / ptr->ppu_x);
	render_window_image(ptr);
	return (0);
}

int	key_hook(int keycode, t_fractal *ptr)
{
	if (keycode == 65307)
		close_window(ptr);
	if (keycode == 99)
		ptr->colour = ptr->colour + 0xA020F6;
	if (keycode == 65362)
		ptr->y_min = ptr->y_min - ptr->f_vision;
	if (keycode == 65364)
		ptr->y_min = ptr->y_min + ptr->f_vision;
	if (keycode == 65361)
		ptr->x_min = ptr->x_min - ptr->f_vision;
	if (keycode == 65363)
		ptr->x_min = ptr->x_min + ptr->f_vision;
	render_window_image(ptr);
	return (0);
}
