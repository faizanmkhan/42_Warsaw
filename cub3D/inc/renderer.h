/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:34:14 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/04 23:08:32 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_H
# define RENDERER_H

# include "cub3d.h"

typedef struct s_ray
{
	double			raydir_x;
	double			raydir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				side;
}					t_ray;

typedef struct s_draw_params
{
	int				x;
	int				draw_start;
	int				draw_end;
	double			perp_wall_dist;
	int				line_height;
	t_ray			*r;
}					t_draw_params;

typedef struct s_wall_vars
{
	struct s_tex	*tex;
	int				use_texture;
	double			wall_x;
	int				tex_x;
}					t_wall_vars;

/* draw helpers (implemented in renderer_draw.c) */
struct s_tex		*select_texture(t_data *d, t_ray *r);
double				calc_wall_x(t_data *d, t_ray *r, double perp_wall_dist);
int					calc_tex_x(struct s_tex *tex, t_ray *r, double wall_x);
unsigned int		sample_tex(struct s_tex *tex, int tx, int ty, int side);
void				draw_vertical_textured(t_data *d, t_draw_params *p);
void				draw_wall_column(t_data *d, t_draw_params *p);
void				min_put_pixel(t_data *data, int x, int y, int color);
void				draw_wall_pixels(t_data *d, t_draw_params *p,
						t_wall_vars *wv);
void				draw_wall_pixel_no_tex(t_data *d, t_draw_params *p, int y);
void				draw_wall_pixel_tex(t_data *d, t_draw_params *p,
						t_wall_vars *wv, int y);
/* ray helpers (implemented in renderer_ray.c) */
void				init_ray(t_data *data, t_ray *r, double camera_x);
void				perform_dda(t_data *data, t_ray *r);
void				compute_and_draw(t_data *data, t_ray *r, int x);

/* public */
int					min_render(t_data *data);

#endif
