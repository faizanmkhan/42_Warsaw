/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:43:02 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/04 23:08:32 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	min_turn(t_data *data, double ang)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dir.x;
	oldplanex = data->plane.x;
	data->dir.x = data->dir.x * cos(ang) - data->dir.y * sin(ang);
	data->dir.y = olddirx * sin(ang) + data->dir.y * cos(ang);
	data->plane.x = data->plane.x * cos(ang) - data->plane.y * sin(ang);
	data->plane.y = oldplanex * sin(ang) + data->plane.y * cos(ang);
}

int	min_keypress(int keysym, t_data *data)
{
	fprintf(stderr, "[key] keysym=%d\n", keysym);
	if (keysym == 65307 || keysym == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		exit(0);
	}
	if (keysym == 119 || keysym == 87)
		min_move_forward(data);
	if (keysym == 115 || keysym == 83)
		min_move_back(data);
	if (keysym == 97 || keysym == 65)
		min_move_left(data);
	if (keysym == 100 || keysym == 68)
		min_move_right(data);
	if (keysym == 65361)
		min_turn(data, 0.05);
	if (keysym == 65363)
		min_turn(data, -0.05);
	return (0);
}
