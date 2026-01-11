/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_alloc_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 17:19:00 by faikhan           #+#    #+#             */
/*   Updated: 2025/11/30 19:16:53 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

static void	set_dir_n(t_data *data)
{
	data->dir.x = -1.0;
	data->dir.y = 0.0;
	data->plane.x = 0.0;
	data->plane.y = 0.66;
}

static void	set_dir_s(t_data *data)
{
	data->dir.x = 1.0;
	data->dir.y = 0.0;
	data->plane.x = 0.0;
	data->plane.y = -0.66;
}

static void	set_dir_e(t_data *data)
{
	data->dir.x = 0.0;
	data->dir.y = 1.0;
	data->plane.x = 0.66;
	data->plane.y = 0.0;
}

static void	set_dir_w(t_data *data)
{
	data->dir.x = 0.0;
	data->dir.y = -1.0;
	data->plane.x = -0.66;
	data->plane.y = 0.0;
}

void	set_dir_plane(t_data *data, char c)
{
	if (c == 'N')
	{
		set_dir_n(data);
		return ;
	}
	if (c == 'S')
	{
		set_dir_s(data);
		return ;
	}
	if (c == 'E')
	{
		set_dir_e(data);
		return ;
	}
	if (c == 'W')
		set_dir_w(data);
}
