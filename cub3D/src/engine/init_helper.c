/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 16:17:29 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/04 23:08:32 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_colors(t_data *data)
{
	data->ceiling_color = 0x87CEEB;
	data->floor_color = 0x707070;
}

void	min_setup_map(t_data *data)
{
	(void)data;
}

void	init_map_placeholders(t_data *data)
{
	data->map = NULL;
	data->rows = 0;
	data->cols = 0;
}

void	init_player(t_data *data)
{
	data->player.x = -1.0;
	data->player.y = -1.0;
	data->dir.x = -1.0;
	data->dir.y = 0.0;
	data->plane.x = 0.0;
	data->plane.y = 0.66;
	data->movespeed = 0.12;
}

void	init_textures(t_data *data)
{
	data->no.img = NULL;
	data->so.img = NULL;
	data->we.img = NULL;
	data->ea.img = NULL;
	data->no.addr = NULL;
	data->so.addr = NULL;
	data->we.addr = NULL;
	data->ea.addr = NULL;
	data->no.init = 0;
	data->so.init = 0;
	data->we.init = 0;
	data->ea.init = 0;
	data->no.width = 0;
	data->so.width = 0;
	data->we.width = 0;
	data->ea.width = 0;
	data->no.height = 0;
	data->so.height = 0;
	data->we.height = 0;
	data->ea.height = 0;
}
