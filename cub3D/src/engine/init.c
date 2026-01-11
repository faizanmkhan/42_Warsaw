/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:36:18 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/04 23:08:32 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	init_screen(t_data *data)
{
	data->screen_x = 640;
	data->screen_y = 480;
	return (0);
}

int	init_mlx(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		ft_putstr_fd("Error: mlx_init failed\n", 2);
		return (1);
	}
	return (0);
}

int	init_window(t_data *data)
{
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->screen_x,
			data->screen_y, "minimal_cub3d");
	if (!data->win_ptr)
	{
		ft_putstr_fd("Error: window creation failed\n", 2);
		return (1);
	}
	return (0);
}

int	init_image(t_data *data)
{
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->screen_x,
			data->screen_y);
	if (!data->img_ptr)
	{
		ft_putstr_fd("Error: image creation failed\n", 2);
		return (1);
	}
	return (0);
}

int	min_init(t_data *data)
{
	if (init_screen(data) != 0)
		return (1);
	if (init_mlx(data) != 0)
		return (1);
	if (init_window(data) != 0)
		return (1);
	if (init_image(data) != 0)
		return (1);
	init_map_placeholders(data);
	init_player(data);
	init_textures(data);
	init_colors(data);
	return (0);
}
