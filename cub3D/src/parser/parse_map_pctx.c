/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_pctx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:52:34 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/03 19:04:02 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parse_map.h"

static int	pctx_pre_map_handle(t_pctx *c, char *trim, char *line)
{
	if (handle_header_line(trim, &c->hdr))
	{
		free(line);
		return (1);
	}
	if (is_map_line(trim))
	{
		c->in_map = 1;
		return (2);
	}
	free(line);
	return (1);
}

static int	pctx_error(char *line, int n)
{
	free(line);
	return (n);
}

static int	pctx_process_line(t_pctx *c, char *line)
{
	int		llen;
	char	*trim;
	int		pr;

	llen = (int)ft_strlen(line);
	if (llen > 0 && line[llen - 1] == '\n')
		line[llen - 1] = '\0';
	trim = trim_leading(line);
	if (!c->in_map)
	{
		pr = pctx_pre_map_handle(c, trim, line);
		if (pr == 1)
			return (0);
	}
	if (c->in_map && (*trim == '\0'))
		pctx_error(line, 1);
	if (append_buf(&c->buf, &c->cap, &c->cnt, trim) < 0)
		pctx_error(line, -1);
	free(line);
	return (0);
}

int	pctx_collect_lines(t_pctx *c)
{
	char	*line;
	int		r;

	while (1)
	{
		line = get_next_line(c->fd);
		if (line == NULL)
			break ;
		r = pctx_process_line(c, line);
		if (r < 0)
			return (-1);
		if (r > 0)
			break ;
	}
	return (0);
}

int	pctx_open_and_collect(t_pctx *c, const char *path)
{
	if (pctx_open(path, c) != 0)
		return (-1);
	if (pctx_collect_lines(c) != 0)
	{
		close(c->fd);
		free_lines(c->buf, c->cnt);
		free(c->base_dir);
		return (-1);
	}
	return (0);
}
