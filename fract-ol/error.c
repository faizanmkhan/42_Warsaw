/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 18:24:00 by faikhan           #+#    #+#             */
/*   Updated: 2025/01/22 22:33:22 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	error_free(t_fractal *ptr)
{
	if (ptr->image)
		free(ptr->image);
	if (ptr->head)
		free(ptr->head);
	if (ptr)
		free(ptr);
	exit(1);
}

void	error_occured(void)
{
	ft_putstr("Fatal error can't recover\n");
}

void	instruction_set(void)
{
	ft_putstr("Wrong input, try \"./fract-ol mandelbrot\"\n");
	ft_putstr("Or, try \"./fract-ol julia -0.75 0.125\"\n");
	ft_putstr("Or, try \"./fract-ol triangle\"\n");
}

void	destroy_fractal(t_fractal *ptr)
{
	mlx_destroy_image(ptr->head->ptr, ptr->image->img);
	mlx_destroy_window(ptr->head->ptr, ptr->head->win);
	mlx_destroy_display(ptr->head->ptr);
	free(ptr->image);
	free(ptr->head->ptr);
	free(ptr->head);
	free(ptr);
}

int	close_window(t_fractal *ptr)
{
	destroy_fractal(ptr);
	exit(0);
}
