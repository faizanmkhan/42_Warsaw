/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:35:10 by faikhan           #+#    #+#             */
/*   Updated: 2025/11/30 19:17:44 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/renderer.h"

int	min_render(t_data *data)
{
	double	x;
	t_ray	r;
	double	camera_x;

	if (data->img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->screen_x,
			data->screen_y);
	if (!data->img_ptr)
		return (0);
	x = 0;
	while (x < data->screen_x)
	{
		camera_x = 2.0 * x / (double)data->screen_x - 1.0;
		init_ray(data, &r, camera_x);
		perform_dda(data, &r);
		compute_and_draw(data, &r, (int)x);
		x += 1.0;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
