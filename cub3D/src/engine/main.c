/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:41:16 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/04 23:09:21 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	close_game(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: cub3D <map.cub>\n", 2);
		return (1);
	}
	if (min_init(&data) != 0)
		return (1);
	if (min_parse_map(&data, argv[1]) != 0)
	{
		ft_putstr_fd("Error: failed to parse map\n", 2);
		return (1);
	}
	mlx_hook(data.win_ptr, 2, 1L << 0, &min_keypress, &data);
	mlx_hook(data.win_ptr, 17, 0, &close_game, &data);
	mlx_loop_hook(data.mlx_ptr, min_render, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
