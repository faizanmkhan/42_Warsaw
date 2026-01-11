/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:42:51 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/04 23:11:57 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft.h"
# include "../mlx/mlx.h"

typedef struct s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			screen_x;
	int			screen_y;

	/* simple map */
	char		**map;
	int			rows;
	int			cols;

	/* player */
	t_pos		player;
	t_pos		dir;
	t_pos		plane;
	double		movespeed;

	/* colors */
	int			floor_color;
	int			ceiling_color;
	/* textures */
	struct		s_tex
	{
		void	*img;
		char	*addr;
		int		bits_per_pixel;
		int		line_length;
		int		endian;
		int		width;
		int		height;
		int		init;
	} no, so, we, ea;
}				t_data;

/* main */
int				minimal_main(void);

/* init */
int				min_init(t_data *data);
int				init_screen(t_data *data);
int				init_mlx(t_data *data);
int				init_window(t_data *data);
int				init_image(t_data *data);
void			init_map_placeholders(t_data *data);
void			init_player(t_data *data);
void			init_textures(t_data *data);
void			init_colors(t_data *data);
void			min_setup_map(t_data *data);
int				min_parse_map(t_data *data, const char *path);

/* render */
int				min_render(t_data *data);
void			min_put_pixel(t_data *data, int x, int y, int color);

/* input */
int				min_keypress(int keysym, t_data *data);
void			min_move_forward(t_data *data);
void			min_move_back(t_data *data);
void			min_move_left(t_data *data);
void			min_move_right(t_data *data);
void			min_turn(t_data *data, double ang);

#endif
