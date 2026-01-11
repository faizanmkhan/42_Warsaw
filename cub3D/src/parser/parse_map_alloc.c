/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:44:26 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:36:26 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

static int	is_player_char(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_player(t_data *data, int i, int j, char c)
{
	data->player.x = i + 0.5;
	data->player.y = j + 0.5;
	set_dir_plane(data, c);
}

int	fill_row(t_data *data, char *rowbuf, int i, int maxw)
{
	int		j;
	int		found;
	char	c;

	j = 0;
	found = 0;
	while (j < maxw)
	{
		if (j < (int)ft_strlen(rowbuf))
			c = rowbuf[j];
		else
			c = '1';
		if (is_player_char(c))
		{
			set_player(data, i, j, c);
			found = 1;
			c = '0';
		}
		if (c != '1')
			c = '0';
		data->map[i][j++] = c;
	}
	data->map[i][data->cols] = '\0';
	return (found);
}

int	allocate_map(t_data *data, int rows, int cols)
{
	int	i;
	int	j;

	data->rows = rows;
	data->cols = cols;
	data->map = malloc(sizeof(char *) * (data->rows + 1));
	if (!data->map)
		return (-1);
	i = -1;
	while (++i < rows)
	{
		data->map[i] = malloc(data->cols + 1);
		if (!data->map[i])
		{
			j = -1;
			while (++j < i)
				free(data->map[j]);
			free(data->map);
			return (-1);
		}
	}
	data->map[data->rows] = NULL;
	return (0);
}

int	fill_map(t_data *data, char **buf, int cnt, int maxw)
{
	int	i;
	int	player_found;
	int	found;

	i = 0;
	player_found = 0;
	while (i < cnt)
	{
		found = fill_row(data, buf[i], i, maxw);
		if (found)
			player_found = 1;
		i++;
	}
	if (player_found)
		return (0);
	return (-1);
}
