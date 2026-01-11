/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pctx_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 18:58:44 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 19:04:09 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

void	pctx_init(t_pctx *c)
{
	c->fd = -1;
	c->base_dir = NULL;
	c->buf = NULL;
	c->cap = 0;
	c->cnt = 0;
	c->in_map = 0;
	c->hdr.no = NULL;
	c->hdr.so = NULL;
	c->hdr.we = NULL;
	c->hdr.ea = NULL;
	c->hdr.floor = -1;
	c->hdr.ceiling = -1;
}

int	pctx_open(const char *path, t_pctx *c)
{
	const char	*p = ft_strrchr(path, '/');

	c->fd = open(path, O_RDONLY);
	if (c->fd < 0)
		return (-1);
	if (p)
		c->base_dir = ft_substr(path, 0, (unsigned int)(p - path));
	return (0);
}

int	pctx_max_width(t_pctx *c)
{
	int	maxw;
	int	i;
	int	l;

	maxw = 0;
	i = 0;
	while (i < c->cnt)
	{
		l = (int)ft_strlen(c->buf[i]);
		if (l > maxw)
			maxw = l;
		i++;
	}
	return (maxw);
}
