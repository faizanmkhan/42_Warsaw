/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:33:44 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:30:56 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

static int	return_error(char *msg, char *base_dir)
{
	ft_putstr_fd(msg, 2);
	free(base_dir);
	return (-1);
}

static int	return_error_buf(char *msg, t_pctx *c)
{
	free_lines(c->buf, c->cnt);
	return (return_error(msg, c->base_dir));
}

static int	min_parse_prepare(t_data *data, t_pctx *c, const char *path)
{
	pctx_init(c);
	if (pctx_open_and_collect(c, path) != 0)
	{
		perror("open");
		return (-1);
	}
	close(c->fd);
	if (c->cnt == 0)
		return (return_error("Error: no map found\n", c->base_dir));
	if (allocate_map(data, c->cnt, pctx_max_width(c)) != 0)
		return (return_error_buf("Error: alloc failed\n", c));
	if (fill_map(data, c->buf, c->cnt, pctx_max_width(c)) != 0)
		return (return_error_buf("Error: no player start (N/S/E/W)\n", c));
	free_lines(c->buf, c->cnt);
	return (0);
}

int	min_parse_map(t_data *data, const char *path)
{
	t_pctx	c;
	int		ox;
	int		oy;

	ox = -1;
	oy = -1;
	if (min_parse_prepare(data, &c, path) != 0)
		return (-1);
	finalize_textures_and_colors(data, &c);
	free(c.base_dir);
	if (flood_fill_check(data, &ox, &oy) == 1)
	{
		print_map_open_region(data, ox, oy);
		return (-1);
	}
	return (0);
}
