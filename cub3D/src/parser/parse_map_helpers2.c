/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_helpers2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:07:14 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 20:44:44 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

int	append_buf(char ***bufp, int *cap, int *cnt, const char *s)
{
	int		newcap;
	char	**tmp;

	if (*cnt + 1 > *cap)
	{
		if (*cap == 0)
			newcap = 16;
		else
			newcap = (*cap * 2);
		tmp = realloc(*bufp, sizeof(char *) * newcap);
		if (!tmp)
			return (-1);
		*bufp = tmp;
		*cap = newcap;
	}
	(*bufp)[(*cnt)++] = ft_strdup(s);
	return (0);
}

static int	valid_parts(char **p)
{
	return (p && p[0] && p[1] && p[2]);
}

static int	make_color(char **p)
{
	return ((ft_atoi(p[0]) << 16) | (ft_atoi(p[1]) << 8) | ft_atoi(p[2]));
}

int	handle_color_line(char *trim, t_hdr *h)
{
	char	**parts;

	if (trim[0] == 'F' && trim[1] == ' ')
	{
		parts = ft_split(trim + 2, ',');
		if (valid_parts(parts))
			h->floor = make_color(parts);
		free_parts(parts);
		return (1);
	}
	if (trim[0] == 'C' && trim[1] == ' ')
	{
		parts = ft_split(trim + 2, ',');
		if (valid_parts(parts))
			h->ceiling = make_color(parts);
		free_parts(parts);
		return (1);
	}
	return (0);
}

int	handle_texture_line(char *trim, t_hdr *h)
{
	if (ft_strncmp(trim, "NO ", 3) == 0)
	{
		free(h->no);
		h->no = ft_strdup(trim + 3);
		return (1);
	}
	if (ft_strncmp(trim, "SO ", 3) == 0)
	{
		free(h->so);
		h->so = ft_strdup(trim + 3);
		return (1);
	}
	if (ft_strncmp(trim, "WE ", 3) == 0)
	{
		free(h->we);
		h->we = ft_strdup(trim + 3);
		return (1);
	}
	if (ft_strncmp(trim, "EA ", 3) == 0)
	{
		free(h->ea);
		h->ea = ft_strdup(trim + 3);
		return (1);
	}
	return (0);
}
