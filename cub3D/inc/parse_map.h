/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:34:06 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/04 23:08:32 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_MAP_H
# define PARSE_MAP_H

# include "cub3d.h"

typedef struct s_hdr
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
}			t_hdr;

typedef struct s_pctx
{
	int		fd;
	char	*base_dir;
	char	**buf;
	int		cap;
	int		cnt;
	int		in_map;
	t_hdr	hdr;
}			t_pctx;

typedef struct s_vstack
{
	char	*visited;
	int		*stx;
	int		*sty;
}			t_vstack;

/* helpers */
char		*trim_leading(char *s);
void		free_lines(char **lines, int n);
int			is_map_line(const char *s);
int			handle_header_line(char *trim, t_hdr *h);
void		free_parts(char **parts);
int			append_buf(char ***bufp, int *cap, int *cnt, const char *s);

/* parse context */
void		pctx_init(t_pctx *c);
int			pctx_open_and_collect(t_pctx *c, const char *path);
int			pctx_open(const char *path, t_pctx *c);
int			pctx_max_width(t_pctx *c);

/* allocation / map fill */
int			allocate_map(t_data *data, int rows, int cols);
int			fill_map(t_data *data, char **buf, int cnt, int maxw);
int			fill_row(t_data *data, char *rowbuf, int i, int maxw);
void		set_dir_plane(t_data *data, char c);
int			allocate_vstack(t_data *data, t_vstack *s);

/* texture/color */
int			finalize_textures_and_colors(t_data *data, t_pctx *c);
int			append_buf(char ***bufp, int *cap, int *cnt, const char *s);
int			handle_texture_line(char *trim, t_hdr *h);
int			handle_color_line(char *trim, t_hdr *h);

/* flood/check */
int			flood_fill_check(t_data *data, int *ox, int *oy);
void		print_map_open_region(t_data *data, int ox, int oy);

/* main */
int			min_parse_map(t_data *data, const char *path);
#endif
