/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:16:32 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/22 22:39:41 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*start;

	start = malloc(sizeof(t_fractal));
	if (!start)
		error_occured();
	start->head = malloc(sizeof(t_mlx_data));
	if (!start->head)
		error_occured();
	start->head->ptr = NULL;
	start->image = malloc(sizeof(t_img_data));
	if (!start->image)
		error_occured();
	start->image->img = NULL;
	start->win_h = 400;
	start->win_w = 400;
	start->f_vision = 0.1;
	if (argc < 2 || argc > 4 || check_fractal_input(start, argv, argc) != 1)
	{
		instruction_set();
		error_free(start);
	}
	else
		initialize_fractal(start);
	return (0);
}

int	check_fractal_input(t_fractal *start, char **argv, int argc)
{
	if (!ft_strcmp("mandelbrot", argv[1]))
		start->name = 1;
	else if (!ft_strcmp("julia", argv[1]))
	{
		start->name = 2;
		set_julia_c_coordinate(argc, argv, start);
	}
	else if (!ft_strcmp("triangle", argv[1]))
		start->name = 3;
	else
		return (0);
	initialize_fractal_setting(start);
	return (1);
}

void	initialize_fractal_setting(t_fractal *ptr)
{
	if (ptr->name == 1)
		set_mandelbrot(ptr);
	else if (ptr->name == 2)
		set_julia(ptr);
	else if (ptr->name == 3)
		set_triangle(ptr);
}
