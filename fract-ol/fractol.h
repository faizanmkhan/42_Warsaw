/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 13:39:11 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/23 21:00:49 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include "mlx.h"

typedef struct s_img_data
{
	void	*img;
	char	*addrs;
	int		scr_len;
	int		bpp;
	int		endian;
}	t_img_data;

typedef struct s_mlx_data
{
	void	*ptr;
	void	*win;
}	t_mlx_data;

typedef struct s_fractal
{
	int			name;
	int			win_h;
	int			win_w;
	int			colour;
	int			p_x;
	int			p_y;
	int			img_x;
	int			img_y;
	int			max_iteration;
	float		f_vision;
	double		iteration;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
	double		ppu_x;
	double		ppu_y;
	double		z_real;
	double		z_im;
	double		c_real;
	double		c_im;
	double		temp;
	t_img_data	*image;
	t_mlx_data	*head;
}	t_fractal;

void	error_free(t_fractal *ptr);
void	error_occured(void);
void	ft_putstr(char *s);
void	instruction_set(void);
void	my_mlx_pixel_put(t_fractal *ptr, int x, int y, int colour);
void	initialize_fractal_setting(t_fractal *ptr);
void	set_mandelbrot(t_fractal *ptr);
void	reset_mandel(t_fractal *ptr);
void	launch_mandelbrot(t_fractal *ptr);
void	set_julia_c_coordinate(int argc, char **argv, t_fractal *ptr);
void	launch_julia(t_fractal *ptr);
void	reset_julia(t_fractal *ptr);
void	set_julia(t_fractal *ptr);
void	launch_fractal(t_fractal *ptr);
void	destroy_fractal(t_fractal *ptr);
void	set_triangle(t_fractal *ptr);
void	reset_triangle(t_fractal *ptr);
void	launch_triangle(t_fractal *ptr);
int		ft_strcmp(char *s1, char *s2);
int		initialize_fractal(t_fractal *ptr);
int		check_fractal_input(t_fractal *start, char **argv, int argc);
int		render_window_image(t_fractal *ptr);
int		initialize_fractal(t_fractal *ptr);
int		initialize_mlx(t_fractal *ptr);
int		zoom_hook(int button, int x, int y, t_fractal *ptr);
int		key_hook(int keycode, t_fractal *ptr);
int		close_window(t_fractal *ptr);
double	fo_atof(const char *s);

#endif