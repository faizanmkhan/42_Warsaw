/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:51:55 by faikhan           #+#    #+#             */
/*   Updated: 2025/11/30 20:09:56 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

char	*trim_leading(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

void	free_lines(char **lines, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

int	is_map_line(const char *s)
{
	int		has_one;
	char	c;

	has_one = 0;
	while (*s)
	{
		c = *s;
		if (c == '1')
			has_one = 1;
		if (c == '1' || c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W'
			|| c == 'D' || c == 'A' || c == ' ')
		{
		}
		else
			return (0);
		s++;
	}
	return (has_one);
}

void	free_parts(char **parts)
{
	int	i;

	i = 0;
	if (!parts)
		return ;
	while (parts[i])
	{
		free(parts[i]);
		i++;
	}
	free(parts);
}

int	handle_header_line(char *trim, t_hdr *h)
{
	if (handle_texture_line(trim, h))
		return (1);
	if (handle_color_line(trim, h))
		return (1);
	return (0);
}
