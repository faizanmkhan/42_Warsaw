/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:54:20 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:34:02 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

char	*resolve_path(const char *base_dir, const char *p)
{
	char	*out;
	char	*tmp;

	if (!p)
		return (NULL);
	if (p[0] == '/')
		return (ft_strdup(p));
	if (!base_dir)
		return (ft_strdup(p));
	tmp = ft_strjoin(base_dir, "/");
	out = ft_strjoin(tmp, p);
	free(tmp);
	return (out);
}

static int	texture_error(char *msg, char *full)
{
	ft_putstr_fd(msg, 2);
	free(full);
	return (-1);
}

static void	set_texture(struct s_tex *tex, void *img, int w, int h)
{
	tex->img = img;
	tex->addr = mlx_get_data_addr(img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	tex->width = w;
	tex->height = h;
	tex->init = 1;
}

int	load_texture_from_path(t_data *data, struct s_tex *tex,
		const char *p, const char *base_dir)
{
	char	*full;
	int		w;
	int		h;
	void	*img;

	if (!p)
		return (0);
	full = resolve_path(base_dir, p);
	if (!full)
		return (-1);
	w = 0;
	h = 0;
	img = mlx_xpm_file_to_image(data->mlx_ptr, full, &w, &h);
	if (!img)
		return (texture_error("Error: failed to load texture\n", full));
	set_texture(tex, img, w, h);
	free(full);
	return (0);
}

int	finalize_textures_and_colors(t_data *data, t_pctx *c)
{
	if (c->hdr.floor >= 0)
		data->floor_color = c->hdr.floor;
	if (c->hdr.ceiling >= 0)
		data->ceiling_color = c->hdr.ceiling;
	if (c->hdr.no)
		load_texture_from_path(data, &data->no, c->hdr.no, c->base_dir);
	if (c->hdr.so)
		load_texture_from_path(data, &data->so, c->hdr.so, c->base_dir);
	if (c->hdr.we)
		load_texture_from_path(data, &data->we, c->hdr.we, c->base_dir);
	if (c->hdr.ea)
		load_texture_from_path(data, &data->ea, c->hdr.ea, c->base_dir);
	free(c->hdr.no);
	free(c->hdr.so);
	free(c->hdr.we);
	free(c->hdr.ea);
	return (0);
}
